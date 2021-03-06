/**
 * @file <argos3/plugins/robots/attabot/simulator/dynamics2d_attabot_model.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef DYNAMICS2D_ATTABOT_MODEL_H
#define DYNAMICS2D_ATTABOT_MODEL_H

namespace argos {
   class CDynamics2DDifferentialSteeringControl;
   class CDynamics2DGripper;
   class CDynamics2DGrippable;
   class CDynamics2DAttabotModel;
}

#include <argos3/plugins/simulator/physics_engines/dynamics2d/dynamics2d_single_body_object_model.h>
#include <argos3/plugins/simulator/physics_engines/dynamics2d/dynamics2d_differentialsteering_control.h>
#include <argos3/plugins/robots/attabot/simulator/attabot_entity.h>

namespace argos {

   class CDynamics2DAttabotModel : public CDynamics2DSingleBodyObjectModel {

   public:

      CDynamics2DAttabotModel(CDynamics2DEngine& c_engine,
                              CAttabotEntity& c_entity);
      virtual ~CDynamics2DAttabotModel();

      virtual void Reset();

      virtual void UpdateFromEntityStatus();
      
   private:

      CAttabotEntity& m_cAttabotEntity;
      CWheeledEntity& m_cWheeledEntity;

      CDynamics2DDifferentialSteeringControl m_cDiffSteering;

      const Real* m_fCurrentWheelVelocity;

   };

}

#endif
