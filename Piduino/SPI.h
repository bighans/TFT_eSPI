/*
  SPI Master library for Raspberry Pi Arduino.
  Copyright (c) 2015 by Hristo Gochkov

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

#pragma once

#include <stdio.h>
#include "Arduino.h"
#include <pigpio.h>

// #define SPI_HAS_TRANSACTION

//AVR Arduino compatibility
#define SPI_CLOCK_DIV2 SPI0F2DIV(8000000)
#define SPI_CLOCK_DIV4 SPI0F2DIV(4000000)
#define SPI_CLOCK_DIV8 SPI0F2DIV(1000000)
#define SPI_CLOCK_DIV16 SPI0F2DIV(500000)
#define SPI_CLOCK_DIV32 SPI0F2DIV(250000)
#define SPI_CLOCK_DIV64 SPI0F2DIV(175000)
#define SPI_CLOCK_DIV128 SPI0F2DIV(87500)


class SPISettings {
public:
  SPISettings():freq(4000000),mode(0){}
  SPISettings(uint32_t clockFreq, uint8_t bitOrder, uint8_t dataMode) {
    freq = clockFreq;
  }
private:
  uint32_t freq;
  uint8_t mode;
  friend class SPIClass;
};


class SPIClass {
	static int fd;
public:
  static void begin();
  static void end();
  static void setDataMode(uint32_t);
  static void setClockDivider(uint32_t);
  static void setClock(uint32_t);
  static void beginTransaction(SPISettings settings);
  static void setFrequency(uint64_t);
  static uint8_t transfer(uint8_t data);
  static uint8_t transfer16(uint16_t data);
  static void endTransaction(void);
  //no bit order on the pi
  static void setBitOrder(uint32_t);
};

extern SPIClass SPI;
