#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <libgen.h>

int add(int a, int b) {
  return a + b;
}

int writeToFile(char* content) {
  FILE* fptr;

  char* dir;

  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) == NULL) {
    return 1;
  } 

  dir = dirname(cwd);
  dir = dirname(dir);

  char* finalPath = strcat(dir, "/public/results.txt");

  fptr = fopen(finalPath, "w");

  if (fptr == NULL) {
    return 1;
  }

  fprintf(fptr, content);
  fclose(fptr);
  
  return 0;
}

int main(void) {
  srand(time(NULL));
  char buffer[1024];
  int numbers[2]; 

  for (int i = 0; i < 2; i++) {
    numbers[i] = rand() % 100;
  }

  for (int i = 0; i < 10; i++) {
    sprintf(buffer, "%d + %d = %d\n", numbers[0], numbers[1], add(numbers[0], numbers[1]));
    writeToFile(buffer);
  }

  return 0;
}
