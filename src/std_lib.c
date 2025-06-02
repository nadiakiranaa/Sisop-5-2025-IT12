#include "std_lib.h"

int div(int a, int b) {
  int neg = 0;
  int res = 0;
  if (a < 0) { a = -a; neg = !neg; }
  if (b < 0) { b = -b; neg = !neg; }
  while (a >= b) {
    a -= b;
    res++;
  }
  return neg ? -res : res;
}

int mod(int a, int b) {
  int neg = 0;
  if (a < 0) { a = -a; neg = 1; }
  if (b < 0) b = -b;
  while (a >= b) a -= b;
  return neg ? -a : a;
}

bool strcmp(char *str1, char *str2) {
  while (*str1 && *str2) {
    if (*str1 != *str2) return false;
    str1++; str2++;
  }
  return *str1 == *str2;
}

void strcpy(char *dst, char *src) {
  while (*src) {
    *dst = *src;
    dst++;
    src++;
  }
  *dst = '\0';
}

void clear(byte *buf, unsigned int size) {
  unsigned int i;
  for (i = 0; i < size; i++) {
    buf[i] = 0x00;
  }
}

void atoi(char *str, int *num) {
  *num = 0;
  int sign = 1;
  if (*str == '-') {
    sign = -1;
    str++;
  }
  while (*str >= '0' && *str <= '9') {
    *num = (*num * 10) + (*str - '0');
    str++;
  }
  *num *= sign;
}

void itoa(int num, char *str) {
  char tmp[16];
  int i = 0, j = 0;
  int sign = 0;
  if (num < 0) {
    sign = 1;
    num = -num;
  }
  do {
    tmp[i++] = (num % 10) + '0';
    num = num / 10;
  } while (num > 0);
  if (sign) tmp[i++] = '-';
  while (i > 0) {
    str[j++] = tmp[--i];
  }
  str[j] = '\0';
}
