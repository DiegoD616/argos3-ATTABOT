/**
 * @file <argos3/plugins/robots/attabot/control_interface/ci_attabot_proximity_sensor.h>
 *
 * @brief This file provides the definition of the Khepera IV proximity sensor.
 *
 * This file provides the definition of the Khepera IV proximity sensor.
 * The sensors are evenly spaced on a ring around the base of the robot.
 * The readings are normalized between 0 and 1, and are in the following
 * order (seeing the robot from TOP, the camera is the FRONT):
 * 
 *      front
 * 
 * l      0      r
 * e    1   7    i
 * f  2       6  g
 * t    3   5    h
 *        4      t
 * 
 *       back   
 *
 * @author Carlo Pinciroli <ilpincy@gmail.com>
 */

#ifndef CCI_ATTABOT_PROXIMITY_SENSOR_H
#define CCI_ATTABOT_PROXIMITY_SENSOR_H

namespace argos {
   class CCI_AttabotProximitySensor;
}

#include <argos3/core/control_interface/ci_sensor.h>
#include <argos3/core/utility/math/angles.h>

namespace argos {

   class CCI_AttabotProximitySensor : public CCI_Sensor {

   public:

      struct SReading {
         Real Value;
         CRadians Angle;

         SReading() :
            Value(0.0f) {}

         SReading(Real f_value,
                  const CRadians& c_angle) :
            Value(f_value),
            Angle(c_angle) {}
      };

      typedef std::vector<SReading> TReadings;

   public:

      /**
       * Class constructor
       */
      CCI_AttabotProximitySensor();

      /**
       * Class destructor
       */
      virtual ~CCI_AttabotProximitySensor() {}

      /**
       * Returns the readings of this sensor
       */
      const TReadings& GetReadings() const;

#ifdef ARGOS_WITH_LUA
      virtual void CreateLuaState(lua_State* pt_lua_state);

      virtual void ReadingsToLuaState(lua_State* pt_lua_state);
#endif

   protected:

      TReadings m_tReadings;

   };

   std::ostream& operator<<(std::ostream& c_os, const CCI_AttabotProximitySensor::SReading& s_reading);
   std::ostream& operator<<(std::ostream& c_os, const CCI_AttabotProximitySensor::TReadings& t_readings);

}

#endif
