#include "real_attabot_ultrasound_sensor.h"

/****************************************/
/****************************************/

CRealAttabotUltrasoundSensor::CRealAttabotUltrasoundSensor(knet_dev_t* pt_dspic) :
   CRealAttabotDevice(pt_dspic) {
   kh4_activate_us(0x1F, GetDSPic());
}
   
/****************************************/
/****************************************/

CRealAttabotUltrasoundSensor::~CRealAttabotUltrasoundSensor() {
   kh4_activate_us(0, GetDSPic());
}

/****************************************/
/****************************************/

#define SETREADING(ARGOSIDX, KH4IDX)                                    \
   m_tReadings[ARGOSIDX].Value = (GetBuffer()[KH4IDX*2] | GetBuffer()[KH4IDX*2+1] << 8);

void CRealAttabotUltrasoundSensor::Do(Real f_elapsed_time) {
   kh4_measure_us(GetBuffer(), GetDSPic());
   SETREADING(0, 2);
   SETREADING(1, 1);
   SETREADING(2, 0);
   SETREADING(3, 4);
   SETREADING(4, 3);
}

/****************************************/
/****************************************/
