/*
 * Ramon Manriquez 
 * 2210376
 * Implementar un programa donde simula el registro e inico de sesion en un sistema. 
 * Adaptar la funcionalidad realizada en la Practica 7 (si es necesario) para el nuevo esquema de datos
 */

#include <stdio.h>

// constantes
#define USERS 3
#define FIELDS 5
#define CHARACTERS 100
#define ALFABETO 27
#define NUMEROS 10
#define ESPECIALES 32

// prototipos

// Captura de datos
void ClearInput();
void Initialize(char *data, int users, int fields, int characters);
void GetData(char *data, int characters);
int ValidateName(char *data, char *numbers, char *specials, int constNumber, int constSpecial);
int ValidateBirthDate(char *birthDate);
int ValidateUsername(char *data, char *specials, int users, int fields, int characters, int constSpecial, int pos, char *ptr);
int CheckPassword(char *data, char *capsON, char *capsOFF, char *numerosArray, char *especialesArray, int alfabeto, int numeros, int especiales);
int ValidatePassword(char *data, char *validateData);
int IsLeapYear(int year);

// Inicio de sesion
int SearchUserName(char *data, char *userName, int users, int fields, int characters);
int SearchPassword(char *data, char *userName, int pos, int users, int fields, int characters);
void ShowData(char *data, int pos, int users, int fields, int characters);

int main() {
    int opc = 0;
    // do while para el menu
    do {
        printf("--MENU--\n");
        printf("[1] Sing In\n[2] Log In \n[0] Exit\n");
        printf("Escoge una opcion\n>> ");
        scanf("%d", &opc);
        ClearInput();
        // Switch case para la opcion 
        switch(opc) {
            case 1: // Registrarse
                // Declaracion e Inicializacion de variables para la captura de datos
                char data[USERS][FIELDS][CHARACTERS];
                char capsON[ALFABETO] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
                char capsOFF[ALFABETO] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
                char numerosArray[NUMEROS] = {'0','1','2','3','4','5','6','7','8','9'};
                char caracteresEspecialesArray[ESPECIALES] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[', ']', '{', '}', ';', ':', '\'', '\"', ',',                                                              '.', '<', '>', '/', '?', '\\', '|', '`', '~'};
                char valPass[CHARACTERS];
                Initialize(&data[0][0][0], USERS, FIELDS, CHARACTERS);
                for (int i = 0; i < USERS; i++) {
                    printf("--USUARIO %d--\n", i + 1);
                    for (int j = 0; j < FIELDS; j++) {
                        if (data[i][j][0] == '\0') {
                            // switch-case para alternar los campos del usuario
                            switch(j) {
                                case 0: // Nombre(s)
                                    do {
                                        printf("Ingresa tu(s) nombre(s)\n>> ");
                                        GetData(&data[i][j][0], CHARACTERS);
                                    } while (ValidateName(&data[i][j][0], numerosArray, caracteresEspecialesArray, NUMEROS, ESPECIALES) == 0);
                                    break;
                                case 1: // Apellidos(s)
                                    do {
                                        printf("Ingresa tu(s) apellido(s)\n>> ");
                                        GetData(&data[i][j][0], CHARACTERS);
                                    } while (ValidateName(&data[i][j][0], numerosArray, caracteresEspecialesArray, NUMEROS, ESPECIALES) == 0);
                                    break;
                                case 2: // Fecha de nacimiento DD/MM/YYYY
                                    do {
                                        printf("Ingresa tu fecha de nacimiento\nFormato DD/MM/YYYY\n>> ");
                                        GetData(&data[i][j][0], CHARACTERS);
                                    } while (ValidateBirthDate(&data[i][j][0]) == 0);
                                    break;
                                case 3: // Nombre de usuario
                                    do {
                                        printf("Ingresa tu nombre de usuario\n>> ");
                                        GetData(&data[i][j][0], CHARACTERS);
                                    } while (ValidateUsername(&data[i][j][0], caracteresEspecialesArray, USERS, FIELDS, CHARACTERS, ESPECIALES, i, &data[0][0][0]) == 0);
                                    break;
                                default: // Contraseña
                                    do {
                                        // Llamar a la función para validar la contraseña
                                        do {
                                            printf("Ingresa tu contraseña\n>> ");
                                            GetData(&data[i][j][0], CHARACTERS);
                                        } while (CheckPassword(&data[i][j][0], &capsON[0], &capsOFF[0], &numerosArray[0], &caracteresEspecialesArray[0], ALFABETO, NUMEROS,                                                                                                                                                         ESPECIALES) == 0);
                                        printf("Valida tu contraseña\n>> ");
                                        GetData(&valPass[0], CHARACTERS);
                                    } while (ValidatePassword(&data[i][j][0], &valPass[0]) == 0);
                                    
                                    break;
                            }
                        }
                    }
                }
                break;
            case 2: // Iniciar Sesion
                // Declaracion e inicializacion de variables para el inicio de sesion
                char checkUsername[CHARACTERS];
                char checkPassword[CHARACTERS];
                int user = -1;
                printf("--INICIO DE SESION--\n");
                do {
                    printf("Ingresa tu nombre de usuario\n>> ");
                    GetData(checkUsername, CHARACTERS);
                    user = SearchUserName(&data[0][0][0], checkUsername, USERS, FIELDS, CHARACTERS);
                    if (user == -1) 
                        printf("Usuario no encontrado.\n");
                } while (user == -1);

                do{
                    printf("Ingresa tu contraseña\n>> ");
                    GetData(checkPassword, CHARACTERS);
                }while(SearchPassword(&data[0][0][0], &checkPassword[0], user, USERS, FIELDS, CHARACTERS) == 0);
                ShowData(&data[0][0][0], user, USERS, FIELDS, CHARACTERS);
                break;
            case 0: // Salir
                printf("Terminando programa...\n");
                return 0;
            default:
                printf("Opcion invalida...\n");
                break;
        }
    } while (opc != 0);

    return 0;
}

