/* 
	Ramon Manriquez Guerrero 
	11 02 2025
	Menu Bitwise
*/

#include <stdio.h>

int main(){

	// Declaracion e inicializacion de variables
	unsigned short int num, opc, bit, insBit, exBit, invBit;

	// Pedimos el numero al usuario
	printf("Ingrese un numero: ");
	scanf("%d", &num);
	
	// Mostramos numero en binario
	printf("Numero binario -> ");
	printf("%d",(num&(1<<15)) > 0);
        printf("%d",(num&(1<<14)) > 0);
        printf("%d",(num&(1<<13)) > 0);
        printf("%d",(num&(1<<12)) > 0);
        printf("%d",(num&(1<<11)) > 0);
        printf("%d",(num&(1<<10)) > 0);
        printf("%d",(num&(1<<9)) > 0);
        printf("%d",(num&(1<<8)) > 0);
	printf("%d",(num&(1<<7)) > 0);
	printf("%d",(num&(1<<6)) > 0);
	printf("%d",(num&(1<<5)) > 0);
	printf("%d",(num&(1<<4)) > 0);
	printf("%d",(num&(1<<3)) > 0);
	printf("%d",(num&(1<<2)) > 0);
	printf("%d",(num&(1<<1)) > 0);	
	printf("%d",(num&(1<<0)) > 0);

	// Menu
	printf("\nMenu\n[0] Consultar bit\n[1] Set bit\n[2] Invertir bit\nQue opcion desea? ");
	scanf("%d", &opc);

	// Control de flujo menu
	if(opc == 0){
		// Consultar bit
		printf("Opcion 0\n");
		printf("Que bit desea consultar (0 - 15)? ");
		scanf("%d", &bit);
		if(bit <= 15 && bit >=  0){
			printf("El bit en la posicion %d es: %d\n\n",bit ,(num&1<<bit)>0);		
		}
	}else if(opc == 1){
		// Set bit
		printf("Opcion 1\n");
		printf("Que bit desea insertar (0 - 15)? ");
                scanf("%d", &bit);
                if(bit <= 15 && bit >=  0){
			printf("El bit en la posicion %d es %d\n", bit, (num&(1<<bit))>0);
			num = num | (1<<bit);
			printf("Ahora el valor del bit %d es %d\n", bit, (num&(1<<bit))>0);
			printf("El nuevo valor es %d\n", num);
			printf("Numero binario -> ");
        		printf("%d",(num&(1<<15)) > 0);
        		printf("%d",(num&(1<<14)) > 0);
        		printf("%d",(num&(1<<13)) > 0);
        		printf("%d",(num&(1<<12)) > 0);
        		printf("%d",(num&(1<<11)) > 0);
        		printf("%d",(num&(1<<10)) > 0);
        		printf("%d",(num&(1<<9)) > 0);
        		printf("%d",(num&(1<<8)) > 0);
			printf("%d",(num&(1<<7)) > 0);
        		printf("%d",(num&(1<<6)) > 0);
        		printf("%d",(num&(1<<5)) > 0);
        		printf("%d",(num&(1<<4)) > 0);
        		printf("%d",(num&(1<<3)) > 0);
        		printf("%d",(num&(1<<2)) > 0);
			printf("%d",(num&(1<<1)) > 0);
			printf("%d",(num&(1<<0)) > 0);
               		printf("\n");
			
		}
	}else if(opc == 2){
		// Invertir bit
		printf("Opcion 2\n");
		printf("Que bit desea consultar (0 - 15)? ");
                scanf("%d", &bit);
                if(bit <= 15 && bit >=  0){
			exBit = num & (1<<bit);
			invBit = exBit ^ (1<<bit);
                	num = num & ~(1<<bit);
			num = num | invBit;
			printf("El nuevo valor del numero es: %d\n\n", num);
			
			// Mostramos el numero modificado en binario
			printf("Numero binario ->");
        		printf("%d",(num&(1<<15)) > 0);
                        printf("%d",(num&(1<<14)) > 0);
                        printf("%d",(num&(1<<13)) > 0);
                        printf("%d",(num&(1<<12)) > 0);
                        printf("%d",(num&(1<<11)) > 0);
                        printf("%d",(num&(1<<10)) > 0);
                        printf("%d",(num&(1<<9)) > 0);
                        printf("%d",(num&(1<<8)) > 0);			
			printf("%d",(num&(1<<7)) > 0);
        		printf("%d",(num&(1<<6)) > 0);
        		printf("%d",(num&(1<<5)) > 0);
        		printf("%d",(num&(1<<4)) > 0);
        		printf("%d",(num&(1<<3)) > 0);
        		printf("%d",(num&(1<<2)) > 0);
        		printf("%d",(num&(1<<1)) > 0);
        		printf("%d",(num&(1<<0)) > 0);	
		}
	}else{
	printf("Opcion no valida\n");
	}
		
	
	
	return 0;	
}
