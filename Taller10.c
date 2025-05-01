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
void MultMatrix(float ***, float ***, float ***, int, int, int, int);

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
	float **matrixA = NULL, **matrixB = NULL, **matrixC = NULL;
	do{
		printf("\n--Menu--\n\n");
		printf("[1] Capturar Matriz A [3] Desplegar Matrices \n[2] Capturar Matriz B [4] Mutiplicar Matrices \n[0] Terminar programa\n");
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
				MultMatrix(&matrixA, &matrixB, &matrixC, rows1, cols1, rows2, cols2);
				break;
			case 0:
				// Liberacion de memoria
				if(matrixA != NULL){
					for(int i = 0; i < rows1; i++){
						free(matrixA[i]);
					}
					free(matrixA);
					matrixA = NULL;
				}

				if(matrixB != NULL){
					for(int i = 0; i < rows2; i++){
						free(matrixB[i]);
					}
					free(matrixB);
					matrixB = NULL;
				}

				if(matrixC != NULL){
					for(int i = 0; i < rows1; i++){
						free(matrixC[i]);
					}
					free(matrixC);
					matrixC = NULL;
				}
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
	
	if(*matrix != NULL){
		for(int i = 0; i < *rows; i++){
			free((*matrix)[i]);
		}
		free(*matrix);
		*matrix = NULL;
	}

    printf("Renglones >> ");
    scanf("%d", rows);
    CleanBuffer();
    printf("Columnas >> ");
    scanf("%d", cols);
    CleanBuffer();

    // Reservar memoria
    *matrix = (float **)malloc(*rows * sizeof(float *));
    for (int i = 0; i < *rows; i++) 
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

void MultMatrix(float ***matrixA, float ***matrixB, float ***matrixC, int r1, int c1, int r2, int c2){
	/*
		2x4*4x3 Si se puede
		La matriz resultate seria 2x3
	*/
	if(c1 == r2){
		// Reservacion de matriz resultante 
		*matrixC = (float **)malloc(r1 * sizeof(float *));
		for(int i = 0; i < r1; i++){
			(*matrixC)[i] = (float *)calloc(c2, sizeof(float)); 
		}
		// Calculo de la matriz resultante
		for(int i = 0; i < r1; i++){
			for(int j = 0; j < c2; j++){
				for(int k = 0; k < r2; k++){
					(*matrixC)[i][j] += (*matrixA)[i][k] * (*matrixB)[k][j];
				}
			}
		}
		// Despliegue de la matriz resultante
		printf("\nMatriz resultante\n");
		ShowMatrix(*matrixC, r1, c2);
	}else{
		printf("No es posible hacer la multiplicacion...\n");
	}
}