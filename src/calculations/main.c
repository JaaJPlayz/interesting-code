#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int add(int a, int b) {
  return a + b;
}


int main(void) {
  srand(time(NULL));
  int numbers[2]; 

  for (int i = 0; i < 2; i++) {
    numbers[i] = rand() % 100;
  }

  for (int i = 0; i < 10; i++) {
    printf("%d + %d = %d\n", numbers[0], numbers[1], add(numbers[0], numbers[1]));
  }
  return 0;
}
