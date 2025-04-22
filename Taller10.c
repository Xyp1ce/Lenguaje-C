/*
	Ramon Manriquez
	2210376
	Definicion de matrices dinamicas junto con multiplicaciones
	04/22/2025
*/

#include <stdio.h>
#include <stdlib.h>

// Prototipos
void DefineMatrix(int r, int c, float **m);
void GetMatrix(int r, int c, float **m);
void ShowMatrix(float **m, int r, int c);
void MultMatrix();
void CleanBuffer();

// Constantes

int main(void){
	// Declaracion e Inicializacino de variables	
	int opc = 0;
	float *m1 = NULL, *m2 = NULL;
	int row1 = 0, col1 = 0, row2 = 0, col2 = 0;
	do{
		printf("--Menu--\n");
		printf("[1] Capturar Matriz A [2] Capturar Matriz B [3] Desplegar Matrices\n[4] Multiplicar Matrices [0] Terminar Programa\n");
		printf("Selecciona una opcion\n>> ");
		scanf("%d", &opc);
		CleanBuffer();
		switch(opc){
			case 1: //Matriz A
				// Liberamos memoria en caso de querer hacer una nueva matriz
				free(m1);
				// Pedimos dimensiones de la matriz
				printf("Cuantos renglones tendra la matriz?\n>> ");
				scanf("&d", &row1);
				CleanBuffer();
				printf("Cuantas columnas tendra la matriz?\n>> ");
				scanf("%d", &col1);
				CleanBuffer();
				// Llamamos a la funcion para definir
				DefineMatrix(row1, col1, &m1);
				printf("Matriz A definida\n");
				// Llamamos a la funcion para registrar datos
				GetMatrix(row1, col1, &m1);
				break;
			case 2: //Matriz B
				// Mismo procedimiento que en el case 1
				free(m2);
				printf("Cuantos renglones tendra la matriz?\n>> ");
				scanf("&d", &row2);
				CleanBuffer();
				printf("Cuantas columnas tendra la matriz?\n>> ");
				scanf("%d", &col2);
				CleanBuffer();
				DefineMatrix(row2, col2, &m2);
				printf("Matriz B definida\n");
				break;
			case 3:
				// Mostramos matrices en pantalla
				printf("Matriz A\n");
				ShowMatrix(&m1, row1, col1);
				printf("Matriz B\n");
				ShowMatrix(&m2, row2, col2);
				break;
			case 4:
				MultMatrix();
				break;
			case 0:
				printf("Finalizando programa...\n");
				return 1;
				break;
			default:
				printf("Opcion invalida...\n");
				break;
		}
	}while(opc != 0);

	return 0;
}

// Procedimientos

void DefineMatrix(int r, int c, float **m){
	// Reservamos 3 espacios de memoria para los renglones
	*m = (float*)malloc(r*sizeof(float*));
	// Para cada renglon asignado reservamos 3 columnas inicializados en 0
	for(int i = 0; i < r; i++){
		m[i] = (float*)calloc(c, sizeof(float*));
	}
}
void GetMatrix(int r, int c, float **m){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			printf("m[%d][%d] >> ", i, j);
			scanf("%f", m[i][j]);
		}
	}
}
void ShowMatrix(float **m, int r, int c){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			printf("%f", m[i][j]);
		}
		printf("\n");
	}		
}
void MultMatrix(){}
void CleanBuffer(){
	char c;
	while((c = getchar() ) != '\n' && c != EOF);
}
