/*
 * readfile.c
 *
 *  Created on: Feb. 24, 2020
 *      Author: shaan
 */


#include<stdio.h>
#include<stdlib.h>
			/*MAIN FUNCTION*/
int main() {
char s[100];				//creating string variable
char t[100];
	
FILE *fpi;				//creating the file pointer
fpi = fopen("hey.txt", "r");		//opeining the hey.txt file
	
	fscanf(fpi, "%s %s %s", s, t);	//reading the strings in the hey.txt file
	
	printf("%s \n", s);		//printing the first string
	printf("%s \n", t );		//prinintg the second string
	
	fclose(fpi);			//closing the file
}
