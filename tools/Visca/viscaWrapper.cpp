
#include "viscaWrapper.h"
#include <cstring>

Vwrapper::Vwrapper() { memset(outData, 0, 128); }
Vwrapper::~Vwrapper() {}

void Vwrapper::directZoom(int index) {

  if (index > 40)
    index = 40;

  if (index < 0)
    index = 0;


  parser.Encode_Command(visca::ViscaPackets::COMMAND_CAM_Zoom_Direct, outData,
                        DataSize, 1, zoom_commands[index][4],
                        zoom_commands[index][5], zoom_commands[index][6],
                        zoom_commands[index][7]);

}

void Vwrapper::zoomCombinedMode() {
  parser.Encode_Command(visca::ViscaPackets::COMMAND_CAM_DZoom_Combine_Mode,
                        outData, DataSize, 1);
}

void Vwrapper::stabilizationOnOff(bool state) {
  if (state) {
    parser.Encode_Command(visca::ViscaPackets::COMMAND_CAM_Stabilizer_On,
                          outData, DataSize, 1);
  } else {
    parser.Encode_Command(visca::ViscaPackets::COMMAND_CAM_Stabilizer_Off,
                          outData, DataSize, 1);
  }
}


void enableAF()
{
    parser.Encode_Command(visca::ViscaPackets::COMMAND_CAM_Focus_Auto_Focus_On, 
            outData, DataSize, 1);
}
