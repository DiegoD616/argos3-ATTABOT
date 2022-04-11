#ifndef REAL_ATTABOT_DIFFERENTIAL_STEERING_DEVICE_H
#define REAL_ATTABOT_DIFFERENTIAL_STEERING_DEVICE_H

#include <argos3/core/utility/datatypes/datatypes.h>

using namespace argos;

class CRealAttabotDifferentialSteeringDevice {

public:

   static CRealAttabotDifferentialSteeringDevice* GetInstance();

   ~CRealAttabotDifferentialSteeringDevice() {}

   inline void SetVelocity(Real* f_velocity) {
      m_fVelocityLeft = f_velocity[0];
      m_fVelocityRight = f_velocity[1];
   }

   inline Real GetVelocityLeft() const {
      return m_fVelocityLeft;
   }

   inline Real GetVelocityRight() const {
      return m_fVelocityRight;
   }

private:

   CRealAttabotDifferentialSteeringDevice();
   
private:

   static CRealAttabotDifferentialSteeringDevice* m_pcInstance;
   Real m_fVelocityLeft;
   Real m_fVelocityRight;
};

#endif
