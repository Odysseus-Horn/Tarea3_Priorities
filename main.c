#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"
#include "list.h"
#include "treemap.h"
#include <string.h>
#include <unistd.h>
#define MAXCHAR 30


int lower_than_string(void* key1, void* key2){
    char* k1=(char*) key1;
    char* k2=(char*) key2;
    if(strcmp(k1,k2)<0) return 1;
    return 0;
}

void enter_value(char *value, char* text_to_show)
{   
    puts("\n========================================");
    printf("%s\n", text_to_show);
    puts("=========================================");
    
    scanf("%30[^\n]s", value);

    while(getchar() != '\n');
}

int main()
{   

    TreeMap *homeworks = createTreeMap(lower_than_string);

    while(1)
    {  
        show_menu();
        int choice;
        scanf("%d", &choice);
        
        while(getchar() != '\n');


        char name[MAXCHAR];
        char priority[MAXCHAR];
        char precedence[MAXCHAR];

        
        switch (choice)
        {
            case 1:
                system("cls");
                
                enter_value(name, "Por favor ingrese el nombre de la tarea:");
                

                enter_value(priority, "Ingrese la prioridad que le quiere asignar:");

                add_task(homeworks, name, priority);

                puts("task added succesfully");


                system("pause");
                system("cls");
                break;
            case 2:
                enter_value(name, "Ingrese el nombre de la tarea:");
                
                enter_value(precedence, "Por favor ingrese el nombre de la tarea a preceder:");
                
                establish_precedence(homeworks, name, precedence);
                break;
            case 3:
                show_to_do(homeworks);

                system("pause");
                break;
            case 4:
                //calls mark_as_done()
                break;
            
            case 5:
                system("cls");
                printf("Hasta luego :D");

                sleep(3);
                return 0;
                break;
            default:
                printf("Opcion no valida, por favor intente nuevamente");
                break;
        }


    }

}