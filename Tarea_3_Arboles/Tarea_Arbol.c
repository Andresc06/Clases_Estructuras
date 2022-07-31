#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//Estructura del nodo
struct nodo{
 struct nodo *padre;
 struct nodo *izq;
 struct nodo *der;
 int valor;
};

struct nodo *crear_nodo(struct nodo *padre, int valor);
void agregar_valor(struct nodo *arbol, int valor);
void inOrder(struct nodo *arbol);

int main(){
//Creamos el arbol vacio
 struct nodo *arbol = calloc(sizeof(struct nodo),1);
 arbol->padre = NULL;
 arbol->valor = NULL;
 //menu
	int opcion;
	int n; 
	do {
		printf ("Elija una opcion: \n");
		printf ("1) Agregar un nodo al arbol. \n");
		printf ("2) Recorrer arbol de forma creciente\n");
		printf ("3) Salir \n");
		scanf("%d", &opcion);
		switch (opcion){
		 	case 1:
				printf("Introduzca el valor a ingresar al arbol \n");
				scanf("%d", &n);
				agregar_valor(arbol, n);
				system("pause");
				system ("cls");	
				break;
			case 2:
				inOrder(arbol);
				system("pause");
				system ("cls");	
				break;
			default:
				printf("Introduzca una opcion valida \n");
				system("pause");
				system ("cls");	
				break;
		}
	} while(opcion != 3);
 
 return 0;
}

// Funcion de creacion de nodo
struct nodo *crear_nodo(struct nodo *padre, int valor){
 struct nodo *n = calloc(sizeof(struct nodo),1);
 n->padre = padre;
 n->valor = valor;
 return n;
}

// Funcion de agregar un valor
void agregar_valor(struct nodo *arbol, int valor){
	
	if (!arbol->valor){
		printf("Se ha insertado %i como la raiz del arbol\n", valor);
		arbol->valor = valor;
	}
	
	else {
	 struct nodo *aux, *piv;
	 int right = 0;
	
	  aux = arbol;
	  while(aux !=NULL){
	   piv = aux;
	   if(valor>aux->valor){
	    aux = aux->der;  
	    right = 1;    
	   }
	   else{
	    aux = aux->izq;
	    right = 0;
	   }
  }
  aux = crear_nodo(piv,valor);
  if(right){
   printf("Insertando %i el lado derecho de %i\n",valor,piv->valor); 
   piv->der = aux;
  }else{
   printf("Insertando %i el lado izquierdo de %i\n",valor,piv->valor);
   piv->izq = aux;
  }

	}
}

//Recorrido
void inOrder(struct nodo *arbol){
	
	if (arbol != NULL)
    {
        inOrder(arbol->izq);
        printf("[ %d ] -\n", arbol->valor);
        inOrder(arbol->der);
    }
}
	
