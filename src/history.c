#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *newHist = malloc(sizeof(Item *));
 newHist->root->id = 0;
 return newHist;

}


void add_history(List *list, char *buffIn)
{
  Item *temp = list->root;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  Item *newItem = malloc(sizeof(Item *));
  newItem->id = temp->id + 1;
  newItem->str = buffIn;
  temp->next = newItem;
}


char *get_history(List *list, int id)
{
  char *noId = "History ID does not exist.\n";
  Item *current = list->root;
  while (current->next != NULL)
  {
    if (current->id == id)
    {
      return current->str;
    }
  }
  return noId;
}


void print_history(List *list)
{
  Item *temp = list->root;
  while (temp != NULL)
  {
    printf("%d. %s", temp->id, get_history(list, temp->id));
    temp = temp->next;
  }
}


void free_history(List* list)
{
  Item *temp = list->root;
  while (temp != NULL)
  {
    
  }


}
