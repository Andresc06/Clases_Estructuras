#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Nodo {
	int dato;
	struct Nodo* siguiente;
} Nodo;


typedef struct Lista {
	Nodo* cabeza;
	int longitud;
} Lista;


struct Lista* crearl(){
	struct Lista* lista = (struct Lista*) malloc(sizeof(struct Lista));
	lista->cabeza = NULL;
	lista->longitud = 0;
	return lista;
}

Nodo* CrearNodo(int dato){
	Nodo* nodo = (Nodo*) malloc (sizeof (Nodo));
	nodo->dato=dato;
	nodo->siguiente=NULL;
	return nodo;
}

void insPrincipio(Lista* lista, int dato){
	Nodo* nodo = CrearNodo(dato);
	nodo->siguiente = lista->cabeza;
	lista->cabeza = nodo;
	lista->longitud++;
}

void insFinal(Lista* lista, int dato){
	
	Nodo*nodo = CrearNodo(dato);
	if (lista->cabeza == NULL) {
		lista->cabeza = nodo;
	} 
	
	else {
		Nodo* puntero = lista->cabeza;
		while (puntero->siguiente){
			puntero = puntero->siguiente;	
		}
		puntero->siguiente = nodo;
	}
	lista->longitud++;
}


void insEnN(int n, Lista* lista, int dato){
	n = n-1;
	Nodo* nodo = CrearNodo(dato);
	if (lista->cabeza == NULL) {
		lista->cabeza == nodo;
	} 
	
	else {
		Nodo* puntero = lista->cabeza;
		int posicion = 0;
	
		while (posicion < n && puntero->siguiente){
			puntero = puntero->siguiente;
			posicion++;
		} 
		
		if (posicion != n){
			printf ("\n Ningun dato es encontrado\n La cedula del estudiante se agregara al final de la lista \n");
		}
		nodo->siguiente = puntero->siguiente;
		puntero->siguiente = nodo;
	}
	lista->longitud++;
}



void Obtener(int n, Lista* lista){
	if (lista->cabeza == NULL){
		printf ("\n La lista esta vacia \n");
	} else {
			Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while (puntero->siguiente && puntero->dato != n){
			puntero = puntero->siguiente;
			posicion++;
		}
		printf ("\n La CI si coincide con unos de los estudiantes, y esta de puesto %d\n", posicion+1);
		if (posicion != n){
			printf ("\n No hay ningun estudiante con esta CI\n");
		}
	}
}

void DeletePrincipio(Lista* lista){
	if(lista->cabeza){
	Nodo* eliminado = lista->cabeza;
	lista->cabeza = lista->cabeza->siguiente;
	delete(eliminado);
	lista->longitud--;
	printf ("Se ha eliminado la cedula del estudiante exitosamente\n");
}  else {
	printf("\n La lista esta vacia \n");
	}
	lista->longitud--;
}


void DeleteUltimo(Lista* lista){
	if(lista->cabeza){
		if(lista->cabeza->siguiente) {
		
		Nodo* puntero = lista->cabeza;
		while (puntero->siguiente->siguiente){
			puntero = puntero->siguiente;
		}
		Nodo* eliminado = puntero->siguiente;
		puntero->siguiente=NULL;
		delete(eliminado);
		lista->longitud--;
		printf ("Se elimino la cedula del estudiante con exito\n");
	} else {
		Nodo* eliminado = lista->cabeza;
		lista->cabeza = NULL;
		delete(eliminado);
		lista->longitud--;
		printf ("Se elimino la cedula del estudiante con exito\n");
	}
	} else{
		printf ("\n La lista esta vacia \n");
	}
	lista->longitud--;
}


void DeleteEnN(int n, Lista* lista){
	if (lista->cabeza) {
		if (n == 0) {
			Nodo* eliminado = lista->cabeza;
			lista->cabeza = lista->cabeza->siguiente;
			delete(eliminado);
			lista->longitud--;
			printf ("Se ha eliminado la cedula del estudiante en la posicion solicitada\n");
		} 
		
		else if (n < lista->longitud) {
			Nodo* puntero = lista->cabeza;
			int posicion = 0;
			while(posicion < (n - 1)) {
				puntero = puntero->siguiente;
				posicion++;
			}
			Nodo* eliminado = puntero->siguiente;
			puntero->siguiente = eliminado->siguiente;
			delete(eliminado);
			lista->longitud--;	
			printf ("Se ha eliminado la cedula del estudiante en la posicion solicitada\n");
		}
		
		else{
			printf("\n No hay ningun dato en esta posicion \n");
		}
	}
	lista->longitud--;
}


void MostrarLista(Lista* lista){
	if (lista->cabeza == NULL){
		printf("\n La lista se encuentra vacia \n");
	} else {
		Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while (posicion < lista->longitud){
			printf("- %d -", puntero->dato);
			puntero = puntero->siguiente;
			posicion++;
		}
		printf("\n\n");
	}
}

int longitud(Lista* lista) {
	return lista->longitud;
}


int main(){
	
	struct Lista* l = crearl();
	int repetidor = true;
	int opcion;
	int dato;
	int n;
	do{
	
	printf ("MENU DE OPCIONES: \n\n");
	printf ("1 Agregar la CI de un estudiante al principio\n");
	printf ("2 Agregar la CI de un estudiante al final\n");
	printf ("3 Agregar la CI de un estudiante en una posicion 'n'\n");
	printf ("4 Eliminar la CI de un estudiante al principio\n");
	printf ("5 Eliminar la CI de un estudiante al final\n");
	printf ("6 Eliminar la CI de un estudiante en una posicion 'n'\n");
	printf ("7 Encontrar posicion de una CI de un estudiante\n");
	printf ("8 Mostrar la lista de CI\n");
	printf ("9 Salir\n\n");
	scanf ("%d", &opcion);
	switch (opcion){
		case 1: 
			printf ("\nIntroduzca la cedula del estudiante para agregar al principio\n");
			scanf ("%d", &dato);
			insPrincipio(l,dato);
			break;
		case 2: 
			printf ("\nIntroduzca la cedula del estudiante para agregar al final\n");
			scanf ("%d", &dato);
			insFinal(l,dato);
			break;
		case 3:
			printf ("\nIntroduzca la cedula del estudiante\n");
			scanf ("%d", &dato);
			printf("Introduzca la posicion\n");
			scanf ("%d", &n);
			insEnN(n-1,l,dato);
			break;
		case 4:
			DeletePrincipio(l);
			break;
		case 5:
			DeleteUltimo(l);
			break;
		case 6: 
			printf("Introduzca la posicion\n");
			scanf ("%d", &n);
			DeleteEnN (n-1,l);
			break;
		case 7:
			printf("Introduzca la CI que desea buscar\n");
			scanf ("%d", &n);
			Obtener(n-1,l);
			break;
		case 8:
			MostrarLista(l);
			break;
		default:
			printf("Introduzca una opcion validad \n");
			break;
	}
	system("pause");
	system ("cls");
}while(opcion!=9);
	return 0;
}