/*
	Manriquez Ramon
	2210376
	Validacion de datos junto con inicio de sesion en matrices tridimencional
*/

#include <stdio.h>

#define LONGITUD_USUARIOS 3
#define LONGITUD_CAMPOS 5
#define LONGITUD_CADENAS 100

void inicializar(char *datos, int x,int y,int z);
void apellido(char *datos, int LONGITUD_CARACTERES);
void capturarDatos(char *datos, int LONGITUD_CARACTERES);
void imprimirDatos(char *datos);

int main(void)
{
	int i;
	char datos[LONGITUD_USUARIOS][LONGITUD_CAMPOS][LONGITUD_CADENAS];
	
	inicializar(&datos[0][0][0],LONGITUD_USUARIOS,LONGITUD_CAMPOS,LONGITUD_CADENAS);
	for( i = 0 ; i<LONGITUD_USUARIOS; i++)
	{
		printf("\n USUARIO %d",i+1);
		capturarDatos(&datos[i][0][0],LONGITUD_CADENAS);
	}
	for( i = 0 ; i<LONGITUD_USUARIOS; i++)
	{
		printf("\n USUARIO %d",i+1);
		imprimirDatos(&datos[i][0][0]);
	}
}
void capturarDatos(char *usuario,int caracteres)
{
	printf("\n Nombre: ");
	fgets( &usuario[0],caracteres,stdin);
	printf("\n Apellido: ");
	fgets( &usuario[100],caracteres,stdin);
	printf("\n Fecha: ");
	fgets( &usuario[200],caracteres,stdin);	
	printf("\n Nombre de usuario: ");
	fgets( &usuario[300],caracteres,stdin);
	printf("\n Contraseña: ");
	fgets( &usuario[400],caracteres,stdin);	
}
void imprimirDatos(char *usuario)
{
	printf("\n Nombre: %s",&usuario[0]);
	printf("\n Apellido: %s",&usuario[100]);
	printf("\n Fecha: %s",&usuario[200]);	
	printf("\n Nombre de usuario: %s",&usuario[300]);
	printf("\n Contraseña: %s",&usuario[400]);
}
void inicializar(char *dato,int x,int y,int z)
{
	// Iniciamos todos los caracteres a un caracter nulo
	int i,j,k;
	
	for(i = 0;i < x;i++)
	{
		for(j = 0;j < y;j++)
		{
			for(k = 0; k < z; k++)
			{
				dato[(i*y*z)+(j*z)+k] = '\0';
				//printf("\n [%d][%d][%d] %d",i,j,k,(i*y*z)+(j*z)+k);
			}
		}
	}
	
}
void apellido(char *cadena,int longitud)
{
	printf("\n Ingresa apellido: ");
	fgets(cadena,longitud,stdin);	
}
