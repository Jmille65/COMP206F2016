#include <stdio.h>
#include <string.h>

int getMonth(char*);
int getDay(char*);
int main(int argc, char *argv[])
{
  char *translation;
  translation = argv[1];
  char day[4];
  int date;
  char month[4];
  int year;
  char time[9]; 
  char zone[4];
  scanf("%s %s %d %s %s %d", day, month, &date, time, zone, &year);
  int monthNum;
  monthNum = getMonth(month);
  int dayNum;
  dayNum = getDay(day);
  if (monthNum == 0 || dayNum == 0)
    {
      printf("Not a valid date. \n");
      return(0);
    }
  dayNum--;
  monthNum += 6;
  if ( argc != 2)
    {
      printf( "Incorrect # of arguments\n" );
    }
  else
    {
      FILE *f;
      if(f = fopen(translation, "r"))
	{
	  char sTranslated[19][20];
	  fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", sTranslated[0], sTranslated[1], sTranslated[2], sTranslated[3], sTranslated[4], sTranslated[5], sTranslated[6], sTranslated[7], sTranslated[8], sTranslated[9], sTranslated[10], sTranslated[11], sTranslated[12], sTranslated[13], sTranslated[14], sTranslated[15], sTranslated[16], sTranslated[17], sTranslated[18]);
	  fclose(f);
	  printf("%s %s %d %s %s %d\n", sTranslated[dayNum], sTranslated[monthNum], date, time, zone, year);
	}
      else
	{
	  printf("File is not a translation file. \n");
	}
    }
  return(0);
}

int getDay(char *day)
{
  int dayNum;
  char sun[4];
  char mon[4];
  char tue[4];
  char wed[4];
  char thu[4];
  char fri[4];
  char sat[4];
  strcpy(sun, "Sun");
  strcpy(mon, "Mon");
  strcpy(tue, "Tue");
  strcpy(wed, "Wed");
  strcpy(thu, "Thu");
  strcpy(fri, "Fri");
  strcpy(sat, "Sat");
  if (strcmp(day, sun) == 0)
    {
      dayNum = 1;
    }
  if (strcmp(day, mon) == 0)
    {
      dayNum = 2;
    }
  if (strcmp(day, tue) == 0)
    {
      dayNum = 3;
    }
  if (strcmp(day, wed) == 0)
    {
      dayNum = 4;
    }
  if (strcmp(day, thu) == 0)
    {
      dayNum = 5;
    }
  if (strcmp(day, fri) == 0)
    {
      dayNum = 6;
    }
  if (strcmp(day, sat) == 0)
    {
      dayNum = 7;
    }
  return dayNum;
}

int getMonth(char *month)
{
  int monthNum;
  char jan[4];
  char feb[4];
  char mar[4];
  char apr[4];
  char may[4];
  char jun[4];
  char jul[4];
  char aug[4];
  char sep[4];
  char oct[4];
  char nov[4];
  char dec[4];
  strcpy(jan, "Jan");
  strcpy(feb, "Feb");
  strcpy(mar, "Mar");
  strcpy(apr, "Apr");
  strcpy(may, "May");
  strcpy(jun, "Jun");
  strcpy(jul, "Jul");
  strcpy(aug, "Aug");
  strcpy(sep, "Sep");
  strcpy(oct, "Oct");
  strcpy(nov, "Nov");
  strcpy(dec, "Dec");
  if (strcmp(month, jan) == 0)
    {
      monthNum = 1;
    }
  if (strcmp(month, feb) == 0)
    {
      monthNum = 2;
    }
  if (strcmp(month, mar) == 0)
    {
      monthNum = 3;
    }
  if (strcmp(month, apr) == 0)
    {
      monthNum = 4;
    }
  if (strcmp(month, may) == 0)
    {
      monthNum = 5;
    }
  if (strcmp(month, jun) == 0)
    {
      monthNum = 6;
    }
  if (strcmp(month, jul) == 0)
    {
      monthNum = 7;
    }
  if (strcmp(month, aug) == 0)
    {
      monthNum = 8;
    }
  if (strcmp(month, sep) == 0)
    {
      monthNum = 9;
    }
  if (strcmp(month, oct) == 0)
    {
      monthNum = 10;
    }
  if (strcmp(month, nov) == 0)
    {
      monthNum = 11;
    }
  if (strcmp(month, dec) == 0)
    {
      monthNum = 12;
    }
  return monthNum;
}
