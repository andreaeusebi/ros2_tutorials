cmake_minimum_required(VERSION 3.8)
project(cpp_custom_srv_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(my_srvs_pkg REQUIRED)

add_executable(cpp_custom_server src/cpp_custom_server.cpp)
ament_target_dependencies(cpp_custom_server rclcpp my_srvs_pkg)

add_executable(cpp_custom_client src/cpp_custom_client.cpp)
ament_target_dependencies(cpp_custom_client rclcpp my_srvs_pkg)

install(TARGETS
    cpp_custom_server
    cpp_custom_client
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
