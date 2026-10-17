# ROS2 C++ 节点 · HelloWorld（第三次任务最后一关）

环境：Ubuntu 22.04 + ROS2 Humble（虚拟机里，已装好）。

## 步骤

1. 启动虚拟机，开终端，确认 ROS2 已加载：  
   `ros2 --help`  
   （能打印用法说明就是环境在；若提示命令不存在，先 `source /opt/ros/humble/setup.bash`；正常已写进 `~/.bashrc` 自动加载。注意：`ros2 --version` 会报 unrecognized arguments，属正常。）
2. 建工作区与功能包（自带一个叫 helloworld 的节点）：
   ```
   mkdir -p ~/ros2_ws/src
   cd ~/ros2_ws/src
   ros2 pkg create --build-type ament_cmake --node-name helloworld cpp_helloworld
   ```
3. 编辑节点源码：  
   `gedit ~/ros2_ws/src/cpp_helloworld/src/helloworld.cpp`

- 顶部已有 `#include "rclcpp/rclcpp.hpp"`，自己加一行 `#include <iostream>`

> 若提示 `colcon: command not found`，先安装：`sudo apt update && sudo apt install -y python3-colcon-common-extensions`

1. 编译（回到工作区根）：
   ```
   cd ~/ros2_ws
   colcon build --packages-select cpp_helloworld
   ```
2. 运行：
   ```
   source install/setup.bash
   ros2 run cpp_helloworld helloworld
   ```
   终端打印 `Hello World!` 即成功。
3. 截图保存运行结果。
4. 交作业：把 `helloworld.cpp` + 截图拷回主机，存进 `luogu/task3/`，然后 git push。

## 关键概念（先想清楚再做）

- 节点 = 一个独立跑的小程序；ROS2 用 `rclcpp` 库管生命周期（`init` → `spin` → `shutdown`）。
- 编译系统：`ament_cmake`（C++ 用这个，不是 ament_python）；包建好后靠 `CMakeLists.txt` 决定编译哪个 .cpp。
- `colcon build` 之后必须 `source install/setup.bash`，否则 `ros2 run` 找不到你的包。
