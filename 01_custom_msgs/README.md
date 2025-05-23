# ROS2 Tutorial 01 - Custom Messages
This tutorial explains how to define and use custom messages in ROS2, for both Python and C++.

Link to the video tutorial [here]().

## Setup & Build
1. Clone repo within a ROS2 source folder (folder name must be "src").
2. Move to workspace root folder and build using `colcon build`.
3. Source the local ROS environment using `source install/setup.bash`.
4. Verify that the messages have been correctly built using `ros2 interface show my_msgs_pkg/msg/Sphere`.

## Run the nodes
Feel free to inspect the Cpp and Python nodes to see how to use custom messages in ROS2.

Try runnning the Cpp nodes using:
- In one terminal, run the publisher node: `ros2 run cpp_ros_pkg cpp_pub_node`.
- In another terminal, run the subscriber node: `ros2 run cpp_ros_pkg cpp_sub_node`.

For the Python nodes:
- In one terminal, run the publisher node: `ros2 run python_ros_pkg python_pub_node`.
- In another terminal, run the subscriber node: `ros2 run python_ros_pkg python_sub_node`.

## Next steps
1. Do you think the Python subscriber can receive messages from the Cpp publisher? And viceversa? Try on your own!
2. Try implementing your own custom messages in ROS2!
