#include <iostream>
#include <fstream>
#include <sys/uio.h>
#include <stdio.h>
#include <string.h>
#include <sys/ptrace.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <elf.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <iomanip>

bool find_elf_addr(pid_t pid, const char* elfname, const char *perms_prot_flags, unsigned long &start, unsigned long &end)
{
	FILE* fp;
	char maps[4096], mapbuf[4096], perms[32], libpath[4096];
	char* libname;
	unsigned long file_offset, inode, dev_major, dev_minor;
	sprintf(maps, "/proc/%d/maps", pid);
	fp = fopen(maps, "rb");
	if (!fp) {
		fprintf(stderr, "Failed to open %s: %s\n", maps, strerror(errno));
		return 0;
	}
	while (fgets(mapbuf, sizeof(mapbuf), fp)) {
		sscanf(mapbuf, "%lx-%lx %s %lx %lx:%lx %lu %s", &start, &end, perms, &file_offset, &dev_major, &dev_minor, &inode, libpath);
		libname = strrchr(libpath, '/');
		if (libname) {
			libname++;
		}
		else {
			continue;
		}
		if (!strncmp(perms, perms_prot_flags, 4) && strstr(libname, elfname)) {
			fclose(fp);
			return true;
		}
	}
	fclose(fp);
	return false;
}

int cross_proc_readv(pid_t pid, char *remoteaddr, char *localaddr, size_t len)
{
	struct iovec local[1] = {};
	struct iovec remote[1] = {};

	local[0].iov_base = localaddr;
	local[0].iov_len = len;

	remote[0].iov_base = remoteaddr;
	remote[0].iov_len = len;

	ssize_t nread = process_vm_readv(pid, local, 1, remote, 1, 0);

	if (nread != len) {
		return errno;
	}
	return 0;
}

int cross_proc_readmem(pid_t pid, char *remoteaddr, char *localaddr, size_t len)
{
  char file[PATH_MAX] = {0};
	sprintf(file, "/proc/%d/mem", pid);
	int fd = open(file, O_RDWR);
	if (fd < 0) {
		return errno;
	}
	int ret = pread(fd, localaddr, len, (off_t)remoteaddr);
	if (ret < 0) {
		return errno;
	}

	close(fd);
	return 0;
}

int cross_proc_readptrace(pid_t pid, char *remoteaddr, char *localaddr, size_t len)
{
	char *dest = localaddr;
	char *src = remoteaddr;
	long word;
	while (len >= sizeof(word)) {
		errno = 0;
		word = ptrace(PTRACE_PEEKTEXT, pid, src, 0);
		if (errno != 0) {
			return errno;
		}
		*(long *)dest = word;
		src += sizeof(word);
		dest += sizeof(word);
		len -= sizeof(word);
	}

	if (len > 0) {
		word = 0;
		char *data = (char *)&word;
		word = ptrace(PTRACE_PEEKTEXT, pid, src, 0);
		if (errno != 0) {
			return errno;
		}
		while (len--) {
			*(dest++) = *(src++);
		}
	}
	return 0;
}

int cross_proc_read(pid_t pid, char *remoteaddr, char *localaddr, size_t len)
{
	int ret = 0;
	ret = cross_proc_readv(pid, remoteaddr, localaddr, len);
	if (0 == ret) {
		return ret;
	}
	ret = cross_proc_readmem(pid, remoteaddr, localaddr, len);
	if (0 == ret) {
		return ret;
	}
	ret = cross_proc_readptrace(pid, remoteaddr, localaddr, len);
	if (0 == ret) {
		return ret;
	}
	fprintf(stderr, "%s %d cross read error %d\n", __FUNCTION__, __LINE__, ret);
	return ret;
}

