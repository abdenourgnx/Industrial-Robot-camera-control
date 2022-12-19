#include "main.h"

clib::SerialPort port;
Vwrapper wrapper;

int main(int argc, char const *argv[])
{

  initUART(port);

  while (true)
  {

    wrapper.zoomCombinedMode();
    wrapper.directZoom(20);
    sendViscaCommand();
    
    usleep(300 * 1000);
  }

  return 0;
}

void sendViscaCommand()
{
    char *buff = new char[200];
    sprintf(buff, "visca ");
    for (int i = 0; i < wrapper.DataSize; i++)
    {
      char hex[2];
      decimalToHex(wrapper.outData[i], hex);
      sprintf((buff + 6) + (i * 2), hex);
    }
    // printf(buff);
    UARTprint(port, buff);
    delete [] buff;
}


//Init uart 
int initUART(clib::SerialPort &port)
{
  int fd;
  if (!port.Open(_SERIAL_PORT, _SERIAL_BAUDRATE))
  {
    printf("couldn't open port");
    return -1;
  }

  printf("Serial open on port %d\n", port.getPort());

  return port.getPort();
}

// Sending messages trough UART
void UARTprint(clib::SerialPort &port, char msg[])
{

  if (port.SendData((uint8_t *)msg, strlen(msg) + 1) == -1)
  {
    printf("could not send message\n");
  }
}

// Sending raw bytes trough UART
void UARTsendBytes(clib::SerialPort &port, uint8_t data[], uint32_t data_size)
{
  if (port.SendData(data, data_size) == -1)
  {
    printf("Could not send data bytes \n");
  }
}


//Convert decimal to Hex char array
void decimalToHex(uint8_t decimalNumber, char *hex)
{
  long quotient, remainder;
  int i, j = 1;
  quotient = decimalNumber;

  if (decimalNumber <= 15)
  {
    hex[0] = '0';
  }

  if (decimalNumber == 0)
  {
    hex[0] = '0';
    hex[1] = '0';
  }

  while (quotient != 0)
  {
    remainder = quotient % 16;
    if (remainder < 10)
      hex[j--] = 48 + remainder;
    else
      hex[j--] = 55 + remainder;
    quotient = quotient / 16;
  }

  return;
}
