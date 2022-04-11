#ifndef REAL_ATTABOT_ULTRASOUND_SENSOR_H
#define REAL_ATTABOT_ULTRASOUND_SENSOR_H

#include <argos3/plugins/robots/attabot/control_interface/ci_attabot_ultrasound_sensor.h>
#include <argos3/plugins/robots/attabot/real_robot/real_attabot_device.h>

using namespace argos;

class CRealAttabotUltrasoundSensor :
   public CCI_AttabotUltrasoundSensor,
   public CRealAttabotDevice {

public:

   CRealAttabotUltrasoundSensor(knet_dev_t* pt_dspic);
   
   virtual ~CRealAttabotUltrasoundSensor();

   virtual void Do(Real f_elapsed_time);

};

#endif // REAL_ATTABOT_ULTRASOUND_SENSOR_H
