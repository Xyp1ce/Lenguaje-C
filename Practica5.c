/*
 * Ramon Manriquez
 * 11 03 2025
 * Palabra palindroma con apuntadores
*/

#include <stdio.h>

// Declaracion de constantes
#define LONGITUD 256

int main(){
    // Declaracion e Inicializacion de variables
    char cadena[LONGITUD] = {}, c;
    int opc = 0, cont = 0;
    // Declaracion de punteros
    char *inicio, *fin;
    
    printf("--MENU--");
    printf("\n[1] Verificar palindromo\n[2] Terminar Programa\n>> ");
    scanf("%d", &opc);
    while ((c = getchar()) != '\n' && c != EOF){} // Limpiamos buffer de entrada
    do{
        //switch-case para ambas opciones
        switch(opc){
            case 1: // Verificar palindromo
            cont = 0;
                printf("Ingresa una palabra (Maximo 256 caracteres):\n");
                fgets(cadena, LONGITUD, stdin);
                inicio = &cadena[0]; // Asignamos al apuntador la direccion del primer caracter
                for(int i = 0; i < LONGITUD; i++){
                    if(cadena[i] == '\n'){ 
                        fin = &cadena[i - 1]; // Asignamos al apuntador la direccion del caracter anterir al salto de linea
                        cadena[i] = '\0'; // Reemplazamos \n con \0
                        break; // Detenmos el bucle for
                    }
                    cont++; // Contamos cuantos caracteres hay antes del \n
                }
                printf("\nHay %d caracteres", cont);
                while(inicio < fin){       // Mientras que la direccion de inicio sea menor a la de fin
                    while(*inicio == ' '){ // Verificamos que ninguno de los apuntadores sean espacios
                        inicio++;          // En dado caso aumentamos uno al inicio y/o decrementamos uno al fin
                    }         
                    while(*fin == ' '){
                        fin--;
                    }
                    printf("\nInicio >> %c | %c << Fin", *inicio, *fin); // Mostramos los datos de inicio y fin

                    if(*inicio != *fin){ // Si los valores son diferentes se termina
                        printf("\nLa palabra/frase no es palindroma");
                        break;
                    }
                    
                    inicio++;
                    fin--;
                    
                    if(inicio >= fin){
                        printf("\nLa palabra/frase es palindroma");
                        break;
                    }
                }
                break;
            case 2: // Terminar programa
                printf("\nTerminando programa...");
                return 1;
                break;
        }
        printf("\nDesea continuar?\n[1] Si\n[2] No\n>> ");
        scanf("%d", &opc);
        while ((c = getchar()) != '\n' && c != EOF){} // Limpiamos buffer de entrada
    }while(opc == 1);
}
