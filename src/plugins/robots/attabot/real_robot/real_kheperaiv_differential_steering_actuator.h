#ifndef REAL_ATTABOT_DIFFERENTIAL_STEERING_ACTUATOR_H
#define REAL_ATTABOT_DIFFERENTIAL_STEERING_ACTUATOR_H

#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>
#include <argos3/plugins/robots/attabot/real_robot/real_attabot_device.h>
#include <argos3/plugins/robots/attabot/real_robot/real_attabot_differential_steering_device.h>

using namespace argos;

class CRealAttabotDifferentialSteeringActuator :
   public CCI_DifferentialSteeringActuator,
   public CRealAttabotDevice {

public:

   CRealAttabotDifferentialSteeringActuator(knet_dev_t* pt_dspic);
   
   virtual ~CRealAttabotDifferentialSteeringActuator();

   virtual void Do(Real f_elapsed_time);
   
   virtual void SetLinearVelocity(Real f_left_velocity,
                                  Real f_right_velocity);

private:

  CRealAttabotDifferentialSteeringDevice* m_pcDevice;
};

#endif
