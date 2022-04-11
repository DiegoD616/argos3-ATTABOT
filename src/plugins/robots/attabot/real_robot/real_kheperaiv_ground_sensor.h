#ifndef REAL_ATTABOT_GROUND_SENSOR_H
#define REAL_ATTABOT_GROUND_SENSOR_H

#include <argos3/plugins/robots/attabot/control_interface/ci_attabot_ground_sensor.h>
#include <argos3/plugins/robots/attabot/real_robot/real_attabot_device.h>

using namespace argos;

class CRealAttabotGroundSensor :
   public CCI_AttabotGroundSensor,
   public CRealAttabotDevice {

public:

   CRealAttabotGroundSensor(knet_dev_t* pt_dspic);
   
   virtual ~CRealAttabotGroundSensor();

   virtual void Do(Real f_elapsed_time);
   
};

#endif // REAL_ATTABOT_GROUND_SENSOR_H
