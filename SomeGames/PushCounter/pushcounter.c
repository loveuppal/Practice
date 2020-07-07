/*This is a simple code that counts every key press */

#include<stdio.h>

int main () {
  int c = 0;			/*Initiate counter variable */
  while(1) {			/* Forever Loop that counts */
	int a;			/* Variable to scan*/
	scanf ("%d", &a);	/* Scans input */
      if (a == 55) {		/* If '55' is given*/
    	  c = c+1;		/* Count increment*/
	}
        printf ("%d ", c);	/* Print the counted number*/
    }
}
