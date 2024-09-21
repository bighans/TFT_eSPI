/*

20240921	HEK3	Created

*/

#include <unistd.h>
#include "Arduino.h"
#include <errno.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

	// Run as root.
	seteuid(0);
	
	int iVersion = gpioInitialise();
	if(iVersion==PI_INIT_FAILED) {
		puts("gpioInitialise() failed");
		return -1;
	}
	printf("gpio version %d\n",iVersion);
	try {
		setup();
		while(true) {
			loop();
		}
	} catch (std::exception e) {
		printf("Fatal Error \"%s\": %s\n",e.what(),strerror(errno));
		return -1;
	}
	gpioTerminate();
	return 0;
}