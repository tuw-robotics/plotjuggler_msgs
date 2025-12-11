cmake_minimum_required(VERSION 3.5)
project(plotjuggler_msgs)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake QUIET)
find_package(catkin QUIET)

if(catkin_FOUND)
  find_package(catkin REQUIRED COMPONENTS std_msgs  message_generation  )

  add_message_files( FILES
    DataPoint.msg
    DataPoints.msg
    Dictionary.msg
    StatisticsNames.msg
    StatisticsValues.msg
  )

  generate_messages(
    DEPENDENCIES
    std_msgs
  )

  catkin_package( CATKIN_DEPENDS std_msgs  message_generation )

elseif(ament_cmake_FOUND)
  find_package(ament_cmake REQUIRED)
  find_package(rosidl_default_generators REQUIRED)
  find_package(std_msgs REQUIRED)
  find_package(rclcpp REQUIRED)

  rosidl_generate_interfaces(${PROJECT_NAME}
    msg/DataPoint.msg
    msg/DataPoints.msg
    msg/Dictionary.msg
    msg/StatisticsNames.msg
    msg/StatisticsValues.msg
    DEPENDENCIES std_msgs
    ADD_LINTER_TESTS
    )


  add_executable(example example.cpp)

  target_include_directories(example PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

  rosidl_get_typesupport_target(cpp_typesupport_target
    ${PROJECT_NAME} "rosidl_typesupport_cpp")
  target_link_libraries(example "${cpp_typesupport_target}")

  ament_target_dependencies(example rclcpp std_msgs)


  install(DIRECTORY include/
    DESTINATION include/${PROJECT_NAME}
  )

  ament_export_include_directories(
    include
  )
  install(TARGETS
    example
    DESTINATION lib/${PROJECT_NAME})

  ament_export_dependencies(rosidl_default_runtime)
  ament_export_dependencies(std_msgs)
  ament_package()
  else()
  message(FATAL_ERROR "Cannot determine appropriate ROS build system")
endif()
