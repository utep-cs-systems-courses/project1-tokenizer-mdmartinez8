
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"



int main()
{
  int terminateWord(char *str);
  char *buffIn = (char *)malloc(1000*sizeof(char *));    //Initial buffer for user input
  List *history = init_history();
  size_t buffSize = 1000;
  int n_chars;
  
  printf("Enter any text. 'Q' To quit program.\t'!!' To get all history\t'!1' To get first input\n");
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
    if (*buffIn == '!')   //If user inquires about history
    {
      buffIn++;
      if (*buffIn == '!')
      {
	print_history(history);
      }else
      {
	printf("%s", get_history(history, *buffIn));
      }
    }
    //printf("Working In While Loop\n");
    tokens = tokenize(buffIn);      //Tokenize
    //printf("Working after tokenize\n");
    print_tokens(tokens);
    //printf("Working after print_tokens\n");
    add_history(history, buffIn);
    free_tokens(tokens);
    printf("\n$");
    getline(&buffIn, &buffSize, stdin);
  }
  //free_history(history);
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
