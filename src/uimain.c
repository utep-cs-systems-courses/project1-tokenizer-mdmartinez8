
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"



int main()
{
  int terminateWord(char *str);
  char *buffIn = (char *)malloc(1000*sizeof(char *));    //Initial buffer for user input
  size_t buffSize = 1000;
  int n_chars;
  
  printf("Enter any text. 'Q' To quit program.\t'!1' To get history\n");
  printf("$");
  n_chars = getline(&buffIn, &buffSize, stdin);
  printf("getline transferred %d chars.  string=<%s>\n", n_chars, buffIn);
  if (n_chars == -1) {
    printf("Error");
  }
  
  char **tokens;
  printf("Working Before While loop\n");
  while(terminateWord(buffIn) == 0)      //Start program loop,check if user requests to terminate
  {
    printf("Working In While Loop\n");
    tokens = tokenize(buffIn);      //Tokenize
    printf("Working after tokenize\n");
    print_tokens(tokens);
    printf("Working after print_tokens\n");
    free_tokens(tokens);
    printf("\n$");
    getline(&buffIn, &buffSize, stdin);
  }
  return 0;
}

int terminateWord(char *buffIn)
{
  char *tWord = "Q";
  if(*buffIn == *tWord)
  {
    return 1;
  }
  return 0;
}
