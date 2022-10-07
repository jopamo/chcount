/*
# Char counter
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "findc.h"

void showOptions() {
  printf("\nThis executable findC takes the following optional command line options:\n");
    printf("\t-h : Output a help message indication what types of inputs it expects.\n");
    printf("\t-f : filename input string.\n");
    printf("\t-c : Specifies a different character to look for in the target file.\n");
}

int main(int argc, char *argv[]) {
  FILE *filePointer = NULL;
  char *inputFile = NULL;

  int findChar  = 'c';
  int ch = 0;

  int opt = 0;
  int flagF = 0;
  int flagC = 0;
  int flagT = 0;
  int num = 0;

  //':' after each option to take args
  while ((opt = getopt(argc, argv, "f:c:h")) != -1) {
    switch (opt) {
      case 'h':
        showOptions();
        exit(0);
      case 'f':
        flagF = 1;
        inputFile = optarg;
        break;
      case 'c':
        flagC = 1;
        findChar = optarg[0];
        break;
      default:
        showOptions();
        exit(1);
      }
  }

  // this is needed to catch these two cases of no input, 0 is stdin
  if (isatty(0))
    flagT = 1;

  if (flagT == 1 && flagC == 1 && flagF == 0) {
    printf("You specified the -c without specifying -f. Try again.\n");
    showOptions();
    exit(1);
  }

  if (flagT == 1 && flagC == 0 && flagF == 0) {
    printf("You did not specify input. Try again.\n");
    showOptions();
    exit(1);
  }

  //stdin pointer is there for us, only open if needed
  if (flagF == 1) {
    filePointer = fopen(inputFile, "r");

    if (filePointer == NULL) {
      printf("Error on input. Try again.\n");
      showOptions();
      exit(1);
    }
  }

  //working logic
  if ((flagC == 0 && flagF == 1) ||
      (flagC == 1 && flagF == 1)) {
      //go through input char by char until EOF
      //use fgetc on file
      while ((ch = fgetc(filePointer)) != EOF) {
        if (findChar == ch) {
          num++;
        }
      }
      printf("Number of %c's found: %i\n", findChar, num);

      //again only close file, never stdin
      fclose(filePointer);

  } else if ((flagC == 0 && flagF == 0) ||
             (flagC == 1 && flagF == 0)) {
      //go through input char by char until EOF
      //use getchar() on stdin
      while (ch != EOF) {
        if (findChar == ch) {
          num++;
        }
        ch = getchar();
      }
      printf("Number of %c's found: %i\n", findChar, num);
  } else {
      printf("Error on input. Try again.\n");
      showOptions();
      exit(1);
  }

  return 0;
}
