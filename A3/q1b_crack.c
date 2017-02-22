#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char*);
int conditionCheck(char*);

int main(int argc, char* argv[])
{

  FILE *f;
  f = fopen(argv[1], "r");
  char c;

  fseek(f, 0, SEEK_END); //gets size of f
  size_t source = ftell(f);
  fseek(f, 0, SEEK_SET); //resets file stream

  char *target = malloc(source); //allocates appropriate length file
  int i = 0;
  while ((c = fgetc(f)) != EOF) { //provides initial string
    target[i] = c;
    i++;
  }
  fclose(f);
  reverseString(target);

  int key = 0;
  char *temp = malloc(source);
  strcpy(temp, target);
  while (conditionCheck(temp) != 1) {
    if (key >= 256) {
      printf("No appropriate string found\n");
      return(0);
    }

    for (int j = 0; j < strlen(target); j++) { //
      temp[j]++; //because key increments by one, increment target by one
      if ((int)temp[j] > 256) { //if target > possible ascii value
        temp[j] -= 256;
      }
    }
    key++;
  }

  printf("%d\n%s\n", (256-key), temp);
  return(0);
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

int conditionCheck(char *target) { //checks for appropriate string conditions outlined in assignment, returns 1 if valid string
  int containsAa = 0;
  int containsZz = 0;
  for (int i = 0; i < strlen(target); i++) { //loops through each letter
    if (((int)target[i] > 64 && (int)target[i] < 91) || ((int)target[i] > 96 && (int)target[i] < 123) || ((int)target[i] == 0) || ((int)target[i] == 32)) { //if valid character
    }
    else {
      return(0);
    }
    if (target[i] == 65 || target[i] == 97) { //if string contains [aA] set 1
      containsAa = 1;
    }
    if (target[i] == 90 || target[i] == 122) { //same but for [Zz]
      containsZz = 1;
    }
  }
  if (containsAa == 1 && containsZz == 1) {
    return(1);
  }
  else {
    return(0);
  }
}
