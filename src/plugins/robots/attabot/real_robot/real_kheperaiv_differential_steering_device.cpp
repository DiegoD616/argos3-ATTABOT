#include "real_attabot_differential_steering_device.h"
#include <argos3/core/utility/logging/argos_log.h>
#include <memory>

/****************************************/
/****************************************/

CRealAttabotDifferentialSteeringDevice* CRealAttabotDifferentialSteeringDevice::GetInstance() {
   static std::unique_ptr<CRealAttabotDifferentialSteeringDevice> pcInstance(
      new CRealAttabotDifferentialSteeringDevice());
   return pcInstance.get();
}

/****************************************/
/****************************************/

CRealAttabotDifferentialSteeringDevice::CRealAttabotDifferentialSteeringDevice() :
   m_fVelocityLeft(0.0),
   m_fVelocityRight(0.0) {}

/****************************************/
/****************************************/
