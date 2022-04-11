#include "real_attabot_leds_actuator.h"

/****************************************/
/****************************************/

CRealAttabotLEDsActuator::CRealAttabotLEDsActuator(knet_dev_t* pt_dspic) :
   CRealAttabotDevice(pt_dspic) {
   kh4_SetRGBLeds(0, 0, 0, 0, 0, 0, 0, 0, 0, GetDSPic());
}
   
/****************************************/
/****************************************/

CRealAttabotLEDsActuator::~CRealAttabotLEDsActuator() {
   kh4_SetRGBLeds(0, 0, 0, 0, 0, 0, 0, 0, 0, GetDSPic());
}
   
/****************************************/
/****************************************/

static Real ARGOS2KH4 = 63.0 / 255.0;

void CRealAttabotLEDsActuator::Do(Real f_elapsed_time) {
   kh4_SetRGBLeds(
      m_tSettings[0].GetRed()   * ARGOS2KH4,
      m_tSettings[0].GetGreen() * ARGOS2KH4,
      m_tSettings[0].GetBlue()  * ARGOS2KH4,
      m_tSettings[1].GetRed()   * ARGOS2KH4,
      m_tSettings[1].GetGreen() * ARGOS2KH4,
      m_tSettings[1].GetBlue()  * ARGOS2KH4,
      m_tSettings[2].GetRed()   * ARGOS2KH4,
      m_tSettings[2].GetGreen() * ARGOS2KH4,
      m_tSettings[2].GetBlue()  * ARGOS2KH4,
      GetDSPic());
}

/****************************************/
/****************************************/
