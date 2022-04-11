/**
 * @file <argos3/plugins/robots/attabot/simulator/attabot_ultrasound_default_sensor.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef ATTABOT_ULTRASOUND_DEFAULT_SENSOR_H
#define ATTABOT_ULTRASOUND_DEFAULT_SENSOR_H

#include <string>
#include <map>

namespace argos {
   class CAttabotUltrasoundDefaultSensor;
}

#include <argos3/plugins/robots/attabot/control_interface/ci_attabot_ultrasound_sensor.h>
#include <argos3/plugins/robots/generic/simulator/proximity_default_sensor.h>

namespace argos {

   class CAttabotUltrasoundDefaultSensor : public CCI_AttabotUltrasoundSensor,
                                             public CSimulatedSensor {

   public:

      CAttabotUltrasoundDefaultSensor();

      virtual ~CAttabotUltrasoundDefaultSensor();

      virtual void SetRobot(CComposableEntity& c_entity);

      virtual void Init(TConfigurationNode& t_tree);

      virtual void Update();

      virtual void Reset();

   private:

      CProximityDefaultSensor* m_pcUltrasoundImpl;

   };

}

#endif
