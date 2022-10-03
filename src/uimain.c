
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main()
{
  char *buffIn = (char *)malloc(1000*sizeof(char));

  printf("Enter any text. 'QUIT' To quit program.\n");
  printf("$");
  scanf("%s", buffIn);

  while(terminateWord(buffIn) == 0)
  {
    printWords(buffIn);
    printf("\n$");
    scanf("%s", buffIn);

  }
  return 0;
}

void printWords(char *buffIn)
{
  while(*buffIn != '\0')
  {
    putchar(*buffIn);
    buffIn++;
  }
  return;
}

int terminateWord(char *buffIn)
{
  char *tWord = "QUIT";

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
