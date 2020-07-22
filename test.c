/*
 * test.c
 *
 *  Created on: Jul. 21, 2020
 *      Author: srikanthpendem
 */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include<string.h>

int main(){
   int file;
   file = open("/dev/ttyO4", O_RDWR | O_NOCTTY);

   	  struct termios options;               //The termios structure is vital
      tcgetattr(file, &options);            //Sets the parameters associated with file
      options.c_cflag = B9600 | CS8 | CREAD | CLOCAL;
      options.c_iflag = IGNPAR | ICRNL;    //ignore partity errors, CR -> newline
      tcflush(file, TCIFLUSH);             //discard file information not transmitted
      tcsetattr(file, TCSANOW, &options);  //changes occur immmediately

      char recieve[256];  			//the string to receive
      char *p; char *q;
while(1) {
	int characters = read(file, (void*) &recieve, 256);       //reception of the string
	sleep(2);
    recieve[characters] = 0;
    p   = strstr(recieve, "$GPGGA");
    //p[characters] = 0;
    while(*p!='\n') {
    	sleep(1.5);
    	printf(" %s", p);
    	}
    fflush(stdout);

}
	close(file);
    return 0;
}
