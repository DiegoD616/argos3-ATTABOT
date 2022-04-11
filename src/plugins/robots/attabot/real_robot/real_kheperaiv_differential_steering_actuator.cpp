#include "real_attabot_differential_steering_actuator.h"
#include <argos3/core/utility/logging/argos_log.h>

/****************************************/
/****************************************/

static int  ATTABOT_POSITIONMARGIN             = 20;
static int  ATTABOT_PID_P                      = 10;
static int  ATTABOT_PID_I                      = 5;
static int  ATTABOT_PID_D                      = 1;
static int  ATTABOT_SPEEDPROFILE_ACC_INC       = 3;
static int  ATTABOT_SPEEDPROFILE_ACC_DIV       = 0;
static int  ATTABOT_SPEEDPROFILE_MIN_SPEED_ACC = 20;
static int  ATTABOT_SPEEDPROFILE_MIN_SPEED_DEC = 1;
static int  ATTABOT_SPEEDPROFILE_MAX_SPEED     = 400;
static Real ATTABOT_SPEED_CM_S_TO_PULSES       = 10.0 / KH4_SPEED_TO_MM_S;

/****************************************/
/****************************************/

CRealAttabotDifferentialSteeringActuator::CRealAttabotDifferentialSteeringActuator(knet_dev_t* pt_dspic) :
  CRealAttabotDevice(pt_dspic) {
  LOG << "[INFO] Differential Steering actuator parameters:" << std::endl;
  kh4_SetPositionMargin(ATTABOT_POSITIONMARGIN, GetDSPic());
  LOG << "[INFO]   Position Margin = "
      << ATTABOT_POSITIONMARGIN
      << std::endl;
  kh4_ConfigurePID(ATTABOT_PID_P,
		   ATTABOT_PID_I,
		   ATTABOT_PID_D, GetDSPic());
  LOG << "[INFO]   PID factors = <"
      << ATTABOT_PID_P << ", "
      << ATTABOT_PID_I << ", "
      << ATTABOT_PID_D << ">"
      << std::endl;
  kh4_SetSpeedProfile(ATTABOT_SPEEDPROFILE_ACC_INC,
		      ATTABOT_SPEEDPROFILE_ACC_DIV,
		      ATTABOT_SPEEDPROFILE_MIN_SPEED_ACC,
		      ATTABOT_SPEEDPROFILE_MIN_SPEED_DEC,
		      ATTABOT_SPEEDPROFILE_MAX_SPEED,
		      GetDSPic());
  LOG << "[INFO]   Speed profile = <"
      << "acc_inc = "       << ATTABOT_SPEEDPROFILE_ACC_INC << ", "
      << "acc_div = "       << ATTABOT_SPEEDPROFILE_ACC_DIV << ", "
      << "min_speed_acc = " << ATTABOT_SPEEDPROFILE_MIN_SPEED_ACC << ", "
      << "min_speed_dec = " << ATTABOT_SPEEDPROFILE_MIN_SPEED_DEC << ", "
      << "max_speed = "     << ATTABOT_SPEEDPROFILE_MAX_SPEED << ">"
      << std::endl;
  kh4_SetMode(kh4RegSpeedProfile, GetDSPic());
  /* Get data structure common to differential steering (for encoder) */
  m_pcDevice = CRealAttabotDifferentialSteeringDevice::GetInstance();
}
   
/****************************************/
/****************************************/

CRealAttabotDifferentialSteeringActuator::~CRealAttabotDifferentialSteeringActuator() {
  kh4_set_speed(0, 0, GetDSPic());
  kh4_SetMode(kh4RegIdle, GetDSPic());
}
   
/****************************************/
/****************************************/

void CRealAttabotDifferentialSteeringActuator::Do(Real f_elapsed_time) {
  kh4_set_speed(m_fCurrentVelocity[0] * ATTABOT_SPEED_CM_S_TO_PULSES,
		m_fCurrentVelocity[1] * ATTABOT_SPEED_CM_S_TO_PULSES,
		GetDSPic());
}

/****************************************/
/****************************************/

void CRealAttabotDifferentialSteeringActuator::SetLinearVelocity(Real f_left_velocity,
                                                                   Real f_right_velocity) {
  /* The speed is passed in cm/s, but the Attabot expects it in mm/s  */
  m_fCurrentVelocity[0] = f_left_velocity;
  m_fCurrentVelocity[1] = f_right_velocity;
  m_pcDevice->SetVelocity(m_fCurrentVelocity);
}

/****************************************/
/****************************************/

