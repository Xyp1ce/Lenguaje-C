/*
 * Manriquez Ramon
 * 2210376
 * Mediante apuntadores y funciones
 * Capturar matriz, matriz a ceros, imprimir matriz, elemento maximo, multiplicacion de matrices
*/

#include <stdio.h>
// Librerias para llenar la matriz de manera aleatoria, para ahorrar tiempo
#include <time.h>
#include <stdlib.h>

// Declaracion de constantes
#define ROWS 100
#define COLUMNS 100
 
// Prototipos 
int Random();
void ClearInput();
void GetMatrix(int *, int, int);
void MatrixZero(int *, int, int);
void ShowMatrix(int *, int, int);
int MatrixMax(int *, int, int);
void MatrixMult(int*, int*, int*, int, int);

// Definicion de matriz global 

int main(){
    // Semilla del programa
    srand(time(NULL));
    
    // Declaracion e Inicializaciona de variables
    int rows = 0, columns = 0, opc = 0;
	int matrix[ROWS][COLUMNS];
	int matrixa[ROWS][COLUMNS];
	int matrixb[ROWS][COLUMNS];    
    // Definimos la matriz
    /*printf("De cuantos renglones sera la matriz?\n>> ");
    scanf("%d", &rows);
    ClearInput();
    printf("De cuantas columnas sera la matriz?\n>> ");
    scanf("%d", &columns);
    ClearInput()
    
    
    if(rows > ROWS || columns > COLUMNS){
        printf("El tamaño excede el limite de 100 x 100");
        return 1;
    }
    
    GetMatrix(*matrix, rows, columns);
    */ 
    do{
        
        printf("\n--Elige una opcion--\n[1] Capturar Matrix \n[2] Matriz Ceros \n[3] Imprimir Matriz \n[4] Elemento Maximo \n[5] Multiplicacion \n[0] Salir\n>> ");
        scanf("%d", &opc);
        ClearInput();
        
        switch(opc){
                case 1: // Caputrar Matrix
                    printf("Desea definir una nueva matriz [1] SI [2] NO(actualmente hay una de %d x %d)\n>> ", rows, columns);
                    scanf("%d", &opc); 
                    ClearInput();
                    if(opc == 1){
                        printf("De cuantos renglones sera la matriz?\n>> ");
                        scanf("%d", &rows);
                        ClearInput();
                        printf("De cuantas columnas sera la matriz?\n>> ");
                        scanf("%d", &columns);
                        ClearInput();
                        
                        if(rows > ROWS || columns > COLUMNS){
                            printf("El tamaño excede el limite de 100 x 100");
                            return 1;
                        }
                        
                        GetMatrix(*matrix, rows, columns);
                    }
                break;
            case 2: // Matriz Ceros
                MatrixZero(*matrix, rows, columns);
                break;
            case 3: // Mostrar Matriz
                ShowMatrix(*matrix, rows, columns);
                break;
            case 4: // Valor maximo en matrix
                MatrixMax(*matrix, rows, columns);
                printf("El valor maximo es %d\n", MatrixMax(*matrix, rows, columns));
                break;
            case 5: // Multiplicacion de matrices
                // Primera matriz
                printf("De cuantos renglones seran la matrices?\n>> ");
                scanf("%d", &rows);
                ClearInput();
                printf("De cuantas columnas seran la matrices?\n>> ");
                scanf("%d", &columns);
                ClearInput();
                
                if(rows > ROWS || columns > COLUMNS){
                    printf("El tamaño excede el limite de 100 x 100");
                    return 1;
                }
                
                GetMatrix(*matrix, rows, columns);
                GetMatrix(*matrixa, rows, columns);
                MatrixZero(*matrixb, rows, columns);
                printf("Matriz A\n");
                ShowMatrix(*matrix, rows, columns);
                printf("Matriz B\n");
                ShowMatrix(*matrixa, rows, columns);
                
                MatrixMult(*matrix, *matrixa, *matrixb, rows, columns);
                printf("Matriz Resultante\n");
                ShowMatrix(*matrixb, rows, columns);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                return 2;
                break;
            default:
                printf("Opcion invalida...\n");
                break;
        }
    }while(opc != 0);
    return 0;
}

// Procedimientos
int Random(){
    int n = rand()%10 + 1;
    return n;
}
void ClearInput(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {} // Limpiar buffer de entrada
}
void GetMatrix(int *matrix, int rows, int columns){
    int opc;
    printf("Desea un llenado manual o aleatorio? [1] Manual [2] Aleatorio\n>> ");
    scanf("%d", &opc);
    ClearInput();
    if(opc == 1){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                printf("Ingresa la posicion %d de la matriz\n>> ", i * columns + j);
                scanf("%d", &matrix[i * columns + j]);
            }
        }
    }else{
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                matrix[i * columns + j] = Random();
            }
        }
    }
    
}
void MatrixZero(int *matrix, int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrix[i * columns + j] = 0;
        }
    }
}
void ShowMatrix(int *matrix, int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("%4d", matrix[i * columns + j]);
        }
        printf("\n");
    }
}
int MatrixMax(int *matrix, int rows, int columns){
    int max = matrix[0];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(matrix[i * columns + j] > max){
                max = matrix[i * columns + j];
                
            }
        }
    }
    return max;
}
void MatrixMult(int *matrix, int *matrixa, int *matrixb, int rows, int columns){
    int acum = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            for(int k = 0; k < columns; k++){
               acum = acum + (matrix[i * columns + k] * matrixa[k * columns + j]);
            }  
            matrixb[i * columns + j] = acum;
            acum = 0;
        }
    }
}
