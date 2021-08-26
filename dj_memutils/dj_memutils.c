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