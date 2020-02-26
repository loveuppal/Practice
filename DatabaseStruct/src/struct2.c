/*
 * readnamesstruct.c
 *
 *  Created on: Feb. 25, 2020
 *      Author: Srikanth Pendem
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct one {
			    /*Member Variables*/
	char firstname[30];
	char lastname[30];
	char city[30];
	};

			    /*Main Function*/
int main() {
	struct one dbasepeople; 			//declare database type os struct one.

	FILE *fpi; 					//creating a file pointer
	fpi = fopen("hey.txt", "r"); 			//opening and reading the file "hey.txt"
	char str1[30],str2[30], str3[30]; 		//creating string variables to store
	fscanf(fpi, "%s %s %s", str1, str2, str3); 	//reading from the text file

		strcpy(dbasepeople.firstname, str1);
		strcpy(dbasepeople.lastname, str2);	//Copying string from text file to struct variable
		strcpy(dbasepeople.city, str3);

	printf("Firstname: %s", dbasepeople.firstname);	//Printing the copied string.
	printf("\nlastname: %s", dbasepeople.lastname);
	printf("\ncity: %s", dbasepeople.city);

	fclose(fpi);					//closing the hey.txt file.

}
