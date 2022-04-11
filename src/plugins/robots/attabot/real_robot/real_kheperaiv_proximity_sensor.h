#ifndef REAL_ATTABOT_PROXIMITY_SENSOR_H
#define REAL_ATTABOT_PROXIMITY_SENSOR_H

#include <argos3/plugins/robots/attabot/control_interface/ci_attabot_proximity_sensor.h>
#include <argos3/plugins/robots/attabot/real_robot/real_attabot_device.h>

using namespace argos;

class CRealAttabotProximitySensor :
   public CCI_AttabotProximitySensor,
   public CRealAttabotDevice {

public:

   CRealAttabotProximitySensor(knet_dev_t* pt_dspic);
   
   virtual ~CRealAttabotProximitySensor();

   virtual void Do(Real f_elapsed_time);

};

#endif // REAL_ATTABOT_PROXIMITY_SENSOR_H
