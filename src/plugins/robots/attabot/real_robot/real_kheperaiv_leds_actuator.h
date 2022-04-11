#ifndef REAL_ATTABOT_LEDS_ACTUATOR_H
#define REAL_ATTABOT_LEDS_ACTUATOR_H

#include <argos3/plugins/robots/generic/control_interface/ci_leds_actuator.h>
#include <argos3/plugins/robots/attabot/real_robot/real_attabot_device.h>

using namespace argos;

class CRealAttabotLEDsActuator :
   public CCI_LEDsActuator,
   public CRealAttabotDevice {

public:

   CRealAttabotLEDsActuator(knet_dev_t* pt_dspic);
   
   virtual ~CRealAttabotLEDsActuator();

   virtual void Do(Real f_elapsed_time);
   
};

#endif