void find_from_file() {
  const std::int32_t pid = 44146;

  const std::string &file_name = "./libtest.so";

  Elf64_Ehdr targetelf;
  memset(&targetelf, 0x0, sizeof(Elf64_Ehdr));
  
  FILE* file = fopen(file_name.c_str(), "rb");
  fread(&targetelf, sizeof(targetelf), 1, file);
  
  // std::uint64_t elfbeginvalue, elfendvalue;
  // find_elf_addr(249588, "main", "r--p", elfbeginvalue, elfendvalue);
  // cross_proc_read(249588, (char *)elfbeginvalue, (char *)&targetelf, sizeof(targetelf));
 
  std::cout << "elf header:" << std::endl;
  std::cout << "* e_ident: " << targetelf.e_ident <<  std::endl;
  std::cout << "* e_type: " << targetelf.e_type <<  std::endl;
  std::cout << "* e_machine: " << targetelf.e_machine <<  std::endl;
  std::cout << "* e_version: " << targetelf.e_version <<  std::endl;
  std::cout << "* e_entry: " << targetelf.e_entry <<  std::endl;
  std::cout << "* e_phoff: " << targetelf.e_phoff <<  std::endl;
  std::cout << "* e_shoff: " << targetelf.e_shoff <<  std::endl;
  std::cout << "* e_flags: " << targetelf.e_flags <<  std::endl;
  std::cout << "* e_ehsize: " << targetelf.e_ehsize <<  std::endl;
  std::cout << "* e_phentsize: " << targetelf.e_phentsize <<  std::endl;
  std::cout << "* e_phnum: " << targetelf.e_phnum <<  std::endl;
  std::cout << "* e_shentsize: " << targetelf.e_shentsize <<  std::endl;
  std::cout << "* e_shnum: " << targetelf.e_shnum <<  std::endl;
  std::cout << "* e_shstrndx: " << targetelf.e_shstrndx <<  std::endl;

  if (memcmp(targetelf.e_ident, ELFMAG, SELFMAG) == 0) {
    std::cout << "is elf file!" << std::endl;
  }
  
  std::int32_t fd = open(file_name.c_str(), O_RDONLY);
  
  struct stat st;
  fstat(fd, &st);
  
  char *elffileaddr = (char *)mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  
  Elf64_Shdr sections[targetelf.e_shnum];
  memcpy(&sections, elffileaddr + targetelf.e_shoff, sizeof(sections));
  
  Elf64_Shdr &shsection = sections[targetelf.e_shstrndx];
  
  char shsectionname[shsection.sh_size];
  memcpy(shsectionname, elffileaddr + shsection.sh_offset, sizeof(shsectionname));
  
  int pltindex = -1;
  int dynsymindex = -1;
  int dynstrindex = -1;
  int relapltindex = -1;
  for (int i = 0; i < targetelf.e_shnum; ++i) {
    Elf64_Shdr &s = sections[i];
    std::string name = &shsectionname[s.sh_name];
    
    std::cout << "section: " << name << std::endl;
    
    if (name == ".plt") {
      pltindex = i;
      continue;
    }
    if (name == ".dynsym") {
      dynsymindex = i;
      continue;
    }
    if (name == ".dynstr") {
      dynstrindex = i;
      continue;
    }
    if (name == ".rela.plt") {
      relapltindex = i;
      continue;
    }
  }
  
  Elf64_Shdr &pltsection = sections[pltindex];
  
  Elf64_Shdr &dynsymsection = sections[dynsymindex];
  Elf64_Sym sym[dynsymsection.sh_size / sizeof(Elf64_Sym)];
  memcpy(&sym, elffileaddr + dynsymsection.sh_offset, sizeof(sym));
  
  Elf64_Shdr &dynstrsection = sections[dynstrindex];
  // char dynstr[dynstrsection.sh_size];
  std::string dynstr;
  dynstr.resize(dynstrsection.sh_size);
  memcpy(const_cast<char *>(dynstr.c_str()), elffileaddr + dynstrsection.sh_offset, dynstrsection.sh_size);
  
  int symfuncindex = -1;
  for (int i = 0; i < (int)(dynsymsection.sh_size / sizeof(Elf64_Sym)); ++i) {
    Elf64_Sym &s = sym[i];
    std::string name = &dynstr[s.st_name];
    
    std::cout << "===> " << name << ":" << std::endl;
  
    std::cout << "* st_name: " << s.st_name << std::endl;
    std::cout << "* st_shndx: " << s.st_shndx << std::endl;
    std::cout << "* st_other: " << s.st_other << std::endl;
    std::cout << "* st_info: " << s.st_info << std::endl;
    std::cout << "* st_size: " << s.st_size << std::endl;
    std::cout << "* st_value: " << s.st_value << std::endl;

    if (symfuncindex < 0 && name == "g_foo") {
      symfuncindex = i;
    }
  }

  Elf64_Sym &targetsym = sym[symfuncindex];

	Elf64_Shdr &relapltsection = sections[relapltindex];

	Elf64_Rela rela[relapltsection.sh_size / sizeof(Elf64_Rela)];

	memcpy(&rela, elffileaddr + relapltsection.sh_offset, sizeof(rela));

	int relafuncindex = -1;
	for (int i = 0; i < (int)(relapltsection.sh_size / sizeof(Elf64_Rela)); ++i)
	{
		Elf64_Rela &r = rela[i];
		if ((int)ELF64_R_SYM(r.r_info) == symfuncindex)
		{
			relafuncindex = i;
			break;
		}
	}

	Elf64_Rela &relafunc = rela[relafuncindex];

	void *func;
	cross_proc_read(pid, (char *)(relafunc.r_offset), (char *)&func, sizeof(func));

	auto funcaddr_plt = (void *)(uint64_t)relafunc.r_offset;
	auto funcaddr = func;

	munmap(elffileaddr, st.st_size);
}
void find_from_file_test() {
  const std::string &file_name = "./libtest.so";

  Elf64_Ehdr targetelf;
  memset(&targetelf, 0x0, sizeof(Elf64_Ehdr));
  
  FILE* file = fopen(file_name.c_str(), "rb");
  fread(&targetelf, sizeof(targetelf), 1, file);
 
  std::cout << "elf header:" << std::endl;
  std::cout << "* e_ident: " << targetelf.e_ident <<  std::endl;
  std::cout << "* e_type: " << targetelf.e_type <<  std::endl;
  std::cout << "* e_machine: " << targetelf.e_machine <<  std::endl;
  std::cout << "* e_version: " << targetelf.e_version <<  std::endl;
  std::cout << "* e_entry: " << targetelf.e_entry <<  std::endl;
  std::cout << "* e_phoff: " << targetelf.e_phoff <<  std::endl;
  std::cout << "* e_shoff: " << targetelf.e_shoff <<  std::endl;
  std::cout << "* e_flags: " << targetelf.e_flags <<  std::endl;
  std::cout << "* e_ehsize: " << targetelf.e_ehsize <<  std::endl;
  std::cout << "* e_phentsize: " << targetelf.e_phentsize <<  std::endl;
  std::cout << "* e_phnum: " << targetelf.e_phnum <<  std::endl;
  std::cout << "* e_shentsize: " << targetelf.e_shentsize <<  std::endl;
  std::cout << "* e_shnum: " << targetelf.e_shnum <<  std::endl;
  std::cout << "* e_shstrndx: " << targetelf.e_shstrndx <<  std::endl;

  if (memcmp(targetelf.e_ident, ELFMAG, SELFMAG) == 0) {
    std::cout << "is elf file!" << std::endl;
  }
  
  std::int32_t fd = open(file_name.c_str(), O_RDONLY);
  
  struct stat st;
  fstat(fd, &st);
  
  std::byte *elffileaddr = (std::byte *)mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  
  // Elf64_Shdr sections[targetelf.e_shnum];
  // memcpy(&sections, elffileaddr + targetelf.e_shoff, sizeof(sections));
  
  std::byte bytes[st.st_size];
  memset(bytes, 0x0, sizeof(bytes));
  memcpy(bytes, elffileaddr, sizeof(bytes));

  std::fstream f;
	f.open("data_file.txt", std::ios::out);

  for (size_t i = 0; i < sizeof(bytes); i++) {
    f << std::setw(2) << std::setfill('0') << std::hex << (int)(bytes[i]);
  }
  f << std::endl;

  std::byte bytes2[st.st_size];
  memset(bytes2, 0x0, sizeof(bytes2));
  memcpy(bytes2, elffileaddr + targetelf.e_shoff, sizeof(bytes));

  std::fstream f2;
	f2.open("data_file2.txt", std::ios::out);

  for (size_t i = 0; i < sizeof(bytes2); i++) {
    f2 << std::setw(2) << std::setfill('0') << std::hex << (int)(bytes2[i]);
  }
  f2 << std::endl;

  f.close();
  f2.close();
}


