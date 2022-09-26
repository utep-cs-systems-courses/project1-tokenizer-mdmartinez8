#include <stdio.h>
#include <stdlib.h>


int main()
{
  char *buffOut = (char *)malloc(1000*sizeof(char));   //Creating buffers of size 1000
  char *buffIn = (char *)malloc(1000*sizeof(char));
  void printWords(char *buffIn);                       //Class that takes in buffer and prints it
  int terminateWord(char *buffIn);                    //Class will check if want to quit program


  
  printf("Enter any text.'QUIT'To Quit\n");
  printf("$");
  gets(buffIn);
  printf("Working.\n");
  *buffOut = buffIn;
  while((terminateWord(buffIn)) == 0)
  {
    printWords(buffOut);
    printf("\n$");
    gets(buffIn);
  }
  return 0;
}
void printWords(char *buffIn)
{
  char *buffOut = (char*)malloc(1000*sizeof(char));
  *buffOut = buffIn;
  printf("Working..\n");
  while(*buffOut != '\0')
  {
    putchar(*buffOut);
    buffOut++;
  }
  return;
}

int terminateWord(char *buffIn)             //Returns 1 if input is terminate word
{
  char *tWord = "QUIT";

  printf("Working...\n");
  while(*buffIn != '\0')
  {
    if(*buffIn != *tWord)
    {
      return 0;
    }
    buffIn++;
    tWord++;
  }

  return 1;
}
// return 0;
//}  
