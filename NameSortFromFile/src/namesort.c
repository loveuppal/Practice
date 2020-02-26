/*
 * sortnames.c
 *
 *  Created on: Feb. 25, 2020
 *      Author: Srikanth Pendem
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char s[100], t[100], u[100];			//creating array to store data
FILE *fpi;					//creating a file pointer

		/*FUNCTION TO COMPARE STRINGS*/
int compar ( void * a, void * b ) {
     char *pa = *( char**)a;
     char *pb = *( char**)b;
 return strcmp(pa,pb);				//comparing the strings
}
		    /*MAIN FUNCTION*/
int main() {
	int i;
	fpi = fopen("hey.txt", "r");		//opening hey.txt file.
	fscanf(fpi, "%s %s %s", s, t, u);	//reading on to the array
	char *input[] = {s, t, u};		//storing the strings from hey.txt
	int L = sizeof(input)/sizeof(char *);	//Calculating size of the storage string

	/*Printing string before sorting the strings*/
	printf("Before: ");
	for(i=0;i<L;i++)
	{
		printf("\n%s", input[i]);	//Printing Strings
	}

	/*Printing string after sorting the strings using qsort*/
	printf("\n\nAfter: ");
	qsort(input, L, sizeof(char *), compar);
	for(i=0;i<L;i++)
	{
		printf("\n%s", input[i]);	//Printing Strings
	}
        fclose(fpi);.                          // Closing the file.
}
