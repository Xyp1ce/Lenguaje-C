/* 
	Manriquez Ramon
	2210376
	20 02 2025
	Rango calificaciones
*/

#include <stdio.h>

int main(){
	// Declaracion e inicializacino de variables
	int opc, cursos;
	float calf, max, min, prom;
	char calfLetra[5];

	// ciclo do-while para el menu
	do{
		printf("[1] EVALUAR DESEMPENO [2] SALIR\n");
		scanf("%d", &opc);

		// Switch-case para las opciones
		switch(opc){
			case 1:
				// Reiniciamos la variable prom a 0 cada que entremos a la primera opcion
				float prom = 0;
				printf("Evaluar desempeno\n");
				printf("Cuantos cursos desea evaluar?\n");			
				scanf("%d", &cursos);
				printf("Ingresa la calificacion del curso 1: ");
				scanf("%f", &calf);
				while(calf < 0 || calf > 100){
					printf("RANGO NO VALIDO 0 - 100\n");
                                        scanf("%f", &calf);
                                 }
				// Asignamos las variables max y min para comparar posteriormente
				max = calf; 
				min = calf;
				prom = prom + calf;
			
				// Ciclo for para pedir todas las calificaciones de los cursos
				for(int i = 2; i <= cursos; i++){
					printf("Ingresa la calificacion del curso %d: ", i);
					scanf("%f", &calf);
					// While para comprobar el rango de calificacion
					while(calf < 0 || calf > 100){
						printf("RANGO NO VALIDO 0 - 100\n");
						scanf("%f", &calf); 
					}	
					// Condicional if para reasignar max o min
					if(calf > max)
						max = calf;
					else if(calf < min)
						min = calf;
					prom = prom + calf;
				}
				
				//Calculamos el promedio dividiendo entre la cantidad de cursos
				prom = prom / cursos;
				
				// if-else para asignar a la variables calfLetra su respectiva calificacion
				if(prom >= 93)
					sprintf(calfLetra, "A");
				else if(prom <= 92.99 && prom >= 90)
					sprintf(calfLetra, "A-");
				else if(prom <= 89.99 && prom >= 87)
                                        sprintf(calfLetra, "B+");
				else if(prom <= 86.99 && prom >= 83)
                                        sprintf(calfLetra, "B");
				else if(prom <= 82.99 && prom >= 80)
                                        sprintf(calfLetra, "B-");
				else if(prom <= 79.99 && prom >= 77)
                                        sprintf(calfLetra, "C+");
				else if(prom <= 76.99 && prom >= 73)
                                        sprintf(calfLetra, "C");
				else if(prom <= 72.99 && prom >= 70)
                                        sprintf(calfLetra, "C-");
				else if(prom <= 69.99 && prom >= 67)
                                        sprintf(calfLetra, "D+");
				else if(prom <= 66.99 && prom >= 60)
                                        sprintf(calfLetra, "D");
				else
					sprintf(calfLetra, "F");
				
				printf("La calificacino maxima es %.2f y la minima es %.2f\n", max, min);
				printf("Con un promedio de %.2f %s\n", prom, calfLetra);
				break;
			case 2:
				printf("Saliendo del programa\n");
				break;
			default:
				printf("OPCION INVALIDA\n");
				break;
		}

	}while(opc != 2);

	return 0;
}
