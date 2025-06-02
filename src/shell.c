#include "shell.h"
#include "kernel.h"
#include "std_lib.h"

void shell(){
  char buf[128];
  char cmd[64];
  char arg[2][64];

  printString("Welcome to EorzeOS!\n");
  while (true) {
    printString("> ");
    readString(buf);

    clear(cmd, 64);
    clear(arg[0], 64);
    clear(arg[1], 64);

    parseCommand(buf, cmd, arg);

    printString("Command: ");
    printString(cmd);
    printString("\n");

    printString("Arg 1: ");
    printString(arg[0]);
    printString("\n");

    printString("Arg 2: ");
    printString(arg[1]);
    printString("\n");
  }
}

void parseCommand(char *buf, char *cmd, char arg[2][64]) {
  int i = 0, j = 0, k = 0;
  int state = 0;

  while (buf[i] != '\0') {
    if (buf[i] == ' ') {
      if (state == 0 && j > 0) {
        cmd[j] = '\0';
        state = 1;
        j = 0;
      } else if (state == 1 && j > 0) {
        arg[0][j] = '\0';
        state = 2;
        j = 0;
      }
    } else {
      if (state == 0) {
        cmd[j++] = buf[i];
      } else if (state == 1) {
        arg[0][j++] = buf[i];
      } else if (state == 2) {
        arg[1][j++] = buf[i];
      }
    }
    i++;
  }

  if (state == 0) {
    cmd[j] = '\0';
  } else if (state == 1) {
    arg[0][j] = '\0';
  } else if (state == 2) {
    arg[1][j] = '\0';
  }
}
