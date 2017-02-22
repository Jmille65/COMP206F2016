#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int generateLabelsFromFile(char*, char*[]);
void generateHorizLine(int, char*);
void generateDayLine(char*, char*[], int);
void generateMonthLine(char*, char*[], int, int);
int generateDateLine(char*, int, int);

int main(int argc, char *argv[])
{
  if (argc != 4)
    {
      printf("Invalid # of args. \n");
      return(0);
    }
  int daysize = atoi(argv[2]);
  if (daysize < 2)
    {
      printf("Invalid day spacing. \n");
      return(0);
    }
  int day = atoi(argv[3]);  
  if (day < 1 || day > 7)
    {
      printf("Invalid first day. \n");
      return(0);
    }
  day = 2 - day;
  char *transLabels[19];
  if (generateLabelsFromFile(argv[1], transLabels) == 0)
    {
      printf("Translation file not found. \n");
      return(0);
    }
  int currentMonthNum = 7;
  char starline[(daysize+3)*7+2];
  char dayline[(daysize+3)*7+2];
  char currentMonthLine[(daysize+3)*7+2];
  char currentDateLine[(daysize+3)*7+2];
  generateHorizLine(daysize, starline);
  generateDayLine(dayline, transLabels, daysize);
  
  while (currentMonthNum < 19)
    {
      generateMonthLine(currentMonthLine, transLabels, daysize, currentMonthNum);
      printf("%s\n%s\n%s\n%s\n%s\n", starline, currentMonthLine, starline, dayline, starline);
      while(day < 31)
	{
	  day = generateDateLine(currentDateLine, day, daysize);
	  printf("%s\n", currentDateLine);
	}
      day -= 37;
      currentMonthNum++;
    }
  printf("%s\n", starline);
  return(0);
}

int generateDateLine(char* dateline, int day, int daysize)
{
  char dateString[7][3];
  for (int i = 0; i < 7; i++)
    {
      if (day < 1 || day > 30)
	{
	  strcpy(dateString[i], "  ");
	}
      else
	{
	  sprintf(dateString[i], "%d", day);
	}
      day++;
    }
  sprintf(dateline, "* %-*.*s * %-*.*s * %-*.*s * %-*.*s * %-*.*s * %-*.*s * %-*.*s *", daysize, daysize, dateString[0], daysize, daysize, dateString[1], daysize, daysize, dateString[2], daysize, daysize, dateString[3], daysize, daysize, dateString[4], daysize, daysize, dateString[5], daysize, daysize, dateString[6]);
  return day;
}

void generateMonthLine(char* monthline, char* translabels[], int daysize, int monthNum)
{
  sprintf(monthline, "* %-*s *", (daysize+3)*7+1-4, translabels[monthNum]);
}

void generateDayLine(char *dayline, char* translabels[], int daysize)
{  
  sprintf(dayline, "* %-*.*s * %-*.*s * %-*.*s * %-*.*s * %-*.*s * %-*.*s * %-*.*s *",daysize, daysize, translabels[0], daysize, daysize, translabels[1], daysize, daysize, translabels[2], daysize, daysize, translabels[3], daysize, daysize, translabels[4], daysize, daysize, translabels[5], daysize, daysize, translabels[6]);
}

void generateHorizLine(int daysize, char* starline)
{
  int tempsize = (daysize + 3)*7 + 1;
  for (int i = 0; i < tempsize; i++)
    {
      starline[i] = '*';
    }
  starline[tempsize] = '\0';
}

int generateLabelsFromFile(char *fileName, char *sTranslated[]) //if file is not found, returns 0
{
  FILE *f;
  if ((f = fopen(fileName, "r")))
    {
      int i = 0;
      char reader[19];
      while (fscanf(f, "%s", reader) != EOF)
	{
	  sTranslated[i] = malloc(sizeof(char) * (strlen(reader) + 1));
          strcpy(sTranslated[i], reader);
	  i++;
	}
      fclose(f);
      return(1);
    }
    else
      {
	return(0);
      }
}
