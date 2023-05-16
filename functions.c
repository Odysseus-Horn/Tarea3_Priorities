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

Homework* findTask(TreeMap *map, char* precedence)
{
    Homework *auxTask = (Homework*) firstTreeMap(map);

    while(auxTask != NULL)
    {
        if(strcmp(precedence, auxTask->hw_name) == 0) return auxTask;

        auxTask = (Homework *) nextTreeMap(map);
    }

    return NULL;
}

void establish_precedence(TreeMap* map, char *task_name, char* precedence)
{     

    if(strcmp(task_name, precedence) == 0)
    {
        puts("Una tarea no puede ser precedente de si misma, por favor intentelo de nuevo.");

        system("pause");
        return;
    }

    if(is_in_tree(map, task_name) == 1 && is_in_tree(map, precedence) == 1) 
    {   
        
        Homework *precedenceTask = findTask(map, precedence);
        Homework *auxTask = findTask(map, task_name);

        pushBack(auxTask->precedence_list, precedenceTask); 
        printf("La tarea %s fue precedida en la tarea %s exitosamente.\n\n", precedenceTask->hw_name, auxTask->hw_name);
        system("pause");
        return;
    }
    else
    {
        printf("la tarea o la tarea a preceder no existe, intentelo de nuevo:\n");
        system("pause");
    }
}

void show_element(Homework* task)
{
    printf("Nombre: %s (Prioridad: %s )", task->hw_name, task->priority);
    Homework *auxPrecedence = (Homework *) firstList(task->precedence_list);

    if("")
    while(auxPrecedence != NULL)
    {
        printf("%s ", auxPrecedence);

        auxPrecedence = (Homework *) nextList(task->precedence_list);
    }

    puts("");
}

void fill_task_list(TreeMap * map, List* tasks_list)
{
    Homework *AuxTask = (Homework *) firstTreeMap(map);



}



void show_to_do(TreeMap *map)
{

    if(firstTreeMap(map) == NULL)
    {
        printf("No existe ninguna tarea, por favor ingrese una tarea\n");
        system("pause");
    }

    List *full_list = createList();

    fill_task_list(map, full_list);

}







