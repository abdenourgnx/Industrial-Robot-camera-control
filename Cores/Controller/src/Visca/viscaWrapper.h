#pragma once 
/*
 * Visca library wrapper 
 * Author : kharouri abdennour 
 *
 *
 * discrepion: 
 * this wrapeer is used on top of visca library to facilitate working with it 
 *
*/



#include "SerialPort.h"
#include <bits/stdint-uintn.h>
#include <sys/types.h>
#include "ViscaProtocolParser.h"



class Vwrapper{

    public:

        visca::ViscaProtocolParser parser; 

        uint8_t inputData[128];
        uint8_t outData[128];
        uint32_t DataSize;

        uint32_t param1 = 0;
        uint32_t param2 = 0;
        uint32_t param3 = 0;
        uint32_t param4 = 0;
        uint32_t param5 = 0;
        uint32_t param6 = 0;
        uint32_t param7 = 0;
        uint32_t param8 = 0;
        uint32_t param9 = 0;
        uint32_t param10 = 0;

        uint8_t zoom_commands[41][9] = // Array of ZOOM commands.
            {{0x81, 0x01, 0x04, 0x47, 0x00, 0x00, 0x00, 0x00, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x01, 0x06, 0x0A, 0x01, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x02, 0x00, 0x06, 0x03, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x02, 0x06, 0x02, 0x08, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x02, 0x0A, 0x01, 0x0D, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x02, 0x0D, 0x01, 0x03, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x02, 0x0F, 0x06, 0x0D, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x01, 0x06, 0x01, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x03, 0x00, 0x0D, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x04, 0x08, 0x06, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x05, 0x0D, 0x07, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x07, 0x00, 0x09, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x08, 0x02, 0x00, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x09, 0x02, 0x00, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x0A, 0x00, 0x0A, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x0A, 0x0D, 0x0D, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x0B, 0x09, 0x0C, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x0C, 0x04, 0x06, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x0C, 0x0D, 0x0C, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x0D, 0x06, 0x00, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x0D, 0x0D, 0x04, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x0E, 0x03, 0x09, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x0E, 0x09, 0x00, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x0E, 0x0D, 0x0C, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x0F, 0x01, 0x0E, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x0F, 0x05, 0x07, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x0F, 0x08, 0x0A, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x0F, 0x0B, 0x06, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x03, 0x0F, 0x0D, 0x0C, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x04, 0x00, 0x00, 0x00, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x06, 0x00, 0x00, 0x00, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x06, 0x0A, 0x08, 0x00, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x07, 0x00, 0x00, 0x00, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x07, 0x03, 0x00, 0x00, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x07, 0x05, 0x04, 0x00, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x07, 0x06, 0x0C, 0x00, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x07, 0x08, 0x00, 0x00, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x07, 0x08, 0x0C, 0x00, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x07, 0x09, 0x08, 0x00, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x07, 0x0A, 0x00, 0x00, 0xFF},
             {0x81, 0x01, 0x04, 0x47, 0x07, 0x0A, 0x0C, 0x00, 0xFF}};

        Vwrapper();

        ~Vwrapper();

        //Fill the Serial Data with the right bytes depending on the index 
        void directZoom(int index);
        
        //Fill the Serial Data with the Bytes sequence for Combined mode zoom
        void zoomCombinedMode();

        //Camera stabilization On/off
        void stabilizationOnOff(bool state);

        //Enable autoFocus
        void enableAF(void);

};


         




