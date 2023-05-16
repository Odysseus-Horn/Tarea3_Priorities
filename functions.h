#ifndef functions_h
#define functions_h
#define MAXCHAR 30

#include "treemap.h"
#include "list.h"

typedef struct
{   
    char priority[MAXCHAR];
    char hw_name[MAXCHAR];
    List *precedence_list;
} Homework;

void show_menu();

void add_task(TreeMap* map, char *task_name, char* priority);

void establish_precedence(TreeMap* map, char *task_name, char* precedence_name);

void show_to_do(TreeMap *map);

#endif