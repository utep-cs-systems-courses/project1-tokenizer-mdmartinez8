#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

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
    if(non_space_char(*str)==1)
    {
      return str;
    }
    
    str++;
  }
  return 0;
}


char *word_terminator(char *word)
{
  if(word_start(word) == 0)
  {
    return 0;
  }
  while(*word != '\0')
  {
    word++;
    if(*word =='\0' || space_char(*word) == 1)
    {
      return word--;
    }
  }
  return 0;
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
    str = word_terminator(str);
    str++;
  }
  return wCount;
}


char *copy_str(char *inStr, short len)
{
  char *copy = (char *)malloc(len*sizeof(char));
  while((*copy++ = *inStr++) != '\0')
    ;
  return copy;

}


char **tokenize(char *str)
{
  char **tokens;
  tokens = malloc((count_words(str)+1)*sizeof(char *));
  while(*str != '\0' && (word_start(str) != 0))
  {
    *tokens = word_start(str);
    tokens++;
    str = word_terminator(str);
    str++;
  }
  return tokens;
}


void print_tokens(char **tokens)
{
  while (**tokens != 0)
  {
    char *current = *tokens;
    while (*current != '\0')
    {
      putchar(*current);
      current++;
    }
    
  }

}


void free_tokens(char **tokens)
{
  while (**tokens != 0)
  {
    tokens = '\0';
    tokens++;
  }

}
