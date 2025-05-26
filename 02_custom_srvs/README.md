# ROS2 Tutorial 02 - Custom Services
This tutorial explains how to define and use custom services in ROS2, for both Python and C++.

Link to the video tutorial [here]().

## Setup & Build
1. Clone repo within a ROS2 source folder (folder name must be "src").
2. Move to workspace root folder and build using `colcon build`.
3. Source the local ROS environment using `source install/setup.bash`.
4. Verify that the messages have been correctly built using `ros2 interface show my_srvs_pkg/srv/DivideIntegers`.

## Run the nodes
Feel free to inspect the Cpp and Python nodes to see how to use custom services in ROS2.

Try runnning the Cpp nodes using:
- In one terminal, run the server node: `ros2 run cpp_custom_srv_pkg cpp_custom_server`.
- In another terminal, run the client node: `ros2 run cpp_custom_srv_pkg cpp_custom_client`.

For the Python nodes:
- In one terminal, run the server node: `ros2 run py_custom_srv_pkg py_custom_server`.
- In another terminal, run the client node: `ros2 run py_custom_srv_pkg py_custom_client`.

## Next steps
1. Do you think the Python client can request a service from the C++ server? And viceversa? Try on your own!
2. Try implementing your own custom services in ROS2!
