#
# attabot headers
#

# argos3/plugins/robots/attabot/control_interface
set(ARGOS3_HEADERS_PLUGINS_ROBOTS_ATTABOT_CONTROLINTERFACE
  control_interface/ci_attabot_camera_sensor.h
  control_interface/ci_attabot_encoder_sensor.h
  control_interface/ci_attabot_ground_sensor.h
  control_interface/ci_attabot_lidar_sensor.h
  control_interface/ci_attabot_light_sensor.h
  control_interface/ci_attabot_proximity_sensor.h
  control_interface/ci_attabot_ultrasound_sensor.h)
if(BUZZ_FOUND)
  set(ARGOS3_HEADERS_PLUGINS_ROBOTS_ATTABOT_CONTROLINTERFACE
    ${ARGOS3_HEADERS_PLUGINS_ROBOTS_ATTABOT_CONTROLINTERFACE}
    control_interface/buzz_controller_attabot.h)
endif(BUZZ_FOUND)

# argos3/plugins/robots/attabot/simulator
if(ARGOS_BUILD_FOR_SIMULATOR)
  set(ARGOS3_HEADERS_PLUGINS_ROBOTS_ATTABOT_SIMULATOR
    simulator/dynamics2d_attabot_model.h
    simulator/attabot_entity.h
    simulator/attabot_light_rotzonly_sensor.h
    simulator/attabot_measures.h
    simulator/attabot_ground_rotzonly_sensor.h
    simulator/attabot_lidar_default_sensor.h
    simulator/attabot_proximity_default_sensor.h
    simulator/attabot_ultrasound_default_sensor.h)
endif(ARGOS_BUILD_FOR_SIMULATOR)

# argos3/plugins/robots/attabot/real_robot
if(ARGOS_BUILD_FOR STREQUAL "attabot")
  set(ARGOS3_HEADERS_PLUGINS_ROBOTS_ATTABOT_REALROBOT
    real_robot/real_attabot.h
    real_robot/real_attabot_device.h)
endif(ARGOS_BUILD_FOR STREQUAL "attabot")

#
# attabot sources
#
set(ARGOS3_SOURCES_PLUGINS_ROBOTS_ATTABOT
  ${ARGOS3_HEADERS_PLUGINS_ROBOTS_ATTABOT_CONTROLINTERFACE}
  control_interface/ci_attabot_camera_sensor.cpp
  control_interface/ci_attabot_encoder_sensor.cpp
  control_interface/ci_attabot_ground_sensor.cpp
  control_interface/ci_attabot_lidar_sensor.cpp
  control_interface/ci_attabot_light_sensor.cpp
  control_interface/ci_attabot_proximity_sensor.cpp
  control_interface/ci_attabot_ultrasound_sensor.cpp)
if(BUZZ_FOUND)
  set(ARGOS3_SOURCES_PLUGINS_ROBOTS_ATTABOT
    ${ARGOS3_SOURCES_PLUGINS_ROBOTS_ATTABOT}
    control_interface/buzz_controller_attabot.cpp)
endif(BUZZ_FOUND)

if(ARGOS_BUILD_FOR_SIMULATOR)
  set(ARGOS3_SOURCES_PLUGINS_ROBOTS_ATTABOT
    ${ARGOS3_SOURCES_PLUGINS_ROBOTS_ATTABOT}
    ${ARGOS3_HEADERS_PLUGINS_ROBOTS_ATTABOT_SIMULATOR}
    simulator/dynamics2d_attabot_model.cpp
    simulator/attabot_entity.cpp
    simulator/attabot_light_rotzonly_sensor.cpp
    simulator/attabot_measures.cpp
    simulator/attabot_ground_rotzonly_sensor.cpp
    simulator/attabot_lidar_default_sensor.cpp
    simulator/attabot_proximity_default_sensor.cpp
    simulator/attabot_ultrasound_default_sensor.cpp)
  # Compile the graphical visualization only if the necessary libraries have been found
  if(ARGOS_QTOPENGL_FOUND)
    include_directories(${ARGOS_QTOPENGL_INCLUDE_DIRS})
    set(ARGOS3_HEADERS_PLUGINS_ROBOTS_ATTABOT_SIMULATOR
      ${ARGOS3_HEADERS_PLUGINS_ROBOTS_ATTABOT_SIMULATOR}
      simulator/qtopengl_attabot.h)
    set(ARGOS3_SOURCES_PLUGINS_ROBOTS_ATTABOT
      ${ARGOS3_SOURCES_PLUGINS_ROBOTS_ATTABOT}
      simulator/qtopengl_attabot.h
      simulator/qtopengl_attabot.cpp)
  endif(ARGOS_QTOPENGL_FOUND)
