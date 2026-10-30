cmake_minimum_required(VERSION 3.8)
project(cpp_topic_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# 生成自定义消息类型
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Item.msg"
)

rosidl_get_typesupport_target(cpp_typesupport_target
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

add_executable(publisher src/publisher.cpp)
target_link_libraries(publisher "${cpp_typesupport_target}")
ament_target_dependencies(publisher rclcpp)

add_executable(subscriber src/subscriber.cpp)
target_link_libraries(subscriber "${cpp_typesupport_target}")
ament_target_dependencies(subscriber rclcpp)

install(TARGETS publisher subscriber
  DESTINATION lib/${PROJECT_NAME})

ament_package()
