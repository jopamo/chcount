#ifndef CHCOUNT_H
#define CHCOUNT_H

#include <stdio.h>

// Display available command-line options
void showOptions();

// Open a file and return its file pointer
FILE* openFile(char* filename);

// Count occurrences of a specified character in a file
int chCount(FILE *fp, int targetChar, int convertFlag);

// Process command-line arguments
void processArgs(int argc, char *argv[], char **inputFile, int *findChar, int *convertFlag);

// Show message about awaiting input from standard input (stdin)
void showStdinInfo();

#endif // CHCOUNT_H
