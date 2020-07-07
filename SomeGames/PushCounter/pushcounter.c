#include<stdio.h>
int main ()
{
  
  int c = 0;
  for(c=0;c<=10;) {
      int a;
	   scanf ("%d", &a);
      if (a == 55) {
    	  c = c+1;
    	
	}
        printf ("%d ", c);
    }
}
