#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* decrypt(int, char*);
void reverseString(char*);

int main(int argc, char* argv[])
{
  if (argc != 3) {
    printf("PEBKAC: Incorrect # of arguments\n");
    return(0);
  }

  int key = atoi(argv[1]);
  FILE *f;
  f = fopen(argv[2], "r");
  char c;
  char target[1000];
  int i = 0;
  while ((c = fgetc(f)) != EOF) {
    target[i] = c;
    i++;
  }
  fclose(f);

  char* newTarget = malloc((strlen(target)+1) * sizeof(char));
  newTarget = decrypt(key, target);
  printf("%s\n", newTarget);
  return(0);
}

char* decrypt(int key, char* original) {
  int i = 0;
  while(i < strlen(original)) {
    if((int)original[i] < key) {
      original[i] += 256;
    }
    original[i] -= key;
    i++;
  }
  original[i] = '\0';
  reverseString(original);
  return original;
}

void reverseString(char *old) {
  int len = strlen(old) - 1;
  char *newTarget = malloc(sizeof(char)*(strlen(old)+1));
  int k = len;
  for (int j = 0; j <= len; j++) { //swaps string values
    newTarget[k] = old[j];
    k--;
  }
  strcpy(old, newTarget);
}
