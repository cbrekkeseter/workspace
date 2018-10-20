/*
 * main.c
 *
 *  Created on: Feb 4, 2018
 *      Author: chris
 */

#include <stdio.h>


int main() {

	int c;

	while((c = getchar()) != EOF) {


		if(c == '\n' || c == '\t' || c == ' ')
			printf("\n");

		else
			putchar('.');
	}


	return 0;
}
