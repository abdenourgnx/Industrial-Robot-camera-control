#include <bits/stdint-uintn.h>
#include <errno.h>
#include <iostream>
#include <memory.h>
#include <ostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "SerialPort.h"
#include <bits/stdint-uintn.h>
#include <cstring>
#include <string.h>
#include "viscaWrapper.h"


#define _SERIAL_PORT "/dev/serial0"
#define _SERIAL_BAUDRATE 115200

//Single byte conversion 
uint8_t hexToDecimal(char *);

//Array Bytes conversion
void hexToDecimalArray(uint8_t* bytes, uint32_t &size, char* input);
int initUART(clib::SerialPort &port);
void UARTprint(clib::SerialPort &port, char msg[]);
void UARTsendBytes(clib::SerialPort &port, uint8_t data[], uint32_t data_size);
void sendViscaCommand();
void decimalToHex(uint8_t decimalNumber ,char* hex);

