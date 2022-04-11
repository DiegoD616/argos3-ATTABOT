#include "real_attabot.h"
#include "real_attabot_differential_steering_actuator.h"
#include "real_attabot_leds_actuator.h"
#include "real_attabot_battery_sensor.h"
#include "real_attabot_camera_sensor.h"
#include "real_attabot_encoder_sensor.h"
#include "real_attabot_ground_sensor.h"
#include "real_attabot_lidar_sensor.h"
#include "real_attabot_proximity_sensor.h"
#include "real_attabot_ultrasound_sensor.h"
#include <argos3/core/utility/logging/argos_log.h>

/****************************************/
/****************************************/

CRealAttabot::CRealAttabot() :
   m_ptDSPic(NULL) {
}

/****************************************/
/****************************************/

CRealAttabot::~CRealAttabot() {
}

/****************************************/
/****************************************/

void CRealAttabot::InitRobot() {
   /* Initialize Attabot */
   if(kh4_init(0,NULL) != 0) {
      THROW_ARGOSEXCEPTION("Error initializing the Attabot subsystem (kh4_init)");
   }
   /* Open robot socket and store the handle in its pointer */
   m_ptDSPic = knet_open("Attabot:dsPic", KNET_BUS_I2C, 0, NULL);
   if(m_ptDSPic == NULL) {
      THROW_ARGOSEXCEPTION("Error initializing communication with Attabot dsPic (knet_open)");
   }
   /* Make sure to start from a clean state */
   /* It's weird to call Destroy() here, but all it does is making
    * sure that at this stage the robot has everything switched off */
   Destroy();
}

/****************************************/
/****************************************/

void CRealAttabot::Destroy() {
   /* Stop wheels */
   kh4_set_speed(0, 0, m_ptDSPic);
   kh4_SetMode(kh4RegIdle, m_ptDSPic );
   /* Switch LEDs off */
   kh4_SetRGBLeds(0,0,0,0,0,0,0,0,0, m_ptDSPic);
   /* Switch ultrasound sensor off */
   kh4_activate_us(0, m_ptDSPic);
}

/****************************************/
/****************************************/

#define MAKE_ACTUATOR(CLASSNAME, TAG)					\
   if(str_name == TAG) {						\
      CLASSNAME* pcAct =						\
         new CLASSNAME(GetDSPic());					\
      m_vecActuators.push_back(pcAct);					\
      LOG << "[INFO] Initialized \"" << TAG << "\" actuator " << std::endl; \
      return pcAct;							\
   }

CCI_Actuator* CRealAttabot::MakeActuator(const std::string& str_name) {
   MAKE_ACTUATOR(CRealAttabotDifferentialSteeringActuator,
                 "differential_steering");
   MAKE_ACTUATOR(CRealAttabotLEDsActuator,
                 "leds");
   return NULL;
}

/****************************************/
/****************************************/

#define MAKE_SENSOR(CLASSNAME, TAG)					\
   if(str_name == TAG) {						\
      CLASSNAME* pcSens =						\
         new CLASSNAME(GetDSPic());					\
      m_vecSensors.push_back(pcSens);					\
      LOG << "[INFO] Initialized \"" << TAG << "\" sensor " << std::endl; \
      return pcSens;							\
   }

CCI_Sensor* CRealAttabot::MakeSensor(const std::string& str_name) {
   MAKE_SENSOR(CRealAttabotBatterySensor,
               "attabot_battery");
   MAKE_SENSOR(CRealAttabotCameraSensor,
               "camera");
   MAKE_SENSOR(CRealAttabotEncoderSensor,
	       "differential_steering");
   MAKE_SENSOR(CRealAttabotGroundSensor,
               "attabot_ground");
   MAKE_SENSOR(CRealAttabotLIDARSensor,
               "attabot_lidar");
   MAKE_SENSOR(CRealAttabotProximitySensor,
               "attabot_proximity");
   MAKE_SENSOR(CRealAttabotUltrasoundSensor,
               "attabot_ultrasound");
   return NULL;
}

/****************************************/
/****************************************/

void CRealAttabot::Sense(Real f_elapsed_time) {
   for(size_t i = 0; i < m_vecSensors.size(); ++i) {
      m_vecSensors[i]->Do(f_elapsed_time);
   }
}

/****************************************/
/****************************************/

void CRealAttabot::Act(Real f_elapsed_time) {
   for(size_t i = 0; i < m_vecActuators.size(); ++i) {
      m_vecActuators[i]->Do(f_elapsed_time);
   }
}

/****************************************/
/****************************************/
