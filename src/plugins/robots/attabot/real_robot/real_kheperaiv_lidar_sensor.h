#ifndef REAL_ATTABOT_LIDAR_SENSOR_H
#define REAL_ATTABOT_LIDAR_SENSOR_H

#include <argos3/plugins/robots/attabot/control_interface/ci_attabot_lidar_sensor.h>
#include <argos3/plugins/robots/attabot/real_robot/real_attabot_device.h>

using namespace argos;

class CRealAttabotLIDARSensor :
   public CCI_AttabotLIDARSensor,
   public CRealAttabotDevice {

public:

   CRealAttabotLIDARSensor(knet_dev_t* pt_dspic);
   
   virtual ~CRealAttabotLIDARSensor();

   virtual void Do(Real f_elapsed_time);

   virtual long GetReading(UInt32 un_idx) const;

   virtual size_t GetNumReadings() const;

   virtual void PowerOn();
   
   virtual void PowerOff();

   virtual void LaserOn();

   virtual void LaserOff();
   
private:

   /** LIDAR board handle */
   int m_nDeviceHandle;

   /** Power and Laser states */
   UInt8 m_unPowerLaserState;

};

#endif // REAL_ATTABOT_LIDAR_SENSOR_H
