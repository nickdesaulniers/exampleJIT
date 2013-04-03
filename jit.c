#include <stdio.h> // printf
#include <string.h> // memcpy
#include <sys/mman.h> // mmap, munmap

int main () {
  unsigned char code [] = {
    0x55,
    0x48, 0x89, 0xe5,
    0x89, 0x7d, 0xfc,
    0x89, 0x75, 0xf8,
    0x8b, 0x75, 0xfc,
    0x0f, 0xaf, 0x75, 0xf8,
    0x89, 0xf0,
    0x5d,
    0xc3
  };

  void* mem = mmap(NULL, sizeof(code), PROT_WRITE | PROT_EXEC,
                   MAP_ANON | MAP_PRIVATE, -1, 0);
  memcpy(mem, code, sizeof(code));
  int (*func) () = mem;
  printf("%d * %d = %d\n", 5, 11, func(5, 11));
}

