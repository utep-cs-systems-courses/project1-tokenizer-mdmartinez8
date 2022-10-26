#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)     //Returns True(non-zero) if c is a whitespace character
{
  if(c == ' ' || c == '\t' || c == '\n')
  {
    return 1;
  }
  return 0;

}

int non_space_char(char c)
{
  if (space_char(c) == 0 && c != '\0')
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
      //printf("%s",str);
      return str;
    }
    str++;
  }
  return 0;
}


char *word_terminator(char *word)
{
  while(*word != '\0')
  {
    word++;
    if(*word =='\0' || space_char(*word) == 1)
    {
      word--;
      //printf("%s\n", word);
      return word;
    }
  }
  return 0;
}


int count_words(char *str)
{
  int wCount = 0;
  while(*str != '\0')
  {
    if(word_start(str))
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
  char *copy = (char *)malloc((len)*sizeof(char *));
  for (int i = 0; i<len; i++, copy++, inStr++)
  {
    *copy = *inStr;
  }
  copy -= len;
  //printf("%s\n", copy);
  return copy;

}


char **tokenize(char *str)
{
  int wordNum = count_words(str);
  //printf("%d\n", wordNum);
  char **tokens = (char **) malloc((wordNum+1) * sizeof(char **));
  int i;
  for (i = 0; i<wordNum; i++)
  {
    str = word_start(str);
    int wLen = word_terminator(str) -  word_start(str);
    tokens[i] = copy_str(str, (wLen + 1));
    //printf("%s\n",tokens[i]);
    str = word_terminator(str);
    str++;
  }
  i++;
  tokens[i] = NULL;
  return tokens;
}


void print_tokens(char **tokens)
{
  char *current = *tokens;
  int tokenIndex = 0;
  while (current)
  {
    /*for (int i = 0; i<(word_terminator(current) - word_start(current)+1); i++)
    {
      putchar(*current);
      current++;
      }*/
    printf("%s\n", current);
    tokenIndex++;
    current = tokens[tokenIndex];
  }
}


void free_tokens(char **tokens)
{
  char *newVal = {'\0'};
  while (*tokens != NULL)
  {
    *tokens = newVal;
    tokens++;
  }

}
