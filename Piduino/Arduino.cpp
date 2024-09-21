/*

	20240921	HEK3	Pin conversions.

*/

#include "Arduino.h"

#include <exception>
#include <string>

void pinMode(uint8_t u8tPin, uint8_t u8tMode) {
	if(gpioSetMode(u8tPin,u8tMode)!=0)
		throw std::invalid_argument(std::string("pinMode(uint8_t u8tPin, uint8_t u8tMode) returned error ")+std::to_string(u8tMode));
}

void digitalWrite(uint8_t u8tPin, uint8_t u8tValue) {;//47.5ns direct register write takes 23ns
	if(gpioWrite(u8tPin,u8tValue)!=0)
		throw std::invalid_argument(std::string("pinMode(uint8_t u8tPin, uint8_t u8tValue) returned error ")+std::to_string(u8tValue));
}

int digitalRead(uint8_t) {;//110ns direct register read takes 74ns
	return 0;
}
