#ifndef __STD_LIB_H__
#define __STD_LIB_H__

#include "std_type.h"

int div(int a, int b);
int mod(int a, int b);

int strcompare(char *str1, char *str2);
void strcpy(char *dst, char *src);
void clear(byte *buf, unsigned int size);

int strtoint(char *str, int *num);
void itoa(int num, char *str);

#endif // __STD_LIB_H__
