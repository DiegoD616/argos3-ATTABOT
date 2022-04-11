/**
 * @file <argos3/plugins/robots/attabot/simulator/attabot_light_rotzonly_sensor.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef ATTABOT_LIGHT_ROTZONLY_SENSOR_H
#define ATTABOT_LIGHT_ROTZONLY_SENSOR_H

#include <string>
#include <map>

namespace argos {
   class CAttabotLightRotZOnlySensor;
   class CLightSensorEquippedEntity;
}

#include <argos3/plugins/robots/attabot/control_interface/ci_attabot_light_sensor.h>
#include <argos3/core/utility/math/range.h>
#include <argos3/core/utility/math/rng.h>
#include <argos3/core/simulator/space/space.h>
#include <argos3/core/simulator/sensor.h>

namespace argos {

   class CAttabotLightRotZOnlySensor : public CSimulatedSensor,
                                      public CCI_AttabotLightSensor {

   public:

      CAttabotLightRotZOnlySensor();

      virtual ~CAttabotLightRotZOnlySensor() {}

      virtual void SetRobot(CComposableEntity& c_entity);

      virtual void Init(TConfigurationNode& t_tree);

      virtual void Update();

      virtual void Reset();

   protected:

      /** Reference to embodied entity associated to this sensor */
      CEmbodiedEntity* m_pcEmbodiedEntity;

      /** Reference to light sensor equipped entity associated to this sensor */
      CLightSensorEquippedEntity* m_pcLightEntity;

      /** Reference to controllable entity associated to this sensor */
      CControllableEntity* m_pcControllableEntity;

      /** Flag to show rays in the simulator */
      bool m_bShowRays;

      /** Random number generator */
      CRandom::CRNG* m_pcRNG;

      /** Whether to add noise or not */
      bool m_bAddNoise;

      /** Noise range */
      CRange<Real> m_cNoiseRange;

      /** Reference to the space */
      CSpace& m_cSpace;
   };

}

#endif