void find_from_so() {
  std::int32_t pid = 237898;

	unsigned long startaddr;
	unsigned long endaddr;

  find_elf_addr(pid, "libtest.so", "r--p", startaddr, endaddr);
  
  char *startaddr_p = (char *)startaddr;
  char *endaddr_p = (char *)endaddr;

  Elf64_Ehdr targetso;
  cross_proc_read(pid, startaddr_p, (char *)&targetso, sizeof(targetso));
  std::cout << "elf header:" << std::endl;
  std::cout << "* e_ident: " << targetso.e_ident <<  std::endl;
  std::cout << "* e_type: " << targetso.e_type <<  std::endl;
  std::cout << "* e_machine: " << targetso.e_machine <<  std::endl;
  std::cout << "* e_version: " << targetso.e_version <<  std::endl;
  std::cout << "* e_entry: " << targetso.e_entry <<  std::endl;
  std::cout << "* e_phoff: " << targetso.e_phoff <<  std::endl;
  std::cout << "* e_shoff: " << targetso.e_shoff <<  std::endl;
  std::cout << "* e_flags: " << targetso.e_flags <<  std::endl;
  std::cout << "* e_ehsize: " << targetso.e_ehsize <<  std::endl;
  std::cout << "* e_phentsize: " << targetso.e_phentsize <<  std::endl;
  std::cout << "* e_phnum: " << targetso.e_phnum <<  std::endl;
  std::cout << "* e_shentsize: " << targetso.e_shentsize <<  std::endl;
  std::cout << "* e_shnum: " << targetso.e_shnum <<  std::endl;
  std::cout << "* e_shstrndx: " << targetso.e_shstrndx <<  std::endl;

  Elf64_Shdr sections[targetso.e_shnum];
  cross_proc_read(pid, startaddr_p + targetso.e_shoff, (char *)&sections, sizeof(sections));

	Elf64_Shdr &shsection = sections[targetso.e_shstrndx];
	char shsectionname[shsection.sh_size];
	cross_proc_read(pid, startaddr_p + shsection.sh_offset, shsectionname, sizeof(shsectionname));
  
  int pltindex = -1;
  int dynsymindex = -1;
  int dynstrindex = -1;
  int relapltindex = -1;
  for (int i = 0; i < targetso.e_shnum; ++i) {
    Elf64_Shdr &s = sections[i];
    std::string name = &shsectionname[s.sh_name];
    
    std::cout << "section: " << name << std::endl;
    
    if (name == ".plt") {
      pltindex = i;
      continue;
    }
    if (name == ".dynsym") {
      dynsymindex = i;
      continue;
    }
    if (name == ".dynstr") {
      dynstrindex = i;
      continue;
    }
    if (name == ".rela.plt") {
      relapltindex = i;
      continue;
    }
  }
  
  Elf64_Shdr &pltsection = sections[pltindex];
  
  Elf64_Shdr &dynsymsection = sections[dynsymindex];

  Elf64_Sym sym[dynsymsection.sh_size / sizeof(Elf64_Sym)];
  cross_proc_read(pid, startaddr_p + dynsymsection.sh_offset, (char *)&sym, sizeof(sym));
  
  Elf64_Shdr &dynstrsection = sections[dynstrindex];

  std::string dynstr;
  dynstr.resize(dynstrsection.sh_size);
  cross_proc_read(pid, startaddr_p + dynstrsection.sh_offset, const_cast<char *>(dynstr.c_str()), dynstrsection.sh_size);
  
  int symfuncindex = -1;
  for (int i = 0; i < (int)(dynsymsection.sh_size / sizeof(Elf64_Sym)); ++i) {
    Elf64_Sym &s = sym[i];
    std::string name = &dynstr[s.st_name];
    
    std::cout << "===> " << name << ":" << std::endl;
  
    std::cout << "* st_name: " << s.st_name << std::endl;
    std::cout << "* st_shndx: " << s.st_shndx << std::endl;
    std::cout << "* st_other: " << s.st_other << std::endl;
    std::cout << "* st_info: " << s.st_info << std::endl;
    std::cout << "* st_size: " << s.st_size << std::endl;
    std::cout << "* st_value: " << s.st_value << std::endl;

    if (symfuncindex < 0 && name == "g_foo") {
      symfuncindex = i;
    }
  }

  Elf64_Sym &targetsym = sym[symfuncindex];
  if (targetsym.st_shndx != SHN_UNDEF && targetsym.st_value != 0 && targetsym.st_size != 0) {
    Elf64_Shdr &s = sections[targetsym.st_shndx];
    std::string name = &shsectionname[s.sh_name];
    if (name == ".text") {
      std::cout << "hello,world!" << std::endl;
    }
    else {
   	  std::cout << "ops!" << std::endl; 
    }
  }
}
void find_from_so_test() {
  std::int32_t pid = 44146;

	unsigned long startaddr;
	unsigned long endaddr;

  find_elf_addr(pid, "libtest.so", "r--p", startaddr, endaddr);
  
  char *startaddr_p = (char *)startaddr;
  char *endaddr_p = (char *)endaddr;

  Elf64_Ehdr targetso;
  cross_proc_read(pid, startaddr_p, (char *)&targetso, sizeof(targetso));
 
  Elf64_Phdr phdrs[targetso.e_phnum];
  cross_proc_read(pid, (char *)(startaddr + targetso.e_phoff), (char *)phdrs, sizeof(Elf64_Phdr) * targetso.e_phnum);

  Elf64_Phdr dy_phdr;
  memset(&dy_phdr, 0x0, sizeof(Elf64_Phdr));
  for (int i = 0; i < targetso.e_phnum; ++i) {
    if (phdrs[i].p_type == PT_DYNAMIC) {
      dy_phdr = phdrs[i];
    }
  }

  Elf64_Addr dynsym_addr, dynstr_addr;  
  for (size_t i = 0; i < dy_phdr.p_memsz / sizeof(Elf64_Dyn); ++i) {
    Elf64_Dyn dyn_entry;
    cross_proc_read(pid, (char *)(startaddr + dy_phdr.p_vaddr + i * sizeof(Elf64_Dyn)), (char *)&dyn_entry, sizeof(dyn_entry));
    
    if (dyn_entry.d_tag == DT_SYMTAB) {
      dynsym_addr = dyn_entry.d_un.d_ptr;
    } else if (dyn_entry.d_tag == DT_STRTAB) {
      dynstr_addr = dyn_entry.d_un.d_ptr;
    } else if (dyn_entry.d_tag == DT_NULL) {
      break; // Reached the end of the dynamic array
    }
  }

  Elf64_Sym sym_entry;
  for (size_t i = 0; i < 20; ++i) {
    cross_proc_read(pid, (char *)(dynsym_addr + i * sizeof(Elf64_Sym)), (char *)&sym_entry, sizeof(sym_entry));
   
    // 读取符号名
    char symbol_name[256]; // 假定符号名不会超过这个长度
    cross_proc_read(pid, (char *)(dynstr_addr + sym_entry.st_name), symbol_name, sizeof(symbol_name));
    
    std::cout << symbol_name << std::endl;
  }

 //  std::byte bytes[50000];
 //  memset(bytes, 0x0, sizeof(bytes));
 //  cross_proc_read(pid, startaddr_p, (char *)bytes, sizeof(bytes));
	//
 //  std::fstream f;
	// f.open("data_so.txt", std::ios::out);
	//
 //  for (size_t i = 0; i < sizeof(bytes); i++) {
 //    f << std::setw(2) << std::setfill('0') << std::hex << (int)(bytes[i]);
 //  }
 //  f << std::endl;
	//
 //  f.close();
}

int main (int argc, char *argv[]) {
  find_from_file();
  // find_from_so();

  // find_from_file_test();
  // find_from_so_test();

  return 0;
}
