/**
 * @file <argos3/plugins/robots/attabot/simulator/attabot_measures.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#include "attabot_measures.h"

/****************************************/
/****************************************/

const Real ATTABOT_BASE_RADIUS    = 0.0704;
const Real ATTABOT_BASE_ELEVATION = 0.0047;
const Real ATTABOT_BASE_HEIGHT    = 0.053;
const Real ATTABOT_BASE_TOP       = ATTABOT_BASE_ELEVATION + ATTABOT_BASE_HEIGHT;

const Real ATTABOT_WHEEL_RADIUS        = 0.021;
const Real ATTABOT_WHEEL_DISTANCE      = 0.1054;
const Real ATTABOT_HALF_WHEEL_DISTANCE = ATTABOT_WHEEL_DISTANCE * 0.5;

const Real ATTABOT_IR_SENSORS_RING_ELEVATION = 0.0145;
const Real ATTABOT_IR_SENSORS_RING_RADIUS    = ATTABOT_BASE_RADIUS;
const Real ATTABOT_IR_SENSORS_RING_RANGE     = 0.12;

const Real ATTABOT_ULTRASOUND_SENSORS_RING_ELEVATION = 0.0145;
const Real ATTABOT_ULTRASOUND_SENSORS_RING_RADIUS    = ATTABOT_BASE_RADIUS;
const CRange<Real> ATTABOT_ULTRASOUND_SENSORS_RING_RANGE(0.25, 2.0);

const CVector2 ATTABOT_IR_SENSORS_GROUND_OFFSET[4] = {
   CVector2(0.06140,  0.01),
   CVector2(0.02060,  0.059),
   CVector2(0.02060, -0.059),
   CVector2(0.06140, -0.01)
};

const CVector3 ATTABOT_LEDS_OFFSET[3] = {
   CVector3( 0.04,  0.025, ATTABOT_BASE_TOP),
   CVector3(-0.05,  0.000, ATTABOT_BASE_TOP),
   CVector3( 0.04, -0.025, ATTABOT_BASE_TOP)
};

const Real ATTABOT_LIDAR_CENTER_ELEVATION   = 0.084;
const Real ATTABOT_LIDAR_ELEVATION          = ATTABOT_BASE_TOP + ATTABOT_LIDAR_CENTER_ELEVATION;
const Real ATTABOT_LIDAR_SENSORS_FAN_RADIUS = ATTABOT_BASE_RADIUS;
const CRadians ATTABOT_LIDAR_ANGLE_SPAN(ToRadians(CDegrees(210.0)));
const CRange<Real> ATTABOT_LIDAR_SENSORS_RING_RANGE(0.02, 4.0);

/****************************************/
/****************************************/
