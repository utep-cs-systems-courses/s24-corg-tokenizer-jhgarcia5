#ifndef _HISTORY_
#define _HISTORY_
#include <stdlib.h>
#include <stdio.h>

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

  //I need to get the size of my string
  int len = 0;
  while(str[len] != '\0'){
    len += 1;
  }

  item->str = malloc(len + 1);

  for (int i = 0; i <= len; i++){
    item->str[i] = str[i];
  }

  item->next = NULL;
  
  //If my list is NULL
  if (list->root == NULL){
    item->id = 1;
    list->root = item;
    return;
  }
  
  
  Item* current = list->root;
  while(current->next != NULL){
    current = current->next;
  }
  
  item->id = current->id + 1;
  current->next = item;
  current = current->next;
}

char *get_history(List *list, int id)
{
  Item* current = list->root;

  while(current != NULL){
    if (current->id == id){
      return current->str;
    }
    
    current = current->next;
  }

  return "That number does not exist\n";
}

void print_history(List *list)
{
  Item* current = list->root;
  puts("History");
  while(current != NULL){
    printf("ID: %d, %s\n",current->id, current->str);
    current = current->next;
  }
}

void free_history(List *list)
{
  Item* current = list->root;

  while(current != NULL){
    Item* temp = current;
    current = current->next;
    free(temp);
  }

  free(list);
  return;
}

#endif
