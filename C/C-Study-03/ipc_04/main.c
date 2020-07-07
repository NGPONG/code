#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

void foo_01(void) {
  int fd = open("./test", O_RDWR);
  if (fd < 0) {
    perror("open file error");
    return;
  }

  int len = lseek(fd, 0, SEEK_END);
  void *addr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
  if (addr == MAP_FAILED) {
    perror("memory map error");
    return;
  }
  
  close(fd);

  int pid = fork();
  if (pid < 0) {
    perror("fork error");
    return;
  } else if (pid == 0) { /* child context */
    sleep(1);

    /* read */
    printf("[%d] child process start read data\n",getpid());

    printf("%s\n", (char *)addr);

    printf("[%d] child process end\n",getpid());
    
    return;
  } else {               /* parent context */
    /* write */
    printf("[%d] parent process start write data\n",getpid());

    char *str = "hello,world!";
    int size = strlen(str) + 1;
    memcpy(addr, str, size);

    printf("[%d] parent process write %d bytes, value = %s\n", getpid(), size, str);
  
    printf("%s\n",(char *)addr);
    
    wait(NULL);
    
    /* close */
    munmap(addr,len);
  }
}

/* 内存共享映射区 */
void foo_02(void) {
  void *addr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  if (addr == MAP_FAILED) {
    perror("memory map error");
    return;
  }

  int pid = fork();
  if (pid < 0) {
    perror("fork error");
    return;
  } else if (pid == 0) { /* child context */
    sleep(1);

    /* read */
    printf("[%d] child process start read data\n",getpid());

    printf("%s\n", (char *)addr);

    printf("[%d] child process end\n",getpid());
    
    return;
  } else {               /* parent context */
    /* write */
    printf("[%d] parent process start write data\n",getpid());

    char *str = "hello,world!";
    int size = strlen(str) + 1;
    memcpy(addr, str, size);

    printf("[%d] parent process write %d bytes, value = %s\n", getpid(), size, str);
    
    wait(NULL);
    
    /* close */
    munmap(addr,4096);
  }
}

int main(int argc, char *argv[]) {
  /* foo_01(); */
  foo_02();

  return EXIT_SUCCESS;
}
