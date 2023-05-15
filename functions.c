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

void establish_precedence(TreeMap* map, char *task_name, char* precedence)
{   

    if(is_in_tree(map, task_name) == 1 && is_in_tree(map, precedence) == 1)
    {   
        Homework *auxTask = (Homework*) firstTreeMap(map);

        while(auxTask != NULL)
        {
            if(strcmp(auxTask->hw_name, task_name) == 0)
            {
                pushBack(auxTask->precedence_list, precedence);
                printf("La tarea %s fue precedida en la tarea %s exitosamente.\n\n", precedence, task_name);
                return;
            }
            auxTask = (Homework*) nextTreeMap(map);
        }
    }
    else
    {
        printf("la tarea o la tarea a preceder no existe, intentelo de nuevo:\n");
    }
}








