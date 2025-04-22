/*
	Ramon Manriquez Guerrero
	2210376
	Validacion de datos
*/

#include <stdio.h>

// Prototipos
int Count(char *string, int acum);
void Replace(char *string, int pos, int replacement);
void ClearInput();
int ValidateName(char *string, int n, char *numerosArray, char *caracteresEspecialesArray);
int ValidateBirthDate(char *birthDate);
int ValidateUsername(char *username, char *caracteresEspecialesArray, int n);
int CheckPassword(char *password, char *capsON, char *capsOFF, char *numerosArray, char *caracteresEspecialesArray, int *up, int *lo, int *num, int *spe, int n);
int ValidatePassword(char *password, char *confirmPassword, int n);

// Constantes
#define ALFABETO 27
#define NUMEROS 10
#define ESPECIALES 32
#define LONGITUD 256


int main(){

    // Declaracion e Inicializacino de variables
    int opc = 0, up = 0, lo = 0, num = 0, spe = 0, acum = 0, n = 0;
    char name[LONGITUD], lastName[LONGITUD], username[LONGITUD], password[LONGITUD], confirmPassword[LONGITUD], birthDate[11];
    char capsON[ALFABETO] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char capsOFF[ALFABETO] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char numerosArray[NUMEROS] = {'0','1','2','3','4','5','6','7','8','9'};
    char caracteresEspecialesArray[ESPECIALES] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[', ']', '{', '}', ';',    ':', '\'', '\"', ',', '.', '<', '>', '/', '?', '\\', '|', '`', '~'};
    
    //Menu Ciclado
    do{
        // Seleccion 
        printf("\n--MENU--\n");
        printf("Ingresa una opcion\n[1] Validacion de datos\n[0] Salir\n>> ");
        scanf("%d", &opc);
        ClearInput();
        // Opciones
        switch(opc){
            case 1: // Validacion de datos - El campo se repetira si la informacion ingresada es incorrecta
            
                // Validacion de nombre
                do{
                    printf("Ingresa tu nombre (Solamente caracteres alfabeticos)\n>> ");
                    fgets(name, LONGITUD, stdin);
                    n = Count(name, acum);
                    Replace(name, n-1, '\0');
                    
                    if(ValidateName(name, n, numerosArray, caracteresEspecialesArray)){
                        printf("TODO BIEN\n\n");
                    }
                    else{
                        printf("TODO MAL\n\n");
                    }
                    
                }while(ValidateName(name, n, numerosArray, caracteresEspecialesArray) == 0);
                

                //Validacion de apellido
                do{
                    printf("Ingresa tu apellido (Solamente caracteres alfabeticos)\n>> ");
                    fgets(lastName, LONGITUD, stdin);
                    n = Count(lastName, acum);
                    Replace(lastName, n-1, '\0');
                    n = Count(lastName, acum);
                    
                    if(ValidateName(lastName, n, numerosArray, caracteresEspecialesArray)){
                        printf("TODO BIEN\n\n");
                    }
                    else{
                        printf("TODO MAL\n\n");
                    }
                    
                }while(ValidateName(lastName, n, numerosArray, caracteresEspecialesArray) == 0);
                
                // Validacion de dia de nacimiento
                do{
                    printf("Ingresa tu fecha de nacimiento. Formato DD/MM/YYYY\n>> ");
                    fgets(birthDate, 11, stdin);
                    n = Count(birthDate, acum);
                    Replace(birthDate, n, '\0');
		    ClearInput();
                    if(ValidateBirthDate(birthDate)){
                        printf("TODO BIEN\n\n");
                    }
                    else{
                        printf("TODO MAL\n\n");
                    }
                }while(ValidateBirthDate(birthDate) == 0);
                
                // Validacion de UserName
                do{
                    printf("Ingresa tu nombre de usuario\n>> ");
                    fgets(username, LONGITUD, stdin);
                    n = Count(username, acum);
                    Replace(username, n-1, '\0');
                    n = Count(username, acum);
                    
                    if(ValidateUsername(username, caracteresEspecialesArray, n)){
                        printf("TODO BIEN\n\n");
                    }else{
                        printf("TODO MAL\n\n");
                    }
                    
                }while(ValidateUsername(username, caracteresEspecialesArray, n) == 0);
                
                // Captura de contraseña
                do{
                    printf("Ingrese su contraseña\n>> ");
                    fgets(password, LONGITUD, stdin);
                    n = Count(password, acum);
                    Replace(password, n-1, '\0');
                    n = Count(password, acum);
                    
                    if(CheckPassword(password, capsON, capsOFF, numerosArray, caracteresEspecialesArray, &up, &lo, &num, &spe, n)){
                        printf("TODO BIEN\n\n");
                    }else{
                        printf("TODO MAL\n\n");
                    }
                    
                }while(CheckPassword(password, capsON, capsOFF, numerosArray, caracteresEspecialesArray, &up, &lo, &num, &spe, n) == 0);
                
                // Validacino de contraseña
                do{
                    printf("Vuelva a ingresar su contraseña\n>> ");
                    fgets(confirmPassword, LONGITUD, stdin);
                    n = Count(confirmPassword, acum);
                    Replace(confirmPassword, n-1, '\0');
                    n = Count(confirmPassword, acum);
                    
                    if(ValidatePassword(password, confirmPassword, n)){
                        printf("TODO BIEN\n\n");
                    }else{
                        printf("TODO MAL\n\n");
                    }
                    
                }while(ValidatePassword(password, confirmPassword, n) == 0);
                break;
            case 0: // Salir
                printf("Saliendo del programa\n");
                return 1;
                break;
            default: // Invalido
                printf("Opcion invalida...\n");
                break;
        }
    }while(opc != 0);

    return 0;
}

