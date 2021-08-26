#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
/*
 DJ's Memory Utils
 created by SIGSEGV-666
*/

//legally do byte-precision addition & subtraction on void pointers on all compilers!
inline void* djmem_vpoffs(void* og, ssize_t offs){return (void*)(((char*)og)+offs);}

//a strided memcpy/memset
void* djmem_strided_memset(void* dst, void* src, size_t dstsize, size_t srcsize)
{
    unsigned char *ucdst = dst, *ucsrc = src, *ucend; ucend = ucdst+dstsize;
    uintptr_t bytes_remaining, bytes2copy;
    while (ucdst < ucend)
    {
        bytes_remaining = (uintptr_t)(ucend-ucdst);
        bytes2copy = (bytes_remaining >= srcsize) ? (srcsize) : (bytes_remaining);
        memcpy(ucdst, src, bytes2copy);
        ucdst += bytes2copy;
    }
    return dst;
}