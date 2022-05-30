// Ejercicio para sacar el promedio de un determinado numero de notas de una materia usando la implementacion de los arreglos dinamicos

#include <iostream>

int main() {
	
	int suma, n;
	float prom;
	int *p;
	
	printf("Ingrese la cantidad de notas: ");
	scanf("%d", &n);
	p = new int[n]; // Aqui se asigna memoria a un arreglo de n elementos
	
	for( int i = 0; i < n; i++) {
		printf("\nIngresa el elemento %d: ", i+1);
		scanf("%d", &p[i]);
		suma += p[i];
	}
	prom = (float)suma / n;
	printf("\nEl promedio de notas es: %.2f", prom);
	delete []p;
	return 0;
}