// Procedimientos
void ClearInput() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {} // Limpiar buffer de entrada
}

void Initialize(char *data, int users, int fields, int characters) {
    for (int i = 0; i < users; i++) {
        for (int j = 0; j < fields; j++) {
            for (int k = 0; k < characters; k++) {
                data[(i * fields * characters) + (j * characters) + k] = '\0';
            }
        }
    }
}

void GetData(char *data, int characters) {
    fgets(data, characters, stdin);
    // Elimina el salto de línea al final, si lo hay
    int i = 0;
    while (data[i] != '\0') {
        if (data[i] == '\n') {
            data[i] = '\0';
            break;
        }
        i++;
    }
}

int ValidateName(char *data, char *numbers, char *specials, int constNumber, int constSpecial) {
    int i = 0;
    while (data[i] != '\0') {
        for (int j = 0; j < constNumber; j++) {
            if (data[i] == numbers[j])
                return 0;
        }
        for (int j = 0; j < constSpecial; j++) {
            if (data[i] == specials[j])
                return 0;
        }
        i++;
    }
    return 1;
}

int IsLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // Año bisiesto
    }
    return 0; // Año no bisiesto
}

int ValidateBirthDate(char *birthDate) {
    int day, month, year;

    // Leer los datos de la fecha
    if (birthDate[2] != '/' || birthDate[5] != '/') {
        printf("Fecha en formato incorrecto. Usa el formato DD/MM/YYYY.\n");
        return 0;
    }

    // Convertir día, mes y año a enteros
    day = (birthDate[0] - '0') * 10 + (birthDate[1] - '0');
    month = (birthDate[3] - '0') * 10 + (birthDate[4] - '0');
    year = (birthDate[6] - '0') * 1000 + (birthDate[7] - '0') * 100 + (birthDate[8] - '0') * 10 + (birthDate[9] - '0');

    // Verificar si el mes es válido
    if (month < 1 || month > 12) {
        printf("Mes no válido.\n");
        return 0;
    }

    // Verificar los días en función del mes
    int maxDay = 31;
    if (month == 2) {
        // Verificar si es un año bisiesto
        if (IsLeapYear(year)) {
            maxDay = 29; // Febrero tiene 29 días en un año bisiesto
        } else {
            maxDay = 28; // Febrero tiene 28 días en un año no bisiesto
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDay = 30; // Meses con 30 días
    }

    if(year > 2025 || year < 2000){
        printf("Año no valido\n");
        return 0;
    }

    if (day < 1 || day > maxDay) {
        printf("Día no válido para el mes.\n");
        return 0;
    }

    return 1;
}

int ValidateUsername(char *data, char *specials, int users, int fields, int characters, int constSpecial, int pos, char *ptr) {
    int i = 0;

    // Verificar caracteres especiales
    while (data[i] != '\0') {
        for (int j = 0; j < constSpecial; j++) {
            if (data[i] == specials[j]) {
                printf("Este caracter no es aceptado: %c\n", data[i]);
                return 0; // Caracter especial no permitido
            }
        }
        i++;
    }

    // Verificar si el nombre de usuario ya está registrado
    for (int i = 0; i < users; i++) {
        if (i == pos) continue;

        char *existingUser = &ptr[(i * fields * characters) + (3 * characters)];

        int j = 0;
        while (existingUser[j] != '\0' && data[j] != '\0') {
            if (existingUser[j] != data[j]) {
                break;
            }
            j++;
        }

        if (existingUser[j] == '\0' && data[j] == '\0') {
            printf("Ya hay un usuario con ese nombre registrado\n");
            return 0; // Hay usuarios repetidos
        }
    }

    return 1; // No hay usuarios repetidos
}

int CheckPassword(char *data, char *capsON, char *capsOFF, char *numerosArray, char *especialesArray, int alfabeto, int numeros, int especiales) {
    // Inicializamos valores para revisar que la contraseña cumpla con las condiciones
    int i = 0, cap = 0, low = 0, num = 0, esp = 0;
    while (data[i] != '\0') {
        for (int j = 0; j < alfabeto; j++) {
            if (capsON[j] == data[i]) {
                cap++;
            }
            if (capsOFF[j] == data[i]) {
                low++;
            }
        }
        for (int j = 0; j < numeros; j++) {
            if (numerosArray[j] == data[i]) {
                num++;
            }
        }
        for (int j = 0; j < especiales; j++) {
            if (especialesArray[j] == data[i]) {
                esp++;
            }
        }
        i++;
    }

    if ((cap + low + num + esp < 8) || (num < 1) || (esp < 1) || (low < 1) || (cap < 1)) {
        return 0;
    }
    return 1;
}

int ValidatePassword(char *data, char *validateData) {
    int i = 0;
    while (data[i] != '\0') {
        if (data[i] != validateData[i]) {
            printf("Las contraseñas no son iguales...\n");
            return 0;
        }
        i++;
    }
    return 1;
}

int SearchUserName(char *data, char *userName, int users, int fields, int characters){
    for(int i = 0; i < users; i++){
        char *existingUsername = &data[(i * fields * characters)+(3*characters)];
        if(userName[0] == existingUsername[0]){
            int j = 0;
            while(userName[j] != '\0' && existingUsername[j] != '\0'){
                if(userName[j] != existingUsername[j]){
                    // Tienen la misma primera letra pero no son iguales
                    break;
                }
                j++;
            }
            if (userName[j] == '\0' && existingUsername[j] == '\0') {
                return i; // Si se encuentra
            }
        }
    }
    printf("Nombre de usuario no registrado...\n");
    return -1;
}

int SearchPassword(char *data, char *password, int pos, int users, int fields, int characters){
    char *existingPassword = &data[(pos * fields * characters)+(4*characters)];
    
    int i = 0;
    while(password[i] != '\0' && existingPassword[i] != '\0'){
        if(password[i] != existingPassword[i]){
            printf("Contraseña Incorrecta...\n");
            return 0; 
        }
        i++;
    }
    return 1;
}

void ShowData(char *data, int pos, int users, int fields, int characters){
    printf("--BIENVENIDO--\n");
    printf("Nombre(s) - %s\n", &data[(pos*fields*characters)+(0*characters)]);
    printf("Apellido(s) - %s\n", &data[(pos*fields*characters)+(1*characters)]);
    printf("Fecha de nacimiento - %s\n", &data[(pos*fields*characters)+(2*characters)]);
}
