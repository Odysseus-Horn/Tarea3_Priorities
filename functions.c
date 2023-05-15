#include "functions.h"
#include "treemap.h"
#include  "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXCHAR 30


void show_menu()
{
    puts(" ---------------------------------------------------");
    puts("| ingrese una opcion:                               |");
    puts("|                                                   |");
    puts("| 1) Agregar tarea.                                 |");
    puts("| 2) Establecer precedencia entre tareas.           |"); 
    puts("| 3) Mostrar tareas por hacer.                      |");
    puts("| 4) marcar tarea como completada.                  |");
    puts("| 5) Salir.                                         |");
    puts(" ---------------------------------------------------");
}

int is_in_tree(TreeMap *map, char* task_name)
{
    Homework *current_task = (Homework*) firstTreeMap(map);
    
    while(current_task != NULL)
    {
        if(strcmp(task_name, current_task->hw_name) == 0)
            return 1;

        current_task = (Homework *) nextTreeMap(map);
    }

    return 0;
}

void add_task(TreeMap* map, char *task_name, char* priority)
{   
    
    Homework *new_task = (Homework*) malloc(sizeof(Homework));

    
    if(is_in_tree(map, task_name) == 1)
    {   
        system("cls");
        printf("La tarea ya existe en la lista, por favor intente de nuevo:\n");

        system("pause");
    }


    strcpy(new_task->hw_name, task_name);
    strcpy(new_task->priority, priority);
    new_task->precedence_list = createList();

    
    insertTreeMap(map, new_task->priority, new_task);

    return;
}

void establish_precedence(TreeMap* map, char *task_name)
{   

    //debemos verificar si la tarea existe
    TreeMap *auxMap = map;
    Homework *auxTask = (Homework*) firstTreeMap(auxMap);

}








