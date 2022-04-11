#ifndef REAL_ATTABOT_ENCODER_SENSOR_H
#define REAL_ATTABOT_ENCODER_SENSOR_H

#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_sensor.h>
#include <argos3/plugins/robots/attabot/real_robot/real_attabot_device.h>
#include <argos3/plugins/robots/attabot/real_robot/real_attabot_differential_steering_device.h>

using namespace argos;

class CRealAttabotEncoderSensor :
   public CCI_DifferentialSteeringSensor,
   public CRealAttabotDevice {

public:

   CRealAttabotEncoderSensor(knet_dev_t* pt_dspic);
   
   virtual ~CRealAttabotEncoderSensor();

   virtual void Do(Real f_elapsed_time);

private:

   int m_nEncoderLeft;
   int m_nEncoderRight;
   CRealAttabotDifferentialSteeringDevice* m_pcDevice;

};

#endif // REAL_ATTABOT_ENCODER_SENSOR_H
