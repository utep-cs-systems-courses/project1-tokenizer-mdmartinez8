#include <stdio.h>
#include <stdlib.h>
//#include "history.c"


int main()
{
  char *buffOut = (char *)malloc(1000*sizeof(char));   //Creating buffers of size 1000
  char *buffIn = (char *)malloc(1000*sizeof(char));
  void printWords(char *buffIn);                       //Class that takes in buffer and prints it
  int terminateWord(char *buffIn);                    //Class will check if want to quit program
  /*int space_char(char c);                             //Class to check if char is space
  int non_space_char(char c);
  char *word_start(char *str);
  char *word_terminator(char *word);
  int count_words(char *str);
  char *copy_str(char *inStr, short len);
  char **tokenize(char* str);
  void print_tokens(char **tokens);
  void free_tokens(char **tokens);**/

  
  printf("Enter any text.'QUIT'To Quit\n");
  printf("$");
  gets(buffIn);
  printf("Working.\n");
  while((terminateWord(buffIn)) == 0)
  {
    printWords(buffIn);
    printf("\n$");
    gets(buffIn);
  }
  return 0;
}
void printWords(char *buffIn)
{
  //char *buffOut = (char*)malloc(1000*sizeof(char));
  printf("Working..\n");
  while(*buffIn != '\0')
  {
    putchar(*buffIn);
    buffIn++;
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

int space_char(char c)
{


}

int non_space_char(char c)
{


}


char *word_start(char *str)
{


}


char *word_terminator(char *word)
{


}


int count_words(char *str)
{


}


char *copy_str(char *inStr, short len)
{


}


char **tokenize(char *str)
{


}


void print_tokens(char **tokens)
{


}


void free_tokens(char **tokens)
{


}
// return 0;
//}  
