/*
  LinuxConsole.cpp - Linux STDIN/STDOUT library for Wiring
  Copyright (c) 2015 Hristo Gochkov.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h>
#include "Arduino.h"

#include "Console.h"
#include <poll.h>

// The one and only.
LinuxConsole Serial;


int LinuxConsole::available(void){

 	pollfd input[1] = {{.fd = 0, .events = POLLIN}};
    int iRetval = poll(input, 1, 0);
	if(iRetval<0)
		throw std::invalid_argument(std::string("Poll returned error ")+std::to_string(errno));
	return 1;
}

int LinuxConsole::peek(void){
	return -1;
}

int LinuxConsole::read(void) {
	uint8_t ch;
	if(::read(0,&ch,1)!=1)
		return -1;
    return ch;
}

void LinuxConsole::flush(){
}

size_t LinuxConsole::write(uint8_t c){
    putchar(c);
    return 1;
}



