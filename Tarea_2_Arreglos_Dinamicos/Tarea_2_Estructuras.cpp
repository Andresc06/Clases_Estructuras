// Este programa muestra la cantidad de alumnos que quedaron en cuadro de honor con respecto a sus notas del semestre.
// Le pide al usuario el numero de alumnos para luego pedirle las notas de una cantidad n de notas de materias
// Y por ultimo muestra la cantidad de alumnos que quedaron en cuadro de honor, es decir que tuvieron +=17.00 como promedio del semestre


#include<stdio.h>
#include<stdlib.h>

//Variables Generales
int als, *ss, *grs, i, j, cont, ctd_grs, sum;
float avg;

//////Declarando Funciones//////
//Ingresando el numero de estudiantes y creacion del array
void start();

//Obtenida de notas
void notas(int als);



int main () {

	//Llamar a la funcion que pide los numeros del estudiante
	start();
	
	//Llamar a la funcion que hace todo el procedimiento
	notas(als);
	
	//Imprimir la cantidad de estudiantes que quedaron en cuadro de honor
	printf("\nQuedaron %d de %d estudiantes en cuadro de honor.", cont, als);
	return 0;
}

void start() {
	
	printf("Ingrese el numero de estudiantes: \n");
	scanf("%d", &als);
	ss = (int *) malloc(als*sizeof(int));
}

void notas(int als){
	for(i=0; i<als; i++) {
		
		avg = 0;		
		printf("\nIngrese el numero de notas del estudiante %d: \n", i+1);
		scanf("%d", &ctd_grs);
		grs = (int *) malloc(ctd_grs*sizeof(int));
		sum = 0;
		
		for(j=0; j<ctd_grs; j++) {
			printf("\nIngrese la nota %d del estudiante %d: \n", j+1, i+1);
			scanf("%d", &grs[j]);
			sum += grs[j];
		}
		avg = (float)sum/ctd_grs;
		if(avg >= 17) {
			cont++;
		}
		system("cls");
	}
		
}