#include <stdio.h>

int strleng(char* str) {
  int counter = 0;
  while (str[counter] != 0) {
    counter++;
  }
  return counter;
}

int main(int argv, char* argc[]) {
  argv--;
  while (argv > 0) {
    int counter = strleng(argc[argv]);
    while (counter >= 0) {
      printf("%c", argc[argv][counter--]);
    }
    printf(" ");
    argv--;
  }
  printf("\n");
}
