#include <stdio.h>
#include <stdlib.h>

// Prototipo reserva de memoria malloc()
void CleanBuffer();
void reservar_dos(int longitud, int **ptr);
void mostrar(int *ptr, int longitud);
void capturar(int *ptr, int longitud);
void insertar(int **ptr, int *longitud);
void reducir(int **ptr, int *longitud);
void ordenar(int *ptr, int *longitud);

int main(){
	int *dir = NULL;
	int longitud = 1, opc = 0;
	
	do{
		printf("--MENU--\n");
		printf("[1] Reservar memoria [2] Agregar elemento   [3] Eliminar Ultimo elemento\n");
		printf("[4] Ordenar elemento [5] Desplegar elemento [6] Liberar memoria\n");
		printf("[0] Terminar Programa\nSelecciona una opcion >> ");
		scanf("%d", &opc);

		// Switch case para el menu
		switch(opc){
			case 1: // reservar memoria
				printf("Cuanta memoria desea reservar?\n>> ");
				scanf("%d", &longitud);
				CleanBuffer();
				reservar_dos(longitud, &dir);
				printf("Memoria Reservada\n");
				capturar(dir, longitud);
				break;
			case 2: // Agregar Elemento
				insertar(&dir, &longitud);
				break;
			case 3: // Eliminar Ultimo Elemento
				reducir(&dir, &longitud);
				break;
			case 4: // Ordenar Elemento
				ordenar(dir, &longitud);
				break;
			case 5: // Desplegar Elemento
				mostrar(dir, longitud);
				break;
			case 6: // Liberar Memoria
				if(dir == NULL){
					printf("La memoria ya esta liberada\n");
				}else{
					free(dir);
					dir = NULL;
					printf("Memoria liberada\n");	
				}
				break;
			case 0: // Salir
				printf("Finalizando programa...\n");
				return 0;
				break;
			default: // Invalido
				printf("Opcion invalida...\n");
				break;	
		}
	}while(opc != 0);

	
	return 0;
}

void CleanBuffer(){
	char c;
	while((c = getchar() ) != '\n' && c != EOF); 	
}

void reservar_dos(int longitud, int **ptr){
	*ptr = (int*)calloc(longitud,sizeof(int));
}
void mostrar(int *ptr, int longitud){
	for(int i = 0; i < longitud; i++){
		printf("[%d] %d\n", i, ptr[i]);
	}
}
void capturar(int *ptr, int longitud){
	for(int i = 0; i < longitud; i++){
		printf("Captura [%d]\n>> ", i);
		scanf("%d", &ptr[i]);
		CleanBuffer();
	}
}
void insertar(int **ptr, int *longitud){
	(*longitud)++;
	int *aux = NULL;
	while(aux == NULL){
		aux = realloc(*ptr, (*longitud) * sizeof(int));
		*ptr = aux;
	}

	printf("Captura [%d]\n>> ", *longitud-1);
	scanf("%d", *ptr+*longitud-1);
	CleanBuffer();
}
void reducir(int **ptr, int *longitud){
	char c;
	if((*longitud) == 0){
		printf("No se puede reducir la memoria\n");
	}else{
		(*longitud)--;
		int *aux = NULL;
		while(aux == NULL){
			aux = realloc(*ptr, (*longitud) * sizeof(int));
			*ptr = aux;
		}
	}
	
}
void ordenar(int *ptr, int *longitud){
	int aux = 0;
	int ordenado = 0;
	// Bubble Sort
	while(ordenado == 0){
		ordenado = 1;
		for(int i = 0; i < *longitud - 1; i++){	
			if(ptr[i] > ptr [i+1]){
				aux = ptr[i];
				ptr[i] = ptr[i+1];
				ptr[i+1] = aux;	
				ordenado = 0;
			}
		}
	}

}
