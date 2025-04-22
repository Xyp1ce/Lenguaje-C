/*
	Manriquez Ramon
	2210376
	Practica 4
*/

#include <stdio.h>

int main(){
	
	// Declaracion e Inicializacion de variables
	int array1[6], array2[6], opc;

	// do-while para repeticion del menu
	do{
		printf("[1] Capturar Arreglo\n[2] Mostrar Duplicados\n[3] Comunes\n[0] Terminar Programa\n> ");
		scanf("%d", &opc);
		
		switch(opc){ // switch-case para las opciones
			case 1: // CAPTURAR ARREGLO
				// Pedimos los valores del primer arreglos
				printf("\nPrimer arreglo\n");
				for(int i = 0; i < 6; i++){ 
					printf("array1[%d] = ", i);
					scanf("%d", &array1[i]);
				}
				// Pedimos los valores del segundo arreglo
				printf("\nSegundo arreglo\n");
				for(int i = 0; i < 6; i++){
                                        printf("array2[%d] = ", i);
                                        scanf("%d", &array2[i]);
                                }
				printf("\n");
				break;
			case 2: // MOSTRAR DUPLICADOS
				printf("\nPrimer arreglo\n");
				int arrayAux[6] = {0};
				int cont = 0;
				for(int i = 0; i < 6; i++){
					int dupl = 1; // Generamos variable para almacenar cuantas veces se repite i
					for(int j = i + 1; j < 6; j++){
						if(array1[i] == array1[j]){
							dupl++;
							arrayAux[i] = array2[i];
						}
					}
					if(dupl >= 2 && cont < 1){
						cont++;
						printf("%d se repite %d veces\n", array1[i], dupl);
					}
				}	
				printf("\nSegundo arreglo\n");
                                for(int i = 0; i < 6; i++){
                                        int dupl = 1; // Generamos variable para almacenar cuantas veces se repite i
                                        for(int j = i + 1; j < 6; j++){
                                                if(array2[i] == array2[j]){
                                                        dupl++;
							arrayAux[i] = array2[i];
						}	
                                        }
                                        if(dupl >= 2 && cont < 1){
                                		cont++;                
						printf("%d se repite %d veces\n", array2[i], dupl);
					}
                                }
				printf("\n");
				break;
			case 3: // COMUNES
				printf("\nDatos Comunes\n");
				int arrayRegistro1[6] = {0};
				for(int i = 0; i < 6; i++){
					for(int j = 0; j < 6; j++){
						if(array1[i] == array2[j]){
							arrayRegistro1[i] = array1[i];
						}
					}		
				}
				for(int i = 0; i < 6; i++){
					if(arrayRegistro1[i] > 0)
						printf("%d ", arrayRegistro1[i]);
				}
				printf("\n");
				break;
			case 0: // TERMINAR PROGRAMA
				printf("SALIENDO\n");
				break;
			default:
				printf("OPCION INVALIDA\n");
				break;
		}

	}while(opc != 0);
	
	return 0;
}
