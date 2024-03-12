#ifndef _HISTORY_
#define _HISTORY_
#include <stdlib.h>

typedef struct s_Item {

  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {

  struct s_Item *root;

} List;

List* init_history()
{
  List* history = malloc(sizeof(List));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str)
{

  Item* item = malloc(sizeof(Item));
  int currId = 0;

  Item* current = list->root;
  while(current->next != NULL){
    current = current->next;
    currId += 1;
  }
  item->id = currId;
  item->str = str;
  item->next = NULL;
  current->next = item;
}

char *get_history(List *list, int id)
{
  Item* current = list->root;

  while(current->id != id){
    current = current->next;
  }

  return current->str;
}

void print_history(List *list)
{

  Item* current = list->root;
  put("History");
  while(current != NULL){
    printf("ID: %d, %s",current->id, current->str);
    current = current->next;
  }

}

void free_history(List *list)
{

}

#endif