// Procedimientos
int Count(char *string, int acum){
    acum = 0;
    for(int i = 0; i < LONGITUD; i++){
        if(string[i] == '\0')
            break;
        else
                acum++;
    }
    return acum;
}
void Replace(char *string, int replacementpos, int replacement){
    string[replacementpos] = replacement;
}
void ClearInput(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {} // Limpiar buffer de entrada
}
int ValidateName(char *name, int n, char *numerosArray, char *caracteresEspecialesArray){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < NUMEROS; j++){
            if(name[i] == numerosArray[j])
                return 0;
        }
        for(int j = 0; j < ESPECIALES; j++){
            if(name[i] == caracteresEspecialesArray[j])
                return 0;
        }
    }
    return 1;
}
int ValidateBirthDate(char *birthDate) {
    int day = 0, month = 0, year = 0;
    int i = 0, part = 0, value = 0;
    
    // Recorrer la cadena manualmente
    while(birthDate[i] != '\0') {
        if(birthDate[i] >= '0' && birthDate[i] <= '9') {
            value = value * 10 + (birthDate[i] - '0');
        }else if (birthDate[i] == '/') {
            if (part == 0) {
                day = value;
            }else if (part == 1) {
                month = value;
            }
            value = 0;
            part++;
        }else {
            return 0; // Carácter inválido
        }
        i++;
    }
    
    if(part != 2) 
        return 0; // Formato inválido
    
    year = value;
    
    // Verificar rango de año
    if(year < 1900 || year > 2100) {
        return 0;
    }
    
    // Verificar rango de mes
    if(month < 1 || month > 12) {
        return 0;
    }

    // Días máximos por mes
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Verificar si el año es bisiesto
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29;
    }
    
    // Verificar día válido
    if(day < 1 || day > daysInMonth[month - 1]) {
        return 0;
    }
    
    return 1;
}
int ValidateUsername(char *username, char *caracteresEspecialesArray, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < ESPECIALES; j++){
            if(username[i] == caracteresEspecialesArray[j]){
                return 0;
            }
        }
    }
    return 1;
}
int CheckPassword(char *password, char *capsON, char *capsOFF, char *numerosArray, char *caracteresEspecialesArray, int *up, int *lo, int *num, int *spe, int n){
    *up = *lo = *num = *spe = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < ALFABETO; j++){
            if(password[i] == capsON[j])
                (*up)++;
            if(password[i] == capsOFF[j])
                (*lo)++;
        }
        for(int j = 0; j < NUMEROS; j++){
            if(password[i] == numerosArray[j])
                (*num)++; 
        }
        for(int j = 0; j < ESPECIALES; j++){
            if(password[i] == caracteresEspecialesArray[j])
                (*spe)++;
        }
    }
    if((*up + *lo + *num + *spe) < 8 || *up < 1 || *lo < 1 || *num < 1 || *spe < 1){
        return 0;
    }else{
        return 1;
    }
}
int ValidatePassword(char *password, char *confirmPassword, int n){
    for(int i = 0; i < n; i++){
        if(password[i] != confirmPassword[i]){
            return 0;
        }
    }
    return 1;
}
