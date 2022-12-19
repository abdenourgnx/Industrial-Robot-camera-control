#include "functions.h"

void hexToDecimalArray(uint8_t *bytes, uint32_t &size, char *input) {
  int j = 0;
  size = strlen(input) / 2;
  for (int i = 0; i < size; i++) {
    bytes[i] = hexToDecimal(input + j);
    j += 2;
  }
}

uint8_t hexToDecimal(char *hex) {

  uint8_t decimal = 0;
  int base = 1;

  for (int i = 1; i >= 0; i--) {
    if (hex[i] >= '0' && hex[i] <= '9') {
      decimal += (hex[i] - 48) * base;
      base *= 16;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      decimal += (hex[i] - 55) * base;
      base *= 16;
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      decimal += (hex[i] - 87) * base;
      base *= 16;
    }
  }

  return decimal;
}

// Init uart
int initUART(clib::SerialPort &port) {
  int fd;
  if (!port.Open(_SERIAL_PORT, _SERIAL_BAUDRATE)) {
    printf("couldn't open port");
    return -1;
  }

  printf("Serial open on port %d\n", port.getPort());

  return port.getPort();
}

void sendViscaCommand(clib::SerialPort &port, uint8_t* outData, uint32_t DataSize)
{
    char *buff = new char[200];
    // sprintf(buff, "visca ");
    for (int i = 0; i < DataSize; i++)
    {
      char hex[2];
      decimalToHex(outData[i], hex);
      sprintf((buff + 6) + (i * 2), hex);
    }
    // printf(buff);
    UARTprint(port, buff);
    delete [] buff;
}

// Sending messages trough UART
void UARTprint(clib::SerialPort &port, char msg[]) {

  if (port.SendData((uint8_t *)msg, strlen(msg) + 1) == -1) {
    printf("could not send message\n");
  }
}

// Sending raw bytes trough UART
void UARTsendBytes(clib::SerialPort &port, uint8_t data[], uint32_t data_size) {
  if (port.SendData(data, data_size) == -1) {
    printf("Could not send data bytes \n");
  }
}

//read bytes until certen byte 
void readUntil( clib::SerialPort &port, uint8_t * input_data, uint32_t &data_size, char until) {
  uint8_t *temp = input_data;

  while (true) {
    int numOfBytes = port.ReadData(input_data, data_size);
    if (numOfBytes > 0) 
    {

      for (int i = 0; i < numOfBytes; i++)
      {

        if (input_data[i] == until)
        {
          *(temp++) = (char)input_data[i];
          data_size = numOfBytes;
          temp = input_data;
          return;
        }
        *(temp++) = input_data[i];
      }
      break;
    }
  }
}

  // Convert decimal to Hex char array
void decimalToHex(uint8_t decimalNumber, char *hex) {
    long quotient, remainder;
    int i, j = 1;
    quotient = decimalNumber;

    if (decimalNumber <= 15) {
      hex[0] = '0';
    }

    if (decimalNumber == 0) {
      hex[0] = '0';
      hex[1] = '0';
    }

    while (quotient != 0) {
      remainder = quotient % 16;
      if (remainder < 10)
        hex[j--] = 48 + remainder;
      else
        hex[j--] = 55 + remainder;
      quotient = quotient / 16;
    }

    return;
  }
