/*
 * main.c
 *
 *  Created on: Feb 3, 2018
 *      Author: chris
 */

#include <stdio.h>

// Constants
#define	LOWERLIMIT	0		// Lower limit of table
#define UPPERLIMIT	300		// Upper limit of table
#define	STEP		20		// Step size of table

// Prototypes
float fahrenheitToCelcius(int fahrenheit);


int main(){

	int fahr;

	printf("Conversion table from Fahrenheit to Celcius\n\n");
	printf("Fahrenheit:\tCelcius:\n");

	for (fahr = LOWERLIMIT; fahr < UPPERLIMIT; fahr = fahr + STEP) {
		printf("%11d\t%8.2f\n", fahr, fahrenheitToCelcius(fahr));
	}

	return 0;
}




float fahrenheitToCelcius(int fahrenheit) {
	float celcius = 0;

	celcius = ((5.0 / 9.0) * (fahrenheit - 32.0));

	return celcius;
}
