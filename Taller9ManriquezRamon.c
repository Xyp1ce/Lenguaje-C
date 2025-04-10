#include <stdio.h>
#include <stdlib.h>

// Prototipo reserva de memoria malloc()
void reservar_dos(int longitud, int **ptr);
void mostrar(int *ptr, int longitud);
void capturar(int *ptr, int longitud);
void insertar(int **ptr, int *longitud);
void reducir(int **ptr, int *longitud);

int main(){
	int *dir = NULL;
	int longitud = 5, opc = 0;
	
	do{
		printf("--MENU--\n");
		printf("");

	}while(opc != 0);

	reservar_dos(longitud, &dir);
	capturar(dir, longitud);
	mostrar(dir, longitud);
	insertar(&dir, &longitud);
	mostrar(dir, longitud);
	reducir(&dir, &longitud);
	mostrar(dir, longitud);
	
	free(dir);
	dir = NULL;	
	return 0;
}

void reservar_dos(int longitud, int **ptr){
	*ptr = (int*)malloc(longitud*sizeof(int));
}
void mostrar(int *ptr, int longitud){
	for(int i = 0; i < longitud; i++){
		printf("[%d] %d\n", i, ptr[i]);
	}
}
void capturar(int *ptr, int longitud){
	char c;
	for(int i = 0; i < longitud; i++){
		printf("Captura [%d]\n>> ", i);
		scanf("%d", &ptr[i]);
		while((c = getchar() ) != '\n' && c != EOF); 	
	}
}
void insertar(int **ptr, int *longitud){
	char c;
	(*longitud)++;
	int *aux = NULL;
	while(aux == NULL){
		aux = realloc(*ptr, (*longitud) * sizeof(int));
		*ptr = aux;
	}

	printf("Captura [%d]\n>> ", *longitud-1);
	scanf("%d", *ptr+*longitud-1);
	while((c = getchar() ) != '\n' && c != EOF); 
}
void reducir(int **ptr, int *longitud){
	char c;
	(*longitud)--;
	int *aux = NULL;
	while(aux == NULL){
		aux = realloc(*ptr, (*longitud) * sizeof(int));
		*ptr = aux;
	}
}
