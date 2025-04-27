/*
	Ramon Manriquez Guerrero 
	2210376
	Matrices dinamicas y multiplicacino de matrices
*/

#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones
void CleanBuffer();
int Menu();
void StartMatrix(float ***, int *, int *);
void GetMatrix(float ***, int *, int *);
void ShowMatrix(float **, int , int );

int main(void){
	// Llamada al menu del programa
	Menu();
	return 0; // Finalizacion del programa
}

// Procedimientos
int Menu(){
	int opc = 0;
	int rows1 = 0, cols1 = 0;
	int rows2 = 0, cols2 = 0;
	float **matrixA = NULL, **matrixB = NULL;
	do{
		printf("--Menu--\n");
		printf("[1] Capturar Matriz A [2] Caputrar Matriz B \n[3] Desplegar Matices [4] Mutiplicar Matrices \n[0] Terminar programa\n");
		printf("Selecciona una opcion.\n>> ");
		scanf("%d", &opc);
		CleanBuffer();
		switch(opc){
			case 1: // Matriz A
				printf("\nMatriz A\n");
				StartMatrix(&matrixA, &rows1, &cols1);
				GetMatrix(&matrixA, &rows1, &cols1);
				break;
			case 2: // Matriz B
				printf("\nMatriz B\n");
				StartMatrix(&matrixB, &rows2, &cols2);
				GetMatrix(&matrixB, &rows2, &cols2);
				break;
			case 3: // Despliegue
				printf("\nMatriz A\n");
				ShowMatrix(matrixA, rows1, cols1);
				printf("\nMatriz B\n");
				ShowMatrix(matrixB, rows2, cols2);
				break;
			case 4:
				break;
			case 0:
				printf("Finalizando programa...\n");
				break;
			default:
				printf("Opcion invalida...\n");
				break;
		}
	}while(opc != 0);

	return 0;
	
}
void CleanBuffer(){
	char c;
    while ((c = getchar()) != '\n' && c != EOF) {} // Limpiar buffer de entrada
}

void StartMatrix(float ***matrix, int *rows, int *cols){
	
    printf("Renglones >> ");
    scanf("%d", rows);
    CleanBuffer();
    printf("Columnas >> ");
    scanf("%d", cols);
    CleanBuffer();

    // Reservar memoria
    *matrix = (float **)malloc(*rows * sizeof(float *));
    for (int i = 0; i < *rows; i++) // aquí debe ser 'rows', no 'cols'
        (*matrix)[i] = (float *)calloc(*cols, sizeof(float));
}

void GetMatrix(float ***matrix, int *rows, int *cols){
	for (int i = 0; i < (*rows); i++){
        for (int j = 0; j < (*cols); j++){
            printf("Matrix[%d][%d] >> ", i, j);
            scanf("%f", &(*matrix)[i][j]);
        }
    }
}

void ShowMatrix(float **matrix, int rows, int cols){
	if (matrix == NULL){
		printf("Matriz no capturada\n");
		return;
	}
	for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%3.1f ", matrix[i][j]);
        }
        printf("\n");
    }
}