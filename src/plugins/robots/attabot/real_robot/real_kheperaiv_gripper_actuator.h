#ifndef REAL_ATTABOT_GRIPPER_ACTUATOR_H
#define REAL_ATTABOT_GRIPPER_ACTUATOR_H

#include <argos3/plugins/robots/generic/control_interface/ci_gripper_actuator.h>
#include <argos3/plugins/robots/attabot/real_robot/real_attabot_device.h>

using namespace argos;

class CRealAttabotGripperActuator :
   public CCI_GripperActuator,
   public CRealAttabotDevice {

public:

   CRealAttabotGripperActuator(knet_dev_t* pt_dspic);
   
   virtual ~CRealAttabotGripperActuator();

   virtual void Do(Real f_elapsed_time);
   
private:

   knet_dev_t* m_ptArm;
   knet_dev_t* m_ptGripper;

};

#endif
