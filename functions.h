#ifndef functions_h
#define functions_h

#include "treemap.h"
#include "list.h"

typedef struct
{   
    char *priority;
    char *hw_name;
    List *precedence_list;
} Homework;

void show_menu();

void add_task();

#endif