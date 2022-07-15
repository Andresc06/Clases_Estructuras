#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMO 50

typedef struct Nodo {
	int ci;
	char carrera[MAXIMO];
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

Nodo* CrearNodo(int ci, char *carrera){
	Nodo* nodo = (Nodo*) malloc (sizeof (Nodo));
	nodo->ci=ci;
	strcpy(nodo->carrera, carrera);
	nodo->siguiente=NULL;
	return nodo;
}

void insPrincipio(Lista* lista, int ci, char *carrera){
	Nodo* nodo = CrearNodo(ci, carrera);
	nodo->siguiente = lista->cabeza;
	lista->cabeza = nodo;
	lista->longitud++;
}

void insFinal(Lista* lista, int ci, char *carrera){
	
	Nodo*nodo = CrearNodo(ci, carrera);
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


void insEnN(int n, Lista* lista, int ci, char *carrera){
	n = n-1;
	Nodo* nodo = CrearNodo(ci, carrera);
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



void Obtener(int ci, Lista* lista){
	if (lista->cabeza == NULL){
		printf ("\n La lista esta vacia \n");
	} 
	else {
		Nodo* puntero = lista->cabeza;
		int i = 0;
		while (puntero->siguiente && puntero->ci != ci){
			puntero = puntero->siguiente;
			i++;
		}	
		if (puntero->ci == ci){
			printf ("\n La CI %d si coincide con unos de los estudiantes, esta en la posicion %d y este estudia %s\n", puntero->ci, i+1, puntero->carrera);
		}
		else {
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
	printf ("Se ha eliminado el primer estudiante exitosamente del registro\n");
	}  
	else {
	printf("\n La lista esta vacia \n");
	}
	
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
		printf ("Se elimino el ultimo estudiante con exito\n");
		} 
		
		else {
		Nodo* eliminado = lista->cabeza;
		lista->cabeza = NULL;
		delete(eliminado);
		lista->longitud--;
		printf ("\nSe elimino el ultimo estudiante con exito\n");
		}
	} 
	
	else{
		printf ("\n La lista esta vacia \n");
	}
}


void DeleteEnN(int n, Lista* lista){
	if (lista->cabeza) {
		if (n == 0) {
			Nodo* eliminado = lista->cabeza;
			lista->cabeza = lista->cabeza->siguiente;
			delete(eliminado);
			lista->longitud--;
			printf ("\nSe ha eliminado el estudiante en la posicion solicitada\n");
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
			printf ("\nSe ha eliminado el estudiante en la posicion solicitada\n");
		}
		
		else{
			printf("\n No hay ningun dato en esta posicion \n");
		}
	}
}


void MostrarLista(Lista* lista){
	if (lista->cabeza == NULL){
		printf("\n La lista se encuentra vacia \n");
	} 
	else {
		Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while (posicion < lista->longitud){
			printf("- [%d] %s -", puntero->ci, puntero->carrera);
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
	int ci;
	char carrera[MAXIMO];
	int n;
	do{
	
	printf ("REGISTRO DE ESTUDIANTES: \n\n");
	printf ("1 Agregar a un estudiante al principio\n");
	printf ("2 Agregar a un estudiante al final\n");
	printf ("3 Agregar a un estudiante en una posicion 'n'\n");
	printf ("4 Eliminar a un estudiante al principio\n");
	printf ("5 Eliminar a un estudiante al final\n");	
	printf ("6 Eliminar a un estudiante en una posicion 'n'\n");
	printf ("7 Encontrar carrera y posicion un estudiante en la lista\n");
	printf ("8 Mostrar la lista de estudiantes\n");
	printf ("9 Cantidad de estudiantes en el registro\n");
	printf ("10 Salir\n\n");
	scanf ("%d", &opcion);
	switch (opcion){
		case 1: 
			printf ("\nIntroduzca la cedula del estudiante para agregar al principio\n");
			scanf ("%d", &ci);
			printf ("\nIntroduzca la carrera de dicho estudiante\n");
			scanf ("%s", &carrera);
			insPrincipio(l,ci, carrera);
			break;
		case 2: 
			printf ("\nIntroduzca la cedula del estudiante para agregar al final\n");
			scanf ("%d", &ci);
			printf ("\nIntroduzca la carrera de dicho estudiante\n");
			scanf ("%s", &carrera);
			insFinal(l,ci, carrera);
			break;
		case 3:
			printf ("\nIntroduzca la cedula del estudiante\n");
			scanf ("%d", &ci);
			printf ("\nIntroduzca la carrera de dicho estudiante\n");
			scanf ("%s", &carrera);
			printf("\nIntroduzca la posicion\n");
			scanf ("%d", &n);
			insEnN(n-1,l,ci,carrera);
			break;
		case 4:
			DeletePrincipio(l);
			break;
		case 5:
			DeleteUltimo(l);
			break;
		case 6: 
			printf("\nIntroduzca la posicion\n");
			scanf ("%d", &n);
			DeleteEnN (n-1,l);
			break;
		case 7:
			printf("\nIntroduzca la CI del estudiante para obtener su carrera\n");
			scanf ("%d", &ci);
			Obtener(ci,l);
			break;
		case 8:
			MostrarLista(l);
			break;
		case 9:
			longitud(l);
			printf("\nLa lista hasta ahora tiene %d registros\n", l->longitud);
		default:
			printf("\nIntroduzca un valor valido\n");
			break;
	}                      
	system("pause");
	system ("cls");
}while(opcion!=10);
	return 0;
}