#include "real_attabot_gripper_actuator.h"

/****************************************/
/****************************************/

CRealAttabotGripperActuator::CRealAttabotGripperActuator(knet_dev_t* pt_dspic) :
   CRealAttabotDevice(pt_dspic) {
   /* Initialize gripper */
   kgripper_init();
   /* Open sockets to gripper components */
   m_ptArm = knet_open( "Kgripper:Arm", KNET_BUS_I2C, 0, NULL);
   if(m_ptArm == NULL) {
      THROW_ARGOSEXCEPTION("Can't connect to Attabot arm");
   }
   m_ptGripper = knet_open( "Kgripper:Gripper", KNET_BUS_I2C, 0, NULL);
   if(m_ptArm == NULL) {
      THROW_ARGOSEXCEPTION("Can't connect to Attabot gripper");
   }
}
   
/****************************************/
/****************************************/

CRealAttabotGripperActuator::~CRealAttabotGripperActuator() {
}
   
/****************************************/
/****************************************/

void CRealAttabotGripperActuator::Do(Real f_elapsed_time) {
}

/****************************************/
/****************************************/
