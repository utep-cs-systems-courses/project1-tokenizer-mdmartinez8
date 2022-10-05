
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main()
{
  char *buffIn = (char *)malloc(1000*sizeof(char));    //Initial buffer for user input

  printf("Enter any text. 'QUIT' To quit program.\t'!1' To get history\n");
  printf("$");
  fgets(buffIn, 1000, stdin);
  printf("Working Before While loop\n");
  while(terminateWord(buffIn) == 0)      //Start program loop,check if user requests to terminate
  {
    printf("Working In While Loop\n");
    char **tokens;
    tokens = malloc((count_words(buffIn)+1)*sizeof(char *));   //Allocate size for tokens
    printf("Working after count_words\n");
    tokens = tokenize(buffIn);      //Tokenize
    printf("Working after tokenize\n");
    print_tokens(tokens);
    printf("Working after print_tokens\n");
    free_tokens(tokens);
    printf("\n$");
    fgets(buffIn, 1000, stdin);

  }
  return 0;
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
