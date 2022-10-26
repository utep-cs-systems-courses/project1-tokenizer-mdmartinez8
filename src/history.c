#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *newHist = (List *) malloc(sizeof(List *));
 newHist->root = malloc(sizeof(Item *));
 newHist->root->id = 0;
 printf("%d\n", newHist->root->id);
 return newHist;

}


void add_history(List *list, char *buffIn)
{
  if (list->root->id == 0)
  {
    list->root->str = buffIn;
    list->root->id = 1;
    return;
  }
  Item *temp = list->root;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  Item *newItem = (Item *)malloc(sizeof(Item *));
  newItem->id = temp->id + 1;
  newItem->str = buffIn;
  temp->next = newItem;
}


char *get_history(List *list, int id)
{
  char *noId = "History ID does not exist.";
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
  while (temp->next != NULL)
  {
    printf("%d. %s", temp->id, temp->str);
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
