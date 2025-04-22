#include <stdio.h>

// Declaracion de constantes
#define X 3
#define Y 3
#define VOCAL 10
#define NUMEROS 10
#define CONSONANTE 42
#define ESPECIALES 33
#define LONGITUD 256

int main(){
    
    // Ejercicio Matriz
    
    //Declaracion e Inicializacion de variables
    double a[X][Y] = {{1,2,3},{4,5,6},{7,8,9}};
    double b[X][Y] = {{7,4,1},{8,5,2},{9,6,3}};
    double c[X][Y] = {0};
    
    // Iteracion entre matrices
    for(int i = 0; i < X; i++){
        for(int j = 0; j < X; j++){
            for(int k = 0; k < Y; k++){
                c[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
    
    printf("Matriz C = A * B:\n");
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            printf("%5.0lf ", c[i][j]); 
        }
        printf("\n");
    }
    
    // Ejercicio Caracteres
    
    // Declaracion e inicializacion de varibles
    char cadena[LONGITUD];
    char vocalArray[VOCAL] = {'a','e','i','o','u', 'A', 'E', 'I', 'O', 'U'};
    char consonanteArray[CONSONANTE] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z',
    'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z'};
    char numerosArray[NUMEROS] = {'0','1','2','3','4','5','6','7','8','9'};
    char caracteresEspecialesArray[ESPECIALES] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[', ']', '{', '}', ';',    ':', '\'', '\"', ',', '.', '<', '>', '/', '?', '\\', '|', '`', '~', ' '};
    int vocal = 0, consonante = 0, numerico = 0, otro = 0, carac = 0;
    
    printf("\nCaptura una cadena: \n");
    fgets(cadena, LONGITUD, stdin);
    printf("La cadena ingresada es %s\n", cadena);
    
    for(int i = 0; i < LONGITUD; i++){
        if(cadena[i] != '\0')
            carac++;
        else
            break;
    }
    
    for(int i = 0; i < carac; i++){
        for(int j = 0; j < VOCAL; j++){
            if(cadena[i] == vocalArray[j])
                vocal++;
        } 
        for(int j = 0; j < CONSONANTE; j++){
            if(cadena[i] == consonanteArray[j])
                consonante++;
        } 
        for(int j = 0; j < NUMEROS; j++){
            if(cadena[i] == numerosArray[j])
                numerico++;
        }
        for(int j = 0; j < NUMEROS; j++){
            if(cadena[i] == caracteresEspecialesArray[j])
                otro++;
        }
        if(cadena[i] == '\n')
            otro++;
    }
    printf("Hay %d caracteres (%d caracteres + ENTER)\n", carac, carac - 1);
    printf("Hay %d vocales\n", vocal);
    printf("Hay %d consonantes\n", consonante);
    printf("Hay %d datos numericos\n", numerico);
    printf("Hay %d otros\n", otro);
    
    return 0;
}
