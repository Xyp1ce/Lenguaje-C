/*
Ramon Manriquez Guerrero
30 01 2025
Practica 1
Lenguaje C
*/

#include <stdio.h>

int main(){

	// Declaracion de constantes
	const float RADGRAD = 180/3.1416;
	const float GRADRAD = 3.1416/180;
	const float KIMMILL = 1/1.609;
	const float MILLKIM = 1.609;
	const float CENPUL = 1/2.54;
	const float PULCEN = 2.54; 
	
	// Declaracion de variables
	float radianes, grados, kilometros, millas, centimetros, pulgadas;
	
	// Pedimos los valores
	printf("Radianes: ");
	scanf("%f",&radianes);
	printf("Grados: ");	
	scanf("%f",&grados);
	printf("Kilometros: ");	
	scanf("%f",&kilometros);
	printf("Millas: ");
	scanf("%f",&millas);
	printf("Centimetros: ");	
	scanf("%f",&centimetros);
	printf("Pulgadas: ");	
	scanf("%f",&pulgadas);

	// Realizamos conversion de datos
	printf("\n%.2f radianes a grados es: %.2f", radianes, radianes * RADGRAD);
	printf("\n%.2f grados a radianes es: %.2f", grados, grados * GRADRAD);	
	printf("\n%.2f kilometros a millas es: %.2f", kilometros,kilometros * KIMMILL);
	printf("\n%.2f millas a kilometros es: %.2f", millas,millas * MILLKIM);
	printf("\n%.2f centimetros a pulgadas es: %.2f", centimetros,centimetros * CENPUL);
	printf("\n%.2f pulgadas a centimetros es: %.2f\n", pulgadas,pulgadas * PULCEN);
	
	return 0;
}
