#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int add(int a, int b) {
  return a + b;
}

int* get_numbers() {
  int* numbers = malloc(sizeof(int) * 2);

  numbers[0] = rand();
  numbers[1] = rand();

  return numbers;
}


int main(void) {
  srand(time(NULL));

  for (int i = 0; i < 10; i++) {
    printf("%d + %d = %d\n", get_numbers()[0], get_numbers()[1], add(get_numbers()[0], get_numbers()[1]));
  }
  return 0;
}
