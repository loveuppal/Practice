/*
 * Name		: gpiotoggle.c
 * Author	: Srikanth Pendem (Adapted from AREmbedded's gpio_led.c program)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {

 system("echo out > /sys/class/gpio/gpio68/direction");		//Enabling GPIO68 to output(P8.10(Pin))
 
 sleep(1);

 int counter=0;							//creating a counter
 
 while(1) {
  
      
      else
         system("echo 0 > /sys/class/gpio/gpio68/value");	//GPIO PIN > LOW if the counter counts a odd integer
         counter++;						//Count continues.
         
         sleep(1);						//Delay of 1 second on every HIGH and LOW
    }
}



