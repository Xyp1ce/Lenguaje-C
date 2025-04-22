/*
	Manriquez Guerrero Ramon
	2210376
	25 03 2025
*/

#include <stdio.h>

// Prototipos
void GetChar(char *);
int CountChar(char *, int *);
int Replace(char *, char *, char *);
void CapsON(char *, char *, char *);
void CapsOFF(char *, char *, char *);

int main(){
	
	// Declaracion e Inicializacion de variables
	char string[256], c, replacementpos[2], replacement[2];
	int opc = 0, acum = 0;	
	char capsON[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char capsOFF[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	
	// Ciclo do-while para el menu
	do{
		printf("--PRACTICA7--\n");
		printf("[1] Capturar cadena de caracteres \n[2] Contar Caracteres \n[3] Reemplazar \n[4] Mayusculas \n[5] Minusculas \n[0] Terminar Programa\n");
		scanf("%d", &opc);
		while ((c = getchar()) != '\n' && c != EOF) {} // Limpiar buffer de entrada
		// Switch Case para las opciones
		switch(opc){
			case 1: // Capturar cadena de caracteres
				GetChar(string);
				break;
			case 2: // Contar caracteres
				CountChar(string, &acum);
				printf("Hay %d caracteres\n", acum);
				break;
			case 3: // Reemplazar
				printf("Ingrese un caracter a reemplazar en %s\n>> ", string);
				fgets(replacementpos, 2, stdin);
				while ((c = getchar()) != '\n' && c != EOF) {} // Limpiar buffer de entrada
				printf("Por cual caracter desea cambiarlo?\n>> ");
				fgets(replacement, 2, stdin);
				while ((c = getchar()) != '\n' && c != EOF) {} // Limpiar buffer de entrada
				Replace(string, replacementpos, replacement);
				break; 
			case 4: // Minus a Mayusculas
				CapsON(string, capsON, capsOFF);
				break;
			case 5: // Mayusculas a Minus
				CapsOFF(string, capsON, capsOFF);
				break;
			case 0:
				break;
			default:
				printf("Opcion invalida...\n");
				break;
			
			
		}
	}while(opc != 0);

	return 0;
}

// Procedimientos
void GetChar(char *string){
	printf("Ingresa una cadena de caracteres:\n>> ");
	fgets(string, 256, stdin);
	int i = 0;
	while(string[i] != '\0'){
		if(	string[i + 1] == '\0')
			string[i] = '\0';
		i++;
	}
}

int CountChar(char *string, int *acum){
	*acum = 0;
	for(int i = 0; i < 256; i++){
		if(string[i] == '\0')
			break;
		else
			(*acum)++;
	}
	return *acum;
}

int Replace(char *string, char *replacementpos, char *replacement){
	for(int i = 0; i < 256 ; i++){
		if(*replacementpos == string[i]){
			string[i] = *replacement;
			printf("La palabra actualizada es %s\n", string);
			return 1;
		}
	}
	printf("%s no se encuentra en %s\n", replacement, string);
	return 0;
}

void CapsON(char *string, char *capsON, char *capsOFF){
	for(int i = 0; i < 256 ; i++){
		for(int j = 0; j < 27; j++){
			if(string[i] == capsOFF[j]){
				string[i] = capsON[j];
			}
		}
	}
	printf("%s\n", string);
}

void CapsOFF(char *string, char *capsON, char *capsOFF){
	for(int i = 0; i < 256 ; i++){
		for(int j = 0; j < 27; j++){
			if(string[i] == capsON[j]){
				string[i] = capsOFF[j];
			}
		}
	}
	printf("%s\n", string);
}
