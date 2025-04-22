/* 
	Ramon Manriquez 
	6 02 2025
	bitwiseP2
*/

#include <stdio.h>

int main(){
	
	// Declaracion de constantes
	#define BIT_7 1<<7
	#define BIT_6 1<<6
	#define BIT_5 1<<5
	#define BIT_4 1<<4
	#define BIT_3 1<<3
	#define BIT_2 1<<2
	#define BIT_1 1<<1
	#define BIT_0 1<<0

	// Declaracion e Inicializacion de varibales
	unsigned char numeroChar;
	int contador = 0, numero;
	
	// Pedimos datos al usuario
	printf("Ingresa un numero (hexadecimal):\n");
	scanf("%x", &numero);
	printf("Numero decimal: %d\n", numero); 
	numeroChar = numero;

	contador += ((numeroChar & BIT_7) >> 7);
	contador += ((numeroChar & BIT_6) >> 6);
	contador += ((numeroChar & BIT_5) >> 5);
	contador += ((numeroChar & BIT_4) >> 4);
	contador += ((numeroChar & BIT_3) >> 3);
	contador += ((numeroChar & BIT_2) >> 2);
	contador += ((numeroChar & BIT_1) >> 1);
	contador += ((numeroChar & BIT_0) >> 0);
	
	printf("%d\n", contador);
	
	return 0;
}
