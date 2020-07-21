/*
 * stringsearch.c
 *
 *  Created on: Jul. 17, 2020
 *      Author: srikanthpendem
---------------------------------------------------------------------------
This code parses GPGGA string and prints the co-ordinates.
Only Latitude and Longitude coordinates are being printed.
GPGGA C Code, GPS Module
This code uses math library, please do not forget to link math library into your eclipse or compile by adding -lm
------------------------------------------------------------------------------------
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>

double deg_conv(double coord) {
	double deg, min, dec, lat;
	dec = coord/100; 	//changes 4337 to 43.37
	deg = truncf(dec);   // Gets the degrees
	min =((dec-deg)*100)/60;
	lat = deg+min;
	return lat;
}

int main () {
	char gprmc[] = "$GPGGA,002802.000,4335.0690,N,07939.9302,W,1,07,1.54,181.0,M,-35.0,M,,*51";

	/*-------------------------------------------*/
	char *p; double loc; double lon; char lat; char lat1;
	double loc1, loc2;
	printf("%s\n", gprmc);

	p = strchr(gprmc, ',')+1;	//Skips GPGGA
	//printf("\n%s\n", p);

	p = strchr(p, ',')+1;		//Skips 002802.000
	//printf("\n%s\n", p);

	loc = atof(p);				// Saves 4335.0690
	//printf("%f ", loc);

	loc1 = deg_conv(loc);		// latitude.

	p = strchr(p, ',')+1;		//Skips 4335.0690
	//printf("\n%s\n", p);

	switch (p[0]) {
	        case 'N':
	        	lat = 'N';
	        	//printf("%c ", lat);	//Prints cardinal directions
	            break;
	        case 'S':
	        	lat = 'S';
	        	//printf("%c ", lat); //Prints cardinal directions
	            break;
	    }

	p = strchr(p, ',')+1;		//N
	//printf("\n%s\n", p);

	lon = atof(p);				// Saves 07939.9302
	//printf("%f ", lon);

	loc2 = deg_conv(lon);		// longitude..


	p = strchr(p, ',')+1;		//Skips 07939.9302
	//printf("\n%s\n", p);

	switch (p[0]) {
	        case 'E':
	        	lat1 = 'E';
	        	//printf("%c ", lat1);	//Prints cardinal directions
	            break;
	        case 'W':
	        	lat1 = 'W';
	        	//printf("%c ", lat1); //Prints cardinal directions
	            break;
	    }

	printf("\n%f %c %f %c\n", loc1,lat,loc2,lat1);	// prints the coordinates parsed
	/*-------------------------------------------*/
	return 0;
}

