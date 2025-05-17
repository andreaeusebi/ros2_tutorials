cmake_minimum_required(VERSION 3.8)
project(cpp_ros_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(my_msgs_pkg REQUIRED) 

add_executable(cpp_pub_node src/cpp_pub_node.cpp)
ament_target_dependencies(cpp_pub_node rclcpp my_msgs_pkg)

add_executable(cpp_sub_node src/cpp_sub_node.cpp)
ament_target_dependencies(cpp_sub_node rclcpp my_msgs_pkg)

install(TARGETS
  cpp_pub_node
  cpp_sub_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