endif(ARGOS_BUILD_FOR_SIMULATOR)

if(ARGOS_BUILD_FOR STREQUAL "attabot")
  set(ARGOS3_SOURCES_PLUGINS_ROBOTS_ATTABOT
    ${ARGOS3_SOURCES_PLUGINS_ROBOTS_ATTABOT}
    ${ARGOS3_HEADERS_PLUGINS_ROBOTS_ATTABOT_REALROBOT}
    real_robot/real_attabot.cpp
    real_robot/real_attabot_device.cpp)
endif(ARGOS_BUILD_FOR STREQUAL "attabot")

#
# Create attabot plugin
#
add_library(argos3plugin_${ARGOS_BUILD_FOR}_attabot SHARED ${ARGOS3_SOURCES_PLUGINS_ROBOTS_ATTABOT})
target_link_libraries(argos3plugin_${ARGOS_BUILD_FOR}_attabot
  argos3plugin_${ARGOS_BUILD_FOR}_genericrobot)
if(ARGOS_BUILD_FOR_SIMULATOR)
  target_link_libraries(argos3plugin_${ARGOS_BUILD_FOR}_attabot
    argos3plugin_${ARGOS_BUILD_FOR}_dynamics2d)
  if(ARGOS_QTOPENGL_FOUND)
    target_link_libraries(argos3plugin_${ARGOS_BUILD_FOR}_attabot argos3plugin_${ARGOS_BUILD_FOR}_qtopengl)
  endif(ARGOS_QTOPENGL_FOUND)
else(ARGOS_BUILD_FOR_SIMULATOR)
  target_link_libraries(argos3plugin_${ARGOS_BUILD_FOR}_attabot
    -lattabot)
endif(ARGOS_BUILD_FOR_SIMULATOR)
if(BUZZ_FOUND)
  target_link_libraries(argos3plugin_${ARGOS_BUILD_FOR}_attabot argos3plugin_${ARGOS_BUILD_FOR}_buzz ${BUZZ_LIBRARY})
endif(BUZZ_FOUND)

#
# Create battery monitor
#
if(ARGOS_BUILD_FOR STREQUAL "attabot")
  add_executable(battery real_robot/battery.c)
  target_link_libraries(battery -lattabot)
endif(ARGOS_BUILD_FOR STREQUAL "attabot")

#
# Installation
#
install(FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_ATTABOT_CONTROLINTERFACE} DESTINATION include/argos3/plugins/robots/attabot/control_interface)

if(ARGOS_BUILD_FOR_SIMULATOR)
  install(FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_ATTABOT_SIMULATOR} DESTINATION include/argos3/plugins/robots/attabot/simulator)
  install(FILES simulator/attabot_texture_bottom.png simulator/attabot_texture_side.png simulator/attabot_texture_top.png DESTINATION include/argos3/plugins/simulator/visualizations/qt-opengl/textures)
else(ARGOS_BUILD_FOR_SIMULATOR)
  install(FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_ATTABOT_REALROBOT} DESTINATION include/argos3/plugins/robots/attabot/real_robot)
  install(FILES real_robot/main.cpp DESTINATION include/argos3/plugins/robots/attabot/real_robot)
endif(ARGOS_BUILD_FOR_SIMULATOR)

install(TARGETS argos3plugin_${ARGOS_BUILD_FOR}_attabot
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib/argos3
  ARCHIVE DESTINATION lib/argos3)
