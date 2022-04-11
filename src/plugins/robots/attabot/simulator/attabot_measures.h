/**
 * @file <argos3/plugins/robots/attabot/simulator/attabot_measures.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef ATTABOT_MEASURES_H
#define ATTABOT_MEASURES_H

#include <argos3/core/utility/datatypes/datatypes.h>
#include <argos3/core/utility/math/vector2.h>
#include <argos3/core/utility/math/vector3.h>

using namespace argos;

extern const Real ATTABOT_BASE_RADIUS;
extern const Real ATTABOT_BASE_ELEVATION;
extern const Real ATTABOT_BASE_HEIGHT;
extern const Real ATTABOT_BASE_TOP;

extern const Real ATTABOT_WHEEL_RADIUS;
extern const Real ATTABOT_WHEEL_DISTANCE;
extern const Real ATTABOT_HALF_WHEEL_DISTANCE;

extern const Real ATTABOT_IR_SENSORS_RING_ELEVATION;
extern const Real ATTABOT_IR_SENSORS_RING_RADIUS;
extern const Real ATTABOT_IR_SENSORS_RING_RANGE;

extern const Real ATTABOT_ULTRASOUND_SENSORS_RING_ELEVATION;
extern const Real ATTABOT_ULTRASOUND_SENSORS_RING_RADIUS;
extern const CRange<Real> ATTABOT_ULTRASOUND_SENSORS_RING_RANGE;

extern const CVector2 ATTABOT_IR_SENSORS_GROUND_OFFSET[4];

extern const CVector3 ATTABOT_LEDS_OFFSET[3];

extern const Real ATTABOT_LIDAR_ELEVATION;
extern const Real ATTABOT_LIDAR_SENSORS_FAN_RADIUS;
extern const CRadians ATTABOT_LIDAR_ANGLE_SPAN;
extern const CRange<Real> ATTABOT_LIDAR_SENSORS_RING_RANGE;

#endif
