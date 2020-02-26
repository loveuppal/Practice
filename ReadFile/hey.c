/*
 * hey.c
 *
 *  Created on: Feb. 24, 2020
 *      Author: shaan
 */


#include<stdio.h>
#include<stdlib.h>
int main() {
char s[100];
char t[100];
FILE *fpi;
fpi = fopen("hey.txt", "r");
	fscanf(fpi, "%s %s %s", s, t);
	printf("%s \n", s);
	printf("%s \n", t );
	fclose(fpi);
}
