
/*
 * serialTest.c:
 *	Very simple program to test the serial port. Expects
 *	the port to be looped back to itself
 *
 * Copyright (c) 2012-2013 Gordon Henderson. <projects@drogon.net>
 ***********************************************************************
 * This file is part of wiringPi:
 *	https://projects.drogon.net/raspberry-pi/wiringpi/
 *
 *    wiringPi is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    wiringPi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with wiringPi.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <string.h> 
#include <wiringPi.h>
#include <wiringSerial.h>

int main ()
{

char serial[20];
//int serialnum = 0;

if( access( "/dev/ttyACM0", F_OK ) != -1 ) {
  strcpy(serial,"/dev/ttyACM0");
//tty = fopen("/dev/ttyACM0","r");
printf("\nACM0\n");
} 

else if( access( "/dev/ttyACM1", F_OK ) != -1 ) {
  strcpy(serial,"/dev/ttyACM1");
//tty = fopen("/dev/ttyACM1","r");
printf("\nACM1\n");
} 

else if( access( "/dev/ttyACM2", F_OK ) != -1 ) {
//tty = fopen("/dev/ttyACM2","r");
 strcpy(serial,"/dev/ttyACM2");
printf("\nACM2\n");
} 

else
  {
 printf("error no serial connection detected");
 return 0;

  }


int fd;
  if ((fd = serialOpen (serial, 115200)) < 0)
  {
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
    return 1;

  }

  if (wiringPiSetup () == -1)
  {
    fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
    return 1 ;
  }
for (;;)
{
	putchar(serialGetchar(fd));
}


return 0;

}

 
