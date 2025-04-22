/* 	
	Manriquez Ramon
	2210376	
	13 02 2025
	Switch y bucles bitwise
*/	

#include <stdio.h>

int main(){
	
	// Declaracion e Inicializacion de variables
	unsigned short int num;
	int opc, cont;
	// Mostramos menu al usuario
	printf("\nMenu Bitwise\n\n[1] Imprimir binario\n[2] Imprimir binario invertido\n[3] Terminar Programa\n");
	scanf("%d", &opc);
	// Ciclo while en caso de que la opcion no sea correcta
	while(opc != 1 && opc != 2 && opc != 3){
		printf("Opcion invalida\nPorfavor ingresa una opcion correcta");
		printf("\n[1] Imprimir binario\n[2] Imprimir binario invertido\n[3] Terminar programa\n");
        	scanf("%d", &opc);
	}
	// Ciclo while para repetir el menu siempre y cuando no se seleccione la opcion 3
	while(opc == 1 || opc == 2){
		// Pedimos el numero al usuario
        	//printf("Ingresa un numero\n");
		// Switch del menu
		switch(opc){
			case 1:
				// Imprimir binario
				printf("Opcion 1 - Imprimir binario\n");
				// Pedimos el numero al usuario
        			printf("Ingresa un numero\n");
        			scanf("%u", &num); // %u para pedir un valor tipo unsigned
				cont = 16;
				while(cont >= 0){
					printf("%d", (num&1<<cont) > 0);
					cont --;
				}
				printf("\n");
				break;
			case 2:
				// Imprimir binario invertido
				printf("Opcion 2 - Imprimit binario invertido\n");
				// Pedimos el numero al usuario
        			printf("Ingresa un numero\n");
        			scanf("%u", &num); // %u para pedir un valor tipo unsigned
				cont = 0;
				while(cont <= 16){
					printf("%d", (num&1<<cont) > 0);
					cont ++;
				}
				printf("\n");		
				break;
			default:
				printf("Opcion invalida\n");
				break;
		}
		// Volvemos a preguntar si quiere repetir el menu
		printf("\nMenu Bitwise\n\n[1] Imprimir binario\n[2] Imprimir binario invertido\n[3] Terminar programa\n");
		scanf("%d", &opc);
		// Ciclo while en caso de que la opcion no sea correcta
        	while(opc != 1 && opc != 2 && opc != 3){
                	printf("Opcion invalida\nPorfavor ingresa una opcion correcta");
                	printf("\n[1] Imprimir binario\n[2] Imprimir binario invertido\n[3] Terminar programa\n");
                	scanf("%d", &opc);
	        }
	}
	printf("Terminando Programa\n");
	
	return 0;
}
