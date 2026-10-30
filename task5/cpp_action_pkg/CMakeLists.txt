cmake_minimum_required(VERSION 3.8)
project(cpp_action_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# 生成自定义 action 接口：cpp_action_pkg/action/Accumulate.hpp
rosidl_generate_interfaces(${PROJECT_NAME}
  "action/Accumulate.action"
)

rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")

add_executable(server src/server.cpp)
target_link_libraries(server "${cpp_typesupport_target}")
ament_target_dependencies(server rclcpp rclcpp_action)

add_executable(client src/client.cpp)
target_link_libraries(client "${cpp_typesupport_target}")
ament_target_dependencies(client rclcpp rclcpp_action)

install(TARGETS
  server
  client
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
