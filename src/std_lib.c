#include "std_lib.h"

int div(int a, int b) {
  bool neg = false;
  if (a < 0) {
    a = -a;
    neg = !neg;
  }
  if (b < 0) {
    b = -b;
    neg = !neg;
  }

  int res = 0;
  while (a >= b) {
    a -= b;
    res++;
  }

  return neg ? -res : res;
}

int mod(int a, int b) {
  bool neg = false;
  if (a < 0) {
    a = -a;
    neg = true;
  }
  if (b < 0) b = -b;

  while (a >= b) {
    a -= b;
  }

  return neg ? -a : a;
}

bool strcmp(char *str1, char *str2) {
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
    if (str1[i] != str2[i]) return false;
    i++;
  }
  return str1[i] == str2[i];
}

void strcpy(char *dst, char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';
}

void clear(byte *buf, unsigned int size) {
  int i;
  for (int i = 0; i < size; i++) {
    buf[i] = 0;
  }
}

void atoi(char *str, int *num) {
  int i = 0;
  int res = 0;
  bool neg = false;

  if (str[i] == '-') {
    neg = true;
    i++;
  }

  while (str[i] >= '0' && str[i] <= '9') {
    res = res * 10 + (str[i] - '0');
    i++;
  }

  *num = neg ? -res : res;
}

void itoa(int num, char *str) {
  int i = 0;
  bool neg = false;
  char temp[16];

  if (num == 0) {
    str[0] = '0';
    str[1] = '\0';
    return;
  }

  if (num < 0) {
    neg = true;
    num = -num;
  }

  while (num > 0) {
    temp[i++] = (num % 10) + '0';
    num = num / 10;
  }

  if (neg) {
    temp[i++] = '-';
  }

  // Reverse
  int j = 0;
  while (i > 0) {
    str[j++] = temp[--i];
  }
  str[j] = '\0';
}
