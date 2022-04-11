/**
 * @file <argos3/plugins/robots/attabot/simulator/attabot_ultrasound_default_sensor.cpp>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#include <argos3/core/simulator/entity/embodied_entity.h>
#include <argos3/core/simulator/entity/composable_entity.h>
#include <argos3/core/simulator/simulator.h>
#include <argos3/plugins/simulator/entities/proximity_sensor_equipped_entity.h>

#include "attabot_ultrasound_default_sensor.h"

namespace argos {

   /****************************************/
   /****************************************/

   class CUltrasoundSensorImpl : public CProximityDefaultSensor {

      static const CRange<Real> RANGE;

   public:

      virtual void SetRobot(CComposableEntity& c_entity) {
         try {
            m_pcEmbodiedEntity = &(c_entity.GetComponent<CEmbodiedEntity>("body"));
            m_pcControllableEntity = &(c_entity.GetComponent<CControllableEntity>("controller"));
            m_pcProximityEntity = &(c_entity.GetComponent<CProximitySensorEquippedEntity>("proximity_sensors[ultrasound]"));
            m_pcProximityEntity->Enable();
         }
         catch(CARGoSException& ex) {
            THROW_ARGOSEXCEPTION_NESTED("Can't set robot for the attabot ultrasound default sensor", ex);
         }
      }

      virtual Real CalculateReading(Real f_distance) {
         return RANGE.NormalizeValue(f_distance);
      }

   };

   const CRange<Real> CUltrasoundSensorImpl::RANGE = CRange<Real>(0.25, 2);

   /****************************************/
   /****************************************/

   CAttabotUltrasoundDefaultSensor::CAttabotUltrasoundDefaultSensor() :
      m_pcUltrasoundImpl(new CUltrasoundSensorImpl()) {}

   /****************************************/
   /****************************************/

   CAttabotUltrasoundDefaultSensor::~CAttabotUltrasoundDefaultSensor() {
      delete m_pcUltrasoundImpl;
   }

   /****************************************/
   /****************************************/

   void CAttabotUltrasoundDefaultSensor::SetRobot(CComposableEntity& c_entity) {
      try {
         m_pcUltrasoundImpl->SetRobot(c_entity);
      }
      catch(CARGoSException& ex) {
         THROW_ARGOSEXCEPTION_NESTED("Can't set robot for the attabot ultrasound default sensor", ex);
      }
   }

   /****************************************/
   /****************************************/

   void CAttabotUltrasoundDefaultSensor::Init(TConfigurationNode& t_tree) {
      m_pcUltrasoundImpl->Init(t_tree);
   }

   /****************************************/
   /****************************************/

   void CAttabotUltrasoundDefaultSensor::Update() {
      m_pcUltrasoundImpl->Update();
      for(size_t i = 0; i < m_pcUltrasoundImpl->GetReadings().size(); ++i) {
         m_tReadings[i].Value = m_pcUltrasoundImpl->GetReadings()[i];
      }
   }

   /****************************************/
   /****************************************/

   void CAttabotUltrasoundDefaultSensor::Reset() {
      m_pcUltrasoundImpl->Reset();
   }

   /****************************************/
   /****************************************/

   REGISTER_SENSOR(CAttabotUltrasoundDefaultSensor,
                   "attabot_ultrasound", "default",
                   "Carlo Pinciroli [ilpincy@gmail.com]",
                   "1.0",
                   "The attabot ultrasound sensor.",
                   "This sensor accesses the attabot ultrasound sensor. For a complete description\n"
                   "of its usage, refer to the ci_attabot_ultrasound_sensor.h interface. For the XML\n"
                   "configuration, refer to the default proximity sensor.\n",
                   "Usable"
		  );

}
