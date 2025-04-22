/* 
	Ramon Manriquez
	18 02 2025
	Calculadora
*/

#include <stdio.h>
#include <math.h>

int main(){

	// Declaracion de constantes
	#define RADGRAD 180/3.1416
	#define GRADRAD 3.1416 * 180
	#define MAX 1
	#define MIN -1
	
	// Declaracion e inicializacion de variables
	float acum = 0, valor;
	char opc;
	
	//Mostramos el menu mediante un do-while 
	do{
		printf("\nMENU CALCULADORA\n[+] SUMA\n[-] RESTA\n[*] MULTIPLICACION\n[/] DIVISION\n[P] POTENCIA\n[R] RAIZ\n[S] SENO\n[C] COSENO\n[T] TANGENTE\n");
		printf("[Z]ARCOSENO\n[K] ARCOCOSENO\n[G] ARCOTANGENTE\n[0] LIMPIAR\n[X] SALIR\n");
		printf("Escoge una opcion: ");
		scanf("%c", &opc);
		while(getchar()!='\n'){}

		// En caso de que el acum == 0 pedimos un valor antes de entrar en el case
		if(acum == 0 && (opc != 'X' || opc != 'x')){
			printf("\nIngresa un numero: ");
			scanf("%f", &acum);
			while(getchar()!='\n'){}
		}
		
		// Switch Case para las opciones 
		switch(opc){
			case '+':
				printf("\nSUMA\n\n");
				printf("Ingresa un numero: ");
				scanf("%f", &valor);
				while(getchar()!='\n'){}
				acum = acum + valor;
				printf("%.2f\n",acum); 
				break;
			case '-':
                               	printf("\nRESTA\n\n");
                        	printf("Ingresa un numero: ");
                                scanf("%f", &valor);
                                while(getchar()!='\n'){}
                                acum = acum - valor;
                                printf("%.2f\n",acum);
			       	break;
			case '*':
                               	printf("\nMULTIPLICACION\n\n");
                               	printf("Ingresa un numero: ");
                                scanf("%f", &valor);
                                while(getchar()!='\n'){}
                                acum = acum * valor;
                                printf("%.2f\n",acum);
				break;
			case '/':
                               	printf("\nDIVISION\n\n");
                               	printf("Ingresa un numero: ");
                                scanf("%f", &valor);
                                while(getchar()!='\n'){}	
                                acum = acum / valor;
                                printf("%.2f\n",acum);
				break;
			case('P'):
                               	printf("\nPOTENCIA\n\n");
                                printf("Ingresa un numero: ");
                                scanf("%f", &valor);
                                while(getchar()!='\n'){}
                                acum = pow(acum, valor);
                                printf("%.2f\n",acum);
				break;
			case('R'):
                               	printf("\nRAIZ\n\n");
                               	printf("Ingresa un numero: ");
                                scanf("%f", &valor);
                                while(getchar()!='\n'){}
                                acum = sqrt(acum);
                                printf("%.2f\n",acum);
				break;
			case('S'):
                               	printf("\n\nSENO\n");
                                acum = sin(acum);
                                printf("%.2f\n",acum);
				break;
			case 'C':
                               	printf("\nCOSENO\n\n");
                                acum = cos(acum);
                                printf("%.2f\n",acum);
				break;
			case 'T':
                               	printf("\nTANGENTE\n\n");
                                acum = tan(acum);
                                printf("%.2f\n",acum);
				break;
			case 'Z':
                               	printf("\nARCOSENO\n\n");
                                if(acum >= MIN && acum <= MAX){
					acum = asin(acum);
                                }else{
					printf("El numero no entra en el rango de arcoseno\n");
				}
				printf("%.2f\n",acum);
				break;
			case 'K':
                               	printf("\nARCOCOSENO\n\n");
				if(acum >= MIN && acum <= MAX){ 
	                                acum = acos(acum);
				}else{
					printf("El numero no entra en el rango de arcocoseno\n");
				}
                                printf("%.2f\n",acum);
				break;
			case 'G':
                               	printf("ARCOCOTANGENTE\n\n");
                                acum = atan(acum);
                                printf("%.2f\n",acum);
				break;
			case '0':
                               	printf("\nLIMPIAR\n\n");
				acum = 0;
				printf("%.2f", acum);
                               	break;
			case 'X':
                               	printf("\nSALIENDO\n\n");
                               	break;
			default:
				printf("OPCION NO VALIDA\n");
				break;
		}

     
	}while(opc != 'X' && opc != 'x');

	return 0;
}
