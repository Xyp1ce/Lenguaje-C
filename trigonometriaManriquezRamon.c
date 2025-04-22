/* 
   Ramon Manriquez 
   24 02 2025
   Calculo del teorema de pitagoras
*/

#include <stdio.h>
#include <math.h>

int main(){
	// Declaracion de constantes
	#define RADGRAD 180 / 3.1416

	// Inicializacion de variables
	double base, altura, hipotenusa, theta, beta, area, perimetro;
	
	// Pedimos el valor de la base y altura
	printf("Ingrese el valor de la base: ");
	scanf("%lf",&base);
	printf("Ingrese el valor de la altura: ");
	scanf("%lf",&altura);

	// Realizamos calculos 

	// Hipotenusa
	hipotenusa = sqrt(pow(base,2) + pow(altura,2));
	printf("Hipotenusa: %.2lf\n", hipotenusa);	

	// Area
	area = (base * altura) / 2;
	printf("Area: %.2lf\n", area);	

	// Perimetro
	perimetro = base + altura + hipotenusa;
	printf("Perimetro: %.2lf\n", perimetro);

	// Theta y Beta
	theta = atan(altura/base) * RADGRAD;
	printf("Theta: %.2lf\n", theta);
	beta = 	atan(base/altura) * RADGRAD;	
	printf("Beta: %.2lf\n", beta);
	return 0;
}
