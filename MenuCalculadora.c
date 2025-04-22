/*
 * Ramon Manriquez
 * 18 02 2025
 * Realizar una calculadora en grados sobre una variable acumulativa
 */

#include <stdio.h>
#include <math.h>

int main()
{
    // Declaracion de constantes
    #define RADGRAD 180/3.1415926535
    #define GRADRAD 3.1415926535/180
    #define MAX 1
    #define MIN -1
    
    // Declaracion e inicializacion de variables
    float res = 0, valor;
    char opc;
    
    // ciclo do-while para repetir el menu 
    do{
        printf("\nCALCULADORA\n\n");
        if(res == 0){
            printf("Ingresa un valor\n");
            scanf("%f", &res);
            while(getchar()!='\n'){}
            printf("\n");
        }
        printf("[+] SUMA       [-] RESTA       [*] MULITPLICACION [/] DIVISION\n");
        printf("[P] POTENCIA   [R] RAIZ        [S] SENO           [C] COSENO\n");
        printf("[T] TANGENGETE [Z] ARCOSENO    [K] ARCOCOSENO     [G] ARCOTANGENTE\n");
        printf("[0] LIMPIAR    [X] SALIR\n\n");
        printf("Escoge una opcion: ");
        scanf("%c", &opc);
        printf("\n");
        while(getchar()!='\n'){}
        
        // Switch case 
        switch(opc){
                case '+':
                    printf("-----------------------------------\n");
                    printf("SUMA\n");
                    printf("Ingresa un valor: ");
                    scanf("%f", &valor);
                    while(getchar()!='\n'){}
                    res = res + valor;
                    printf("%.2f\n", res);
                    printf("-----------------------------------\n");
                    break;
                case '-':
                    printf("-----------------------------------\n");
                    printf("RESTA\n");
                    printf("Ingresa un valor: ");
                    scanf("%f", &valor);
                    while(getchar()!='\n'){}
                    res = res - valor;
                    printf("%.2f\n", res);
                    printf("-----------------------------------\n");
                    break;
                case '*':
                    printf("-----------------------------------\n");
                    printf("MULTIPLICACION\n");
                    printf("Ingresa un valor: ");
                    scanf("%f", &valor);
                    while(getchar()!='\n'){}
                    res = res * valor;
                    printf("%.2f\n", res);
                    printf("-----------------------------------\n");
                    break;
                case '/':
                    printf("-----------------------------------\n");
                    printf("DIVISION\n");
                    printf("Ingresa un valor: ");
                    scanf("%f", &valor);
                    while(getchar()!='\n'){}
                    if(valor == 0){
                        printf("NO ES POSIBLE LA DIVISION ENTRE 0\n");
                    }else{
                        res = res / valor;
                        printf("%.2f\n", res);
                    }
                    printf("-----------------------------------\n");
                    break;
                case 'P':
                case 'p':
                    printf("-----------------------------------\n");
                    printf("POTENCIA\n");
                    printf("Ingresa un valor: ");
                    scanf("%f", &valor);
                    while(getchar()!='\n'){}
                    res = pow(res,valor);
                    printf("%.2f\n", res);
                    printf("-----------------------------------\n");
                    break;
                case 'R':
                case 'r':
                    printf("-----------------------------------\n");
                    printf("RAIZ\n");
                    res = sqrt(res);
                    printf("%.2f\n", res);
                    printf("-----------------------------------\n");
                    break;
                case 'S':
                case 's':
                    printf("-----------------------------------\n");
                    printf("SENO\n");
                    res = sin(res * GRADRAD);
                    printf("%f\n", res);
                    printf("-----------------------------------\n");
                    break;
                case 'C':
                case 'c':
                    printf("-----------------------------------\n");
                    printf("COSENO\n");
                    printf("SENO\n");
                    res = cos(res * GRADRAD);
                    printf("%f\n", res);
                    printf("-----------------------------------\n");
                    break;
                case 'T':
                case 't':
                    printf("-----------------------------------\n");
                    printf("TANGENTE\n");
                    printf("SENO\n");
                    res = tan(res * GRADRAD);
                    printf("%f\n", res);
                    printf("-----------------------------------\n");
                    break;
                case 'Z':
                case 'z':
                    printf("-----------------------------------\n");
                    printf("ARCOSENO\n");
                    if(res >= MIN && res <= MAX){
                        res = asin(res) * RADGRAD;
                        printf("%f\n", res);
                    }else{
                        printf("%.2f no esta entre el rango aceptable del arco seno\n", res);
                    }
                    printf("-----------------------------------\n");
                    break;
                case 'K':
                case 'k':
                    printf("-----------------------------------\n");
                    printf("ARCOCOSENO\n");
                    if(res >= MIN && res <= MAX){
                        res = acos(res) * RADGRAD;
                        printf("%f\n", res);
                    }else{
                        printf("%.2f no esta entre el rango aceptable del arco coseno\n", res);
                    }
                    printf("-----------------------------------\n");
                    break;
                case 'G':
                case 'g':
                    printf("-----------------------------------\n");
                    printf("ARCOTANGENTE\n");
                    res = atan(res) * RADGRAD;
                    printf("%f\n", res);
                    printf("-----------------------------------\n");
                    break;
                case '0':
                    printf("-----------------------------------\n");
                    printf("LIMPIAR\n");
                    res = 0;
                    printf("%.2f\n", res);
                    printf("-----------------------------------\n");
                    break;
                case 'X':
                case 'x':
                    printf("-----------------------------------\n");
                    printf("SALIENDO\n");
                    printf("-----------------------------------\n");
                    break;
                default:
                    printf("-----------------------------------\n");
                    printf("OPCION NO VALIDA\n");
                    printf("-----------------------------------\n");
                    break;
        }
    }while(opc != 'X' && opc != 'x');
    return 0;
}
