/**
 * @file <argos3/plugins/robots/attabot/simulator/attabot_proximity_default_sensor.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef ATTABOT_PROXIMITY_DEFAULT_SENSOR_H
#define ATTABOT_PROXIMITY_DEFAULT_SENSOR_H

#include <string>
#include <map>

namespace argos {
   class CAttabotProximityDefaultSensor;
}

#include <argos3/plugins/robots/attabot/control_interface/ci_attabot_proximity_sensor.h>
#include <argos3/plugins/robots/generic/simulator/proximity_default_sensor.h>

namespace argos {

   class CAttabotProximityDefaultSensor : public CCI_AttabotProximitySensor,
                                            public CSimulatedSensor {

   public:

      CAttabotProximityDefaultSensor();

      virtual ~CAttabotProximityDefaultSensor();

      virtual void SetRobot(CComposableEntity& c_entity);

      virtual void Init(TConfigurationNode& t_tree);

      virtual void Update();

      virtual void Reset();

   private:

      CProximityDefaultSensor* m_pcProximityImpl;

   };

}

#endif
