#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "chCount.h"
#include "chConvert.h"

void showOptions() {
  printf("\nOptions:\n");
  printf("\t-h : Output a help message.\n");
  printf("\t-f <filename> : Specify the filename to process.\n");
  printf("\t-c <character> : Specify a character to count in the file.\n");
  printf("\t-u : Convert all characters to upper case.\n");
  printf("\t-l : Convert all characters to lower case.\n");
}

FILE* openFile(char* filename) {
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    perror("Error opening file");
    exit(1);
  }
  return fp;
}

int chCount(FILE *fp, int targetChar, int convertFlag) {
  int ch, count = 0;
  while ((ch = fgetc(fp)) != EOF) {
    if (convertFlag == 1) ch = toUpper(ch);
    if (convertFlag == 2) ch = toLower(ch);
    if (ch == targetChar) count++;
  }
  return count;
}

void processArgs(int argc, char *argv[], char **inputFile, int *findChar, int *convertFlag) {
  int opt;
  while ((opt = getopt(argc, argv, "f:c:hul")) != -1) {
    switch (opt) {
      case 'h':
        showOptions();
        exit(0);
      case 'f':
        *inputFile = optarg;
        break;
      case 'c':
        *findChar = optarg[0];
        break;
      case 'u':
        *convertFlag = 1;
        break;
      case 'l':
        *convertFlag = 2;
        break;
      default:
        showOptions();
        exit(1);
    }
  }
}

void showStdinInfo() {
  printf("Awaiting input from standard input (stdin).\n");
  printf("Type input followed by EOF (Ctrl+D in Unix/Linux, Ctrl+Z followed by Enter in Windows).\n");
  printf("You may need to hit Enter before your EOF combo.\n");
}

int main(int argc, char *argv[]) {
  char *inputFile = NULL;
  int findChar = 'c';
  int convertFlag = 0;
  int count = 0;

  processArgs(argc, argv, &inputFile, &findChar, &convertFlag);

  FILE *fp = NULL;
  if (inputFile) {
    fp = openFile(inputFile);
  } else {
    showStdinInfo();
    fp = stdin;
  }

  count = chCount(fp, findChar, convertFlag);

  printf("Number of '%c's found: %d\n", findChar, count);

  if (inputFile) {
    fclose(fp);
  }

  return 0;
}
