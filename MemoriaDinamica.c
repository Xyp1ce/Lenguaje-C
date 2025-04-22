#include <stdio.h>
// La libreria stdlib es necesaria para la memoria dinamica
#include <stdlib.h>

#define LENGHT 3

void GetData(int *cadena, int lenght);

int main(){
	
	int cadena[LENGHT]; // &cadena[0]
	int longitud;

	// Creamos un apuntador para la memoria dinamica asignando una direccion nula
	int *arregloDinamico = NULL;
	
	printf("Captura la longitud\n");
	scanf("%d", &longitud);

	// calloc() requiere de dos parametros
	// La longitud a reservar y el tamano de bytes del tipo de dato que va a reservar
	// arregloDinamico = (int*)calloc(longitud, sizeof(int));
	// malloc() requiere solo de un parametro
	// La multiplicacion de la longitud deseada por el tamano del tipo de dato
	arregloDinamico = (int*)malloc(longitud*sizeof(int));

	for(int i = 0; i < longitud; i++){
		printf("[%x] Caputra [%d]: ", arregloDinamico+i, i);
		scanf("%d", &arregloDinamico[i]);
	}

	printf("Captura la nueva longitud\n");
	scanf("%d", &longitud);

	// Utilizamos realloc() para aumentar o decrementar el tamano de arregloDinamico
	int *aux;
	aux = NULL;
	while(aux == NULL){
		aux = realloc(arregloDinamico, longitud*sizeof(int));
	}

	arregloDinamico = aux;
	
	for(int i = 0; i < longitud; i++){
		printf("\n [%x] Caputra [%d]: %d\n", arregloDinamico+i, i, arregloDinamico[i]);
	}

	// Liberamos la memorio cuando se deje de usar 
	free(arregloDinamico);

	//GetData(&cadena[0], LENGHT);
	return 0;
}

void GetData(int *cadena, int lenght){
	for(int i = 0; i < lenght; i++){
		printf("Captura %d\n", i);
		scanf("%d", &cadena[i]);
	}	

}
