#include <stdio.h>

#define LONG 1024  // Definimos el tamaño máximo de las cadenas

int main() {
    // Declaración de variables
    char string1[LONG] = {0};  // Almacena la frase original
    char string2[LONG] = {0};  // Almacena la palabra a buscar
    char string3[LONG] = {0};  // Almacena la palabra de reemplazo
    char c;                    // Variable auxiliar para limpiar el buffer
    int opc = 0, is_found = 0;  // Opción del menú y bandera para verificar si se encontró la palabra

    do {
        // Menú de opciones
        printf("Escoge una opcion\n[1] Capturar frase\n[2] Reemplazar palabra\n[0] Terminar Programa\n>> ");
        scanf("%d", &opc);
        while ((c = getchar()) != '\n' && c != EOF) {} // Limpiar buffer de entrada

        switch (opc) {
            case 1: // Capturar la frase completa
                printf("Ingresa una oracion\n>> ");
                fgets(string1, LONG, stdin);  // Leer la frase
                for (char *p = string1; *p != '\0'; p++) { // Eliminar el salto de línea al final
                    if (*p == '\n') {
                        *p = '\0';
                        break;
                    }
                }
                printf("La frase ingresada fue: %s\n", string1);
                break;

            case 2: // Reemplazar palabra en la frase
                printf("Ingresa una palabra para buscar\n>> ");
                fgets(string2, LONG, stdin);  // Leer la palabra a buscar
                for (char *p = string2; *p != '\0'; p++) { // Eliminar el salto de línea
                    if (*p == '\n') {
                        *p = '\0';
                        break;
                    }
                }

                printf("Ingresa la palabra de reemplazo\n>> ");
                fgets(string3, LONG, stdin);  // Leer la palabra de reemplazo
                for (char *p = string3; *p != '\0'; p++) { // Eliminar el salto de línea
                    if (*p == '\n') {
                        *p = '\0';
                        break;
                    }
                }

                // Inicializamos la nueva cadena resultante
                char resultado[LONG] = {0};
                char *p1 = string1, *p2;  // Puntero para recorrer la frase
                int idx = 0;  // Índice para la nueva cadena

                is_found = 0;  // Reiniciamos la bandera antes de buscar la palabra

                while (*p1 != '\0') {  // Recorremos la frase original
                    if (*p1 == *string2) {  // Si el carácter coincide con el inicio de la palabra a buscar
                        p2 = string2;
                        char *temp = p1;

                        // Verificar si toda la palabra coincide
                        while (*temp == *p2 && *p2 != '\0') {
                            temp++;
                            p2++;
                        }

                        // Si encontramos la palabra completa y está separada por espacio o signos de puntuación
                        if (*p2 == '\0' && (*temp == ' ' || *temp == ',' || *temp == '.' || *temp == '\0')) {
                            is_found = 1;

                            // Copiar la palabra de reemplazo en la nueva cadena
                            for (char *p3 = string3; *p3 != '\0'; p3++) {
                                resultado[idx++] = *p3;
                            }

                            p1 = temp;  // Saltamos la palabra original en la frase
                            continue;
                        }
                    }
                    resultado[idx++] = *p1++;  // Copiar carácter actual a la nueva cadena
                }

                resultado[idx] = '\0';  // Agregar terminador de cadena

                if (is_found) {
                    // Copiar la cadena modificada de regreso a string1
                    for (int i = 0; resultado[i] != '\0'; i++) {
                        string1[i] = resultado[i];
                    }
                    string1[idx] = '\0';  // Asegurar terminador de cadena

                    printf("Frase actualizada: %s\n", string1);
                } else {
                    printf("La palabra no está en la oración\n");
                }

                break;

            case 0: // Terminar programa
                printf("Terminando programa...\n");
                return 0;

            default:
                printf("Opcion invalida...\n");
                break;
        }
    } while (opc != 0);

    return 0;
}
