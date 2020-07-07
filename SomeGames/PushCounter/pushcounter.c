/*This is a simple code that counts every key press */

#include<stdio.h>

int main () {
  int c = 0;			/*Initiate counter variable */
  while(1) {		/* Loop that counts */
      int a;
	   scanf ("%d", &a);
      if (a == 55) {
    	  c = c+1;
    	
	}
        printf ("%d ", c);
    }
}
