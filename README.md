# Tarea3_Priorities
Tarea 3 de Estructura de datos, ing Civil informática

Organizador de tareas utilizando TDA mapa y lista

---
**antes de Empezar**

* El repositorio fue creado y manejado con Github Desktop.
* Para compilar se usa el comando: `gcc -g main.c list.c functions.c treemap.c -o Tarea3` y luego se ejecuta con el comando `\Tarea3.exe`.
* Se recomienda simplemente ejecutar el codigo desde el archivo `Tarea3.exe`.

---

Se utilizo un arbol binario que aceptase claves repetidas y las mande al lado izquierdo para almacenamiento ordenado de los datos y listas enlazadas para organizacion de las precedencias

las TDAS utilizadas son TDA lista y TDA mapa.

Se creo una estructura en la que se guardan las tareas de la siguiente forma:

````
//MAXCHAR es igual a 30 caracteres.
typedef struct
{   
    char priority[MAXCHAR]; 
    char hw_name[MAXCHAR];
    List *precedence_list;
} Homework;
````
# Funcionalidades

el programa funciona a traves de un menu en una terminal que tiene las siguientes:

----

- **Opcion 1: Agregar tarea**

  Esta opcion llama a la funcion `add_task()` que procede a pedir el nombre de la tarea a ingresar y su prioridad, estos valores se guardan y luego verifica si la tarea ya existe en el arbol con la funcion `findTask()`, en caso de que no exista, se inicializa una estructura Homework donde se copiaran los datos ingresados del usuario y se creara una lista para las precedencias, luego concluye al insertar la tarea al arbol.

- **Opcion 2: Establecer precedencia**

  La opcion llama a la funcion `establish_precedence()` que procede a preguntar al usuario la tarea X a la que le quiere establecer precedencias y la tarea Y que se precedera de esta, luego de esto se verifica que ambas tareas, la elegida y la a preceder existan en el arbol. En el caso de que existan, se guardan las variables de ambas tareas con `FindTask()` y se inserta la tarea Y a la lista de precedencias de la tarea X.
  
- **Opcion 3: Mostrar tareas ordenadas**

  La opcion llamara a `show_to_do()` funcion que mostrara una lista con los datos ordenados por prioridad y precedencia de la siguiente forma. Primero se crea una lista donde se insertaran los datos ordenados y se empezara a recorrer el arbol desde el valor con prioridad mas alta (valor menor) y pregunta si es que tiene precedencias, en el caso de que sea asi, se procesan las tareas precedentes que tambien se les hara la misma pregunta para luego insertarlas al arbol, hasta terminar de ejecutar la lista. Tener en cuenta que se verifica en cada insercion si es que esa tarea ya existe en la lista para evitar que se inserten tareas ya insertadas previamente probablemente por las listas de precedencia. una vez llena la lista simplemente se muestran las tareas con su nombre, prioridad y lista de precedencias de forma enumerada
  
- **Opcion 4: Marcar tarea como completada**

  la opcion llama a `mark_as_done()` que procede a pedir al usuario la tarea a eliminar y se verifica si existe previamente. Si es asi, se recorren en el arbol todas las listas para buscar si existen precedencias con el nombre de la tarea a eliminar para luego proceder inmediatamente a eliminar la tarea dicha.
  
- **Opcion 5: Salir**
finaliza el codigo y procede a cerrar el programa.
---
**Coevaluacion Personal**

| Nombres | Participación | Responsabilidad | Comunicación | Calidad de trabajo | Trabajo en equipo | TOTAL |
|--------|--------------|----------------|--------------|--------------------|------------------|-------|
| Ulysses B. | 20 | 20 | 20 | 20 | 20 | 100 |
  
  


