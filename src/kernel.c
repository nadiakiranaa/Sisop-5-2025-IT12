#include "shell.h"
#include "kernel.h"

int main() {
  clearScreen();
  shell();
}

void printString(char *str)
{
  int i = 0;
  while (str[i] != '\0') {
    interrupt(0x10, 0x0E00 + str[i], 0, 0, 0);
    i++;
  }
}

void readString(char *buf)
{
  int i = 0;
  char c = 0;

  while (1) {
    c = interrupt(0x16, 0x0000, 0, 0, 0);
    if (c == 0x0D) {
      break;
    } else if (c == 0x08) {
      if (i > 0) {
        i--;
        printString("\b \b");
      }
    } else {
      buf[i] = c;
      i++;
      char out[2] = {c, '\0'};
      printString(out);
    }
  }

  buf[i] = '\0';
  printString("\r\n");
}

void clearScreen()
{
  int i;
  for (i = 0; i < 2000; i++) {
    putInMemory(0xB000, 2 * i, ' ');
    putInMemory(0xB000, 2 * i + 1, 0x07);
  }
  interrupt(0x10, 0x0200, 0, 0, 0);
}
