#include <stdio.h>
#include <stdlib.h>
#include "uimain.c"

int space_char(char c)     //Returns True(non-zero) if c is a whitespace character
{
  if(c == ' ' || c == '\t')
  {
    return 1;
  }
  return 0;

}

int non_space_char(char c)
{
  if (space_char(c) == 0)
  {
    return 1;
  }
  return 0;

}


char *word_start(char *str)
{
  while(*str != '\0')
  {
    if(non_space_char(str)==1)
    {
      return str;
    }
    
    str++;
  }
  return 0;
}


char *word_terminator(char *word)
  if(word_start(word))
  {
    return 0;
  }
  while(*word != '\0')
  {
    word++;
    if(word =='\0' || space_char(word) == 1)
    {
      return word--;
    }
  }
}


int count_words(char *str)
{
  int wCount = 0;
  while(*str != '\0')
  {
    if(word_start(str) != 0)
    {
      wCount++;
    }
    str = word_terminator(str)++;
  }
  return 0;
}


char *copy_str(char *inStr, short len)
{
  char *copy = (char *)malloc(1000*sizeof(char));
  while((*copy++ = *inStr++) != '\0')
    ;
  return copy;

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
