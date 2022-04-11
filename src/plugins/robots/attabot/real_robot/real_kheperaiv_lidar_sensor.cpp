#include "real_attabot_lidar_sensor.h"

/****************************************/
/****************************************/

/* Device where the LRF is connected: here USB port */
static char  ATTABOT_LRF_DEVICE[]    = "/dev/ttyACM0";
static UInt8 ATTABOT_POWERON_LASERON = 3;

/****************************************/
/****************************************/

CRealAttabotLIDARSensor::CRealAttabotLIDARSensor(knet_dev_t* pt_dspic) :
   CRealAttabotDevice(pt_dspic),
   m_unPowerLaserState(ATTABOT_POWERON_LASERON) {
   /* Initialize LIDAR */
   m_nDeviceHandle = kb_lrf_Init(ATTABOT_LRF_DEVICE);
   if(m_nDeviceHandle < 0) {
      kb_lrf_Power_Off();
      THROW_ARGOSEXCEPTION("Can't initialize LIDAR");
   }
   if(kb_lrf_GetDistances(m_nDeviceHandle) < 0) {
      kb_lrf_Close(m_nDeviceHandle);
      kb_lrf_Power_Off();
      THROW_ARGOSEXCEPTION("Can't get distance readings from LIDAR");
   }
}

/****************************************/
/****************************************/

CRealAttabotLIDARSensor::~CRealAttabotLIDARSensor() {
   kb_lrf_Close(m_nDeviceHandle);
   kb_lrf_Power_Off();
}

/****************************************/
/****************************************/

void CRealAttabotLIDARSensor::Do(Real f_elapsed_time) {
   if(m_unPowerLaserState != ATTABOT_POWERON_LASERON)
      return;
   kb_lrf_GetDistances(m_nDeviceHandle);
}

/****************************************/
/****************************************/

long CRealAttabotLIDARSensor::GetReading(UInt32 un_idx) const {
   return kb_lrf_DistanceData[LRF_DATA_NB - un_idx - 1];
}

/****************************************/
/****************************************/

size_t CRealAttabotLIDARSensor::GetNumReadings() const {
   return LRF_DATA_NB;
}

/****************************************/
/****************************************/

void CRealAttabotLIDARSensor::PowerOn() {
   m_unPowerLaserState = m_unPowerLaserState | 0x1;
   kb_lrf_Power_On();
}

/****************************************/
/****************************************/

void CRealAttabotLIDARSensor::PowerOff() {
   m_unPowerLaserState = m_unPowerLaserState & 0xFE;
   kb_lrf_Power_Off();
}

/****************************************/
/****************************************/

void CRealAttabotLIDARSensor::LaserOn() {
   m_unPowerLaserState = m_unPowerLaserState | 0x2;
   kb_lrf_Laser_On(m_nDeviceHandle);
}

/****************************************/
/****************************************/

void CRealAttabotLIDARSensor::LaserOff() {
   m_unPowerLaserState = m_unPowerLaserState & 0xFD;
   kb_lrf_Laser_Off(m_nDeviceHandle);
}

/****************************************/
/****************************************/
