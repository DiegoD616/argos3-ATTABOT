#include "real_attabot_battery_sensor.h"

/****************************************/
/****************************************/

CRealAttabotBatterySensor::CRealAttabotBatterySensor(knet_dev_t* pt_dspic) :
   CRealAttabotDevice(pt_dspic) {
}
   
/****************************************/
/****************************************/

CRealAttabotBatterySensor::~CRealAttabotBatterySensor() {
}

/****************************************/
/****************************************/

void CRealAttabotBatterySensor::Do(Real f_elapsed_time) {
   kh4_battery_status(GetBuffer(), GetDSPic());
   m_sReading.AvailableCharge = GetBuffer()[3] / 100.0;
   m_sReading.TimeLeft = -1.0; // TODO
}

/****************************************/
/****************************************/
