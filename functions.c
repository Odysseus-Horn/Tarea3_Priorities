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


int is_in_list(List *list, Homework *task)
{
    Homework* current_list = (Homework*) firstList(list);
    while(current_list != NULL)
    {   
        if(strcmp(current_list->hw_name,task->hw_name) == 0) return 1;

        current_list = (Homework*) nextList(list);
    }

    return 0;
}

void show_list_precedence(List *list)
{
    Homework* current = (Homework*) firstList(list);

    printf("[");
    while(current != NULL)
    {
        printf(" %s", current->hw_name);
        
        current = (Homework*) nextList(list);
    }
    puts("]");
}


List *create_task_list(TreeMap * map)
{   
    
    Homework *AuxTask = (Homework *) firstTreeMap(map); //elemento del mapa

    List *tasks_list = createList(); //lista de las tareas ordenadas

    while (AuxTask != NULL) //bucle para recorrer tareas //a1
    {
        

        Homework* current_precedence = (Homework*) firstList(AuxTask->precedence_list);

        

        if(current_precedence == NULL)
        {   
            

            if(is_in_list(tasks_list, AuxTask) == 0) // si aun no ha entrado en la lista a imprimir, se inserta (en caso de que no se cumpla la condicion)
            {   
                pushBack(tasks_list, AuxTask);
            }

        }
        else //si es que la tarea tiene precedencias se ejecutan estas primero
        {
            
            while(current_precedence != NULL)
            {
                if(is_in_list(tasks_list, current_precedence) == 0) // si no ha entrado en la lista se inserta.
                {   
                    
                    pushBack(tasks_list, current_precedence);
                }
                current_precedence = (Homework*) nextList(AuxTask->precedence_list);
            }

            if(is_in_list(tasks_list, AuxTask) == 0) // si aun no ha entrado en la lista a imprimir, se inserta (en caso de que no se cumpla la condicion)
            {   
                pushBack(tasks_list, AuxTask);
            }
            

        }
        AuxTask = (Homework*) nextTreeMap(map);
    }


    return tasks_list;
}


void show_without_order(TreeMap *map) //FUNCION PARA VERIFICAR ERRORES
{
    Homework *current = (Homework*) firstTreeMap(map);

    while(current != NULL)
    {
        printf("Tarea %s\n", current->hw_name);
        
        current = (Homework*) nextTreeMap(map);
    }

    system("pause");
}

void show_to_do(TreeMap *map)
{

    //show_without_order(map);


    if(firstTreeMap(map) == NULL)
    {
        printf("No existe ninguna tarea, por favor ingrese una tarea\n");
        return;
    }

    
    
    List *full_list = create_task_list(map);
    
    /*printf("PROBANDO DESPUES DE MOSTRAR PRIORIDADES");
    show_list(full_list);
    system("pause");
    */

    Homework* current_list = (Homework *) firstList(full_list);
    

    while(current_list != NULL)
    {   

        printf("Nombre: %s (Prioridad: %s) ", current_list->hw_name, current_list->priority);

        if(firstList(current_list->precedence_list) != NULL)
        {   

            printf("Precedente: ");
            show_list_precedence(current_list->precedence_list);
        }
        puts("");
        current_list = nextList(full_list);
    }
    system("pause");
    system("cls");
}







