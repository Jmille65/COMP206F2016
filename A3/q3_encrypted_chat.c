#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char* decrypt(int, char*); //oh sweet, this actually works!
char* loadNewMessage(char*, char*);

int main(int argc, char *argv[]) {
  if(argc != 5) {
    printf("Error: PEBKAC\n"); //that's on you, man
    return(0);
  }

  int key = atoi(argv[4]);

  char newOut[1000]; //new message to send
  char writeToFile[1050]; //same as above but with label
  char *newIncoming; //stores new message from other user
  char *prevIncoming = malloc((sizeof(char)) * 11); //stores prev message from other user for comparison
  strcpy(prevIncoming, "Shibboleet\0"); //Random keyword people unlikely to say
  int newMessageFlag = 0;

  FILE* temp;
  if ((temp = fopen(argv[1], "r"))) { //if there's a new message, continue
    fseek(temp, 0, SEEK_END); //gets size of temp
    size_t tempSource = ftell(temp);
    fclose(temp);
    if (tempSource <= sizeof(char)) { //if file is empty
      printf("Nothing received yet. \n");
      goto FIRSTMESSAGER; //Bad I know, sorry. It messed me up and now I know why not to do it.
    }
  }
  else { //otherwise, skip and make this user the first messager
    printf("Nothing received yet. \n");
    fclose(temp);
    goto FIRSTMESSAGER;
  }

  //TURN-BASED CHAT STARTS HERE
  while(1) {
    //Waiting and recieving new message
    while (newMessageFlag == 0) {
      sleep(1); //let's save some processing power...
      newIncoming = loadNewMessage(newIncoming, argv[1]);
      if (strcmp(newIncoming, prevIncoming) != 0) { //if strings are different, return 1 unless
        newMessageFlag = 1;
      }
    }

    //This block prints new message and resets for next cycle
    char *incomingDecrypted = malloc(sizeof(char) * (strlen(newIncoming) + 1)); //decrypts for printing
    strcpy(incomingDecrypted, newIncoming);
    incomingDecrypted = decrypt(key, incomingDecrypted);
    printf("Received: %s", incomingDecrypted); //there's a typo in the spec image examples...
    int newSize = (sizeof(char)) * (strlen(newIncoming) + 1);
    prevIncoming = realloc(prevIncoming, newSize);
    strcpy(prevIncoming, newIncoming);
    newMessageFlag = 0;

    FIRSTMESSAGER:;//OUTPUT
    FILE* output;

    printf("Send:     ");
    fgets(newOut, 1000, stdin);
    sprintf(writeToFile, "[%s] %s", argv[3], newOut); //concats output
    char *toEncrypt = malloc((strlen(writeToFile) + 1) * sizeof(char));
    toEncrypt = decrypt(256-key, writeToFile); //encrypts
    output = fopen(argv[2], "w"); //erases old file, rewrites
    fputs(writeToFile, output);
    fclose(output);
  }
}

char* loadNewMessage(char *newIncoming, char* inputFilePath) {
  //if new message, stores in newIncoming
  //inputFilePath remains unchanged

  FILE *input;
  if ((input = fopen(inputFilePath, "r"))) {

    fseek(input, 0, SEEK_END); //gets size of input
    size_t source = ftell(input);
    fseek(input, 0, SEEK_SET); //resets file stream

    newIncoming = malloc(source); //allocates appropriate length for new string
    char c;
    int i = 0;
    while ((c = fgetc(input)) != '\n' && (feof(input) == 0)) { //reads string into newIncoming
      newIncoming[i] = c;
      i++;
    }
    newIncoming[i+1] = '\0'; //null-terminates
    fclose(input);
    return newIncoming;
  }
  else { //if file cannot be opened
    newIncoming = malloc((sizeof(char)) * 11);
    strcpy(newIncoming, "Shibboleet\0");
    return newIncoming;
  }
}
