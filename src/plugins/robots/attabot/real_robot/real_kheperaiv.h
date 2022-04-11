#ifndef REAL_ATTABOT_H
#define REAL_ATTABOT_H

#include <argos3/core/real_robot/real_robot.h>
#include <argos3/plugins/robots/attabot/real_robot/real_attabot_device.h>
#include <attabot/attabot.h>

using namespace argos;

class CRealAttabot : public CRealRobot {

public:

   CRealAttabot();
   virtual ~CRealAttabot();
   virtual void InitRobot();
   virtual void Destroy();
   virtual CCI_Actuator* MakeActuator(const std::string& str_name);
   virtual CCI_Sensor* MakeSensor(const std::string& str_name);
   virtual void Sense(Real f_elapsed_time);
   virtual void Act(Real f_elapsed_time);

   inline knet_dev_t* GetDSPic() const {
      return m_ptDSPic;
   }

private:

   knet_dev_t* m_ptDSPic;
   std::vector<CRealAttabotDevice*> m_vecActuators;
   std::vector<CRealAttabotDevice*> m_vecSensors;
};

#endif // REAL_ATTABOT_H
