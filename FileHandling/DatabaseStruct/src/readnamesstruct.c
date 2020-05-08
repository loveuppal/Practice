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
	struct one dbasepeople[100]; 					//declare database type os struct one.

	FILE *fpi; 							//creating a file pointer
	fpi = fopen("hey.txt", "r"); 					//opening and reading the file "hey.txt"
	char str1[30],str2[30], str3[30]; 				//creating string variables to store

	int currentline = 0;						// initializing counter to read lines
	char store[100];							//variable to sing line of string

	while(fgets(store, 100, fpi) != NULL) {				//Reading till end of the line from the file
	         sscanf(store, "%s %s %s \n",str1,str2,str3);		//Reading strings form the current line into

		strcpy(dbasepeople[currentline].firstname, str1);
		strcpy(dbasepeople[currentline].lastname, str2);	//Copying string from text file to structure variable
		strcpy(dbasepeople[currentline].city, str3);
		currentline++;
	}

	for(int i=0; i<currentline;i++){
		printf("\nFirstname: %s", dbasepeople[i].firstname);	//Printing the copied string.
	       	printf("\nlastname: %s", dbasepeople[i].lastname);
	       	printf("\ncity: %s", dbasepeople[i].city);
}
	fclose(fpi);							//closing the hey.txt file.

}
