#include <stdio.h>
#include <iostream>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "SerialPort.h"
#include "viscaWrapper.h"

#define _SERIAL_PORT "/dev/serial0"
#define _SERIAL_BAUDRATE 115200

int initUART(clib::SerialPort &port);
void UARTprint(clib::SerialPort &port, char msg[]);
void UARTsendBytes(clib::SerialPort &port, uint8_t data[], uint32_t data_size);
void sendViscaCommand();
void decimalToHex(uint8_t decimalNumber ,char* hex);