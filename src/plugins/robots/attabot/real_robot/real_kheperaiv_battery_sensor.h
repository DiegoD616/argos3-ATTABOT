#ifndef REAL_ATTABOT_BATTERY_SENSOR_H
#define REAL_ATTABOT_BATTERY_SENSOR_H

#include <argos3/plugins/robots/generic/control_interface/ci_battery_sensor.h>
#include <argos3/plugins/robots/attabot/real_robot/real_attabot_device.h>

using namespace argos;

class CRealAttabotBatterySensor :
   public CCI_BatterySensor,
   public CRealAttabotDevice {

public:

   CRealAttabotBatterySensor(knet_dev_t* pt_dspic);
   
   virtual ~CRealAttabotBatterySensor();

   virtual void Do(Real f_elapsed_time);
   
};

#endif // REAL_ATTABOT_BATTERY_SENSOR_H
