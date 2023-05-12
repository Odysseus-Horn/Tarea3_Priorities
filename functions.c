#include "functions.h"
#include "treemap.h"
#include  "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

void add_task(TreeMap* map, char *task_name, char* priority)
{   
    Homework *new_task = (Homework*) malloc(sizeof(Homework));

    strcpy(new_task->hw_name, task_name);
    strcpy(new_task->priority, priority);
    new_task->precedence_list = createList();


    insertTreeMap(map, new_task->priority, new_task);
}