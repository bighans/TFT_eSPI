/*

20240921	HEK3	Created

*/

#include "Arduino.h"
#include <errno.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	try {
		setup();
		while(true) {
			loop();
		}
	} catch (std::exception e) {
		printf("Fatal Error \"%s\": %s\n",e.what(),strerror(errno));
		return -1;
	}
	return 0;
}