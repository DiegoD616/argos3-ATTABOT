/**
 * @file <argos3/plugins/robots/attabot/control_interface/ci_attabot_encoder_sensor.h>
 *
 * @brief This file provides the definition of the Khepera IV encoder sensor. It

 * This file provides the definition of the Khepera IV encoder sensor. It
 * returns the distance covered by the wheels in the last control step.
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef CCI_ATTABOT_ENCODER_SENSOR_H
#define CCI_ATTABOT_ENCODER_SENSOR_H

/* To avoid dependency problems when including */
namespace argos {
   class CCI_AttabotEncoderSensor;
}

#include <argos3/core/control_interface/ci_sensor.h>

namespace argos {

   class CCI_AttabotEncoderSensor : public CCI_Sensor {

   public:

      /**
       * The DTO of the encoder
       * It returns the distance covered by the wheels in the last timestep
       * In addition it returns the value of the wheel distance.
       * i.e. the distance between the two wheels.
       */
      struct SReading {
         Real CoveredDistanceLeftWheel;
         Real CoveredDistanceRightWheel;
         Real WheelAxisLength;
         
         SReading() :
            CoveredDistanceLeftWheel(0.0f),
            CoveredDistanceRightWheel(0.0f),
            WheelAxisLength(0.0f) {}
         
         SReading(Real f_covered_distance_left_wheel,
                  Real f_covered_distance_right_wheel,
                  Real f_wheel_axis_length) :
            CoveredDistanceLeftWheel(f_covered_distance_left_wheel),
            CoveredDistanceRightWheel(f_covered_distance_right_wheel),
            WheelAxisLength(f_wheel_axis_length) {
         }

      };

      /**
       * Destructor
       */
      virtual ~CCI_AttabotEncoderSensor() {}

      /**
       * @brief Returns the reading of the encoder sensor
       * Returns the reading of the encoder sensor
       */
      const SReading& GetReading() const;

#ifdef ARGOS_WITH_LUA
      virtual void CreateLuaState(lua_State* pt_lua_state);

      virtual void ReadingsToLuaState(lua_State* pt_lua_state);
#endif

   protected:

      SReading m_sReading;
   };

}

#endif
