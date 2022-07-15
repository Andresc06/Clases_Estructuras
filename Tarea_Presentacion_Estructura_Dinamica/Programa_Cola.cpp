#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXIMO 50

/*Definir la estructura de un nodo en general*/
struct nodo {
    char task[MAXIMO]; // Declaracion del dato
    nodo *next;
};
 
/*Declarar la estructura de la cola*/
struct cola {
    nodo *delante;
    nodo *fin;
};

/*Funcion para saber si la cola esta vacia*/
bool vacia(nodo *delante) {
	
	// Si esta vacia entonces retorna true, de lo contrario retorna false
	if (delante == NULL) return true;
	else return false;
}
 
/*Se crea la funcion de agregar elementos a la cola*/

void agregar( struct cola &c, char *task) {
     
     //Creacion de un nuevo puntero y asignacion de sus datos
	 nodo *new_nodo = new nodo();
     strcpy(new_nodo->task, task); //strcpy porque estamos hablando de cadenas
     new_nodo -> next = NULL;
     
     // Si esta vacia entonces delante y fin son el nuevo nodo
     if(c.delante == NULL)
         c.delante = new_nodo;
         
     // Si no esta vacia entonces el puntero siguiente es el nuevo nodo y fin se le asigna el nuevo nodo
     else
         (c.fin) -> next = new_nodo;
         
     c.fin = new_nodo;
     
}
 
/*Se crea la funcion de eliminar un elemento en la cola*/

void eliminar( struct cola &c )
{
	 //char task[MAXIMO];
     struct nodo *new_nodo; 
     new_nodo = c.delante;      		// new_nodo apunta al inicio de la cola
     c.delante = (c.delante) -> next;	// Se cambia el puntero que apunta hacia adelante hacia el siguiente dato
     delete(new_nodo);         		 	// libera memoria a donde apuntaba new_nodo
     
}

/*Vaciar Cola*/

void vaciar( struct cola &c)
{
    struct nodo *new_nodo;
     
     while( c.delante != NULL) {
        new_nodo = c.delante;
        c.delante = new_nodo->next;
        delete(new_nodo);
     }
     c.delante = NULL;
     c.fin   = NULL;
     
}
 
/*Mostrar Cola*/

void mostrar( struct cola c )
{
     struct nodo *new_nodo;
     int i = 1;
	      
     new_nodo = c.delante;
         
	 // Mientras exista un nuevo nodo se imprima el dato de ese nodo
     while( new_nodo != NULL) 
     {
        printf("\t%d) %s\n", i, new_nodo->task);
        new_nodo = new_nodo->next;
        i++;
     }    
}

/*Mostrar Frente*/

void frente( struct cola c )
{
     struct nodo *new_nodo;
     new_nodo = c.delante;
	 printf("\n\tLa tarea que esta de primero en la cola es: %s\n\n", new_nodo->task);  
}
 
/*Funcion Principal*/
int main()
{
   
	struct cola c;
   
    c.delante = NULL;
    c.fin   = NULL;
   
    char task[MAXIMO];   
    int op;    // opcion elegida del menu
    //char x;    // dato que devuelve la funcion delete
    	
    do {
    	
		printf("\n MENU DE OPCIONES\n");
	    printf(" 1. Anadir una tarea\n");
	    printf(" 2. Ya hiciste una tarea? borrala! \n");
	    printf(" 3. Mostrar tareas del dia\n");
	    printf(" 4. Vaciar cola de tareas\n");
	    printf(" 5. Mostrar tarea que sigue (primera)\n");
	    printf(" 6. Salir\n");
		printf("Ingrese una opcion: \n\n");
		scanf("%d", &op); 
		
        switch(op) {
        	
            case 1:
                 printf("\n Tarea a agregar: ");
                 scanf("%s", &task);                 
                 agregar(c,  task);
                 printf("\n\tTarea %s agregada exitosamente...\n\n", task);
            	 break;
 
 
            case 2:
            	 if(c.delante==NULL) printf("\n\tNo es posible borrar una tarea, porque no has ingresado ninguna!\n\n");
                 else {
				 	eliminar(c);
                 	printf("\n\tFelicidades se elimino esa tarea de la lista. Sigue asi!!\n\n");
				 }
            	 break;
                 
 
            case 3:
                 printf("\n\nMostrando las tareas del dia:\n\n");
                 if(c.delante!=NULL) mostrar(c);
                 else  printf("\tNo tienes tareas. Puedes descansar!!");
                 printf("\n\n");
            	 break;
           
           case 4:
           		 if(c.delante==NULL) printf("\n\tNo es posible vaciar la cola, porque no hay ningun dato!\n\n");
           		 else {
           		 	printf("\n\nVaciando cola de tareas...\n\n");
                 	vaciar(c);
				 }
                 printf("\n\n");
            	 break;
        	
        	case 5:
        		if(c.delante==NULL) printf("\n\tNo es posible mostrar el primero de  la lista, porque no hay ningun dato!\n\n");
        		else frente(c);
        		break;
            	 
            default:
				printf("Introduzca una opcion valida \n");
				printf("\n\n");
				break;
         }
 
        system("pause");  
		system("cls");
 
    }while(op!=6);
   
   
    return 0;
}