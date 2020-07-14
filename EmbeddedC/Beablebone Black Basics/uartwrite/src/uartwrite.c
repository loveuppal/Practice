/*
 * uartwrite.c
 *
 *  Created on: Jul. 13, 2020
 *      Author: srikanthpendem
 */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>   // using the termios.h library

int main(){
   int file;
   file = open("/dev/ttyO1", O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);

   	  struct termios options;               //The termios structure is vital
      tcgetattr(file, &options);            //Sets the parameters associated with file
      options.c_cflag = B9600 | CS8 | CREAD | CLOCAL;
      options.c_iflag = IGNPAR | ICRNL;    //ignore partity errors, CR -> newline
      tcflush(file, TCIFLUSH);             //discard file information not transmitted
      tcsetattr(file, TCSANOW, &options);  //changes occur immmediately

      unsigned char transmit[18] = "BRO";  //the string to send

      write(file, &transmit,18);       //send the string

      close(file);
       return 0;
}
