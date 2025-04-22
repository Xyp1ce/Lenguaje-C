/*
	Ramon Manriquez
	25 05 2025
	Taller 5 Arrays
*/

#include <stdio.h>

int main(){
	
	// Declaracion e Inicializacion de variables
	float arrayFlotante[6], auxiliar, max, min;
	int opc;
	
	do{

		// Mostramos opciones
        	printf("\nMENU\n\n");
        	printf("[1] CAPTURA ARREGLO [2] DESPLEGAR\n");
        	printf("[3] MAXIMO [4] MINIMO\n");
        	printf("[5] ORDENAR [0] CERRAR PROGRAMA\n");
        	// Ciclo do-while para pedir la opcion del menu
        	do{
                	printf("Ingresa una opcion: ");
                	scanf("%d", &opc);
        	}while(opc != 1 && opc != 2 && opc != 3 && opc != 4 && opc != 5 && opc != 0);

		// Ciclo do-while para el menu mientras que opc != 0
		switch(opc){
			case 1:
				printf("CAPTURAR ARREGLO\n");
				for(int i = 0; i <= 5; i++){
					printf("Posicion %d de 5\n", i);
					scanf("%f", &arrayFlotante[i]); 
				}
				break;
				
			case 2:
				printf("DESPLEGAR ARREGLO\n");
				printf("[");
				for(int i = 0; i <= 5; i++){
					printf("%.2f ", arrayFlotante[i]);
				}
				printf("]\n");
				break;
			case 3:
				printf("MAXIMO\n");
				max = arrayFlotante[0];
				for(int i = 1; i <= 5; i++){
					if(arrayFlotante[i] > max)
						max = arrayFlotante[i];
				}
				printf("El valor maximo es %.2f\n", max);
				break;
	
			case 4:
				printf("MINIMO\n");
				min = arrayFlotante[0];
				for(int i = 1; i <= 5; i++){
                                	if(arrayFlotante[i] < min)
	                                        min = arrayFlotante[i];
        	                }
				printf("El valor minimo es %.2f\n", min);
				break;	
	
			case 5:
				printf("ORDENAR\n");

				for(int i = 0; i < 5; i++) {  // El bucle exterior va hasta 4
    					for(int j = i + 1; j < 6; j++) {  // El bucle interior va de i+1 a 5
        					if(arrayFlotante[i] > arrayFlotante[j]) {
            						auxiliar = arrayFlotante[i];
            						arrayFlotante[i] = arrayFlotante[j];
            						arrayFlotante[j] = auxiliar;
        					}
    					}
				}
                                break;				
			
			case 0:
				printf("SALIENDO\n");
				break;
				
			default:
				printf("OPCION INCORRECTA\n");
				break;
		}
	}while(opc != 0);
	return 0;
}
