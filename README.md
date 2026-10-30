# homework

C++ 与 ROS2 学习任务仓库。按任务分组，每次作业一个 `taskN` 目录。

## 目录结构

```
.
├── task1                               # C++ 环境配置与 HelloWorld
│   ├── hello.cpp                       # HelloWorld 源码
│   └── 截图 2026-09-27 *.png            # 编译与运行截图（3 张）
├── task2                               # 入门一、入门二各 5 题 + 小乌龟
│   ├── basic1                          # 入门一：顺序结构 5 题
│   │   └── screenshots                 # 每题 AC 截图
│   ├── basic2                          # 入门二：分支结构 5 题
│   │   └── screenshots                 # 每题 AC 截图
│   └── ros2_turtle.png                 # ROS2 小乌龟键盘控制
├── task3                               # 入门三、入门四各 5 题 + ROS2 节点
│   ├── basic3                          # 入门三：循环结构 5 题
│   │   └── screenshots
│   ├── basic4                          # 入门四：数组 5 题
│   │   └── screenshots
│   └── ros2_helloworld                 # ROS2 C++ 节点
│       ├── ros2_helloworld.cpp         # 节点源码
│       └── ros2_helloworld.png         # 运行截图
├── task4                               # 入门六：函数与结构体 6 题
│   └── basic6
│       └── screenshots
├── task5                               # ROS2 话题 / 服务 / 动作 + 自定义接口
│   ├── cpp_topic_pkg                   # 题目1：话题 + 自定义 msg
│   │   ├── msg/Item.msg
│   │   ├── src/publisher.cpp
│   │   ├── src/subscriber.cpp
│   │   ├── CMakeLists.txt
│   │   └── package.xml
│   ├── cpp_service_pkg                 # 题目2：服务 + 自定义 srv
│   │   ├── srv/Fibonacci.srv
│   │   ├── src/server.cpp
│   │   ├── src/client.cpp
│   │   ├── CMakeLists.txt
│   │   └── package.xml
│   ├── cpp_action_pkg                  # 题目3：动作 + 自定义 action
│   │   ├── action/Accumulate.action
│   │   ├── src/server.cpp
│   │   ├── src/client.cpp
│   │   ├── CMakeLists.txt
│   │   └── package.xml
│   └── screenshots                     # 6 张运行截图
└── README.md
```

## 任务说明

- **task1**：C++ 环境配置与 HelloWorld
- **task2**：洛谷入门一、入门二各 5 题 + ROS2 小乌龟键盘控制
- **task3**：洛谷入门三（basic3）、入门四（basic4）各 5 题 + ROS2 C++ 节点（ros2_helloworld）
- **task4**：洛谷入门六「函数与结构体」6 题（basic6），练习自定义函数、递归、struct、sort
- **task5**：ROS2 三种通信方式 + 自定义接口（话题 / 服务 / 动作各一个包）

## task5 · ROS2 话题 / 服务 / 动作

### 环境

Ubuntu 虚拟机 + ROS2 Humble，工作空间 `~/ros2_ws`，三个包均通过 `colcon build` 编译。

### 题目1 · 话题 + 自定义消息

自定义消息 `msg/Item.msg`，包含物品 ID 与基本信息：

```
int32 id
string name
int32 price
string description
```

- `publisher.cpp`：定时器每秒发布一条物品信息，日志打印 `[PUBLISH] id=... name=... price=... desc=...`
- `subscriber.cpp`：订阅同一话题，回调中打印 `[RECEIVE] ...`

运行：

```bash
ros2 run cpp_topic_pkg publisher    # 终端 A
ros2 run cpp_topic_pkg subscriber   # 终端 B
```

### 题目2 · 服务 + 自定义服务接口

自定义服务 `srv/Fibonacci.srv`：

```
int32 order      # 请求：第几项
---
int32 result     # 响应：斐波那契数
```

- `server.cpp`：收到请求后迭代计算第 n 项并返回，打印 `[SERVER] got order=n, send back fib(n)=x`
- `client.cpp`：循环请求第 1 到第 10 项（每秒一次），打印 `[CLIENT] order=n -> fib=x`

两端日志时间戳逐条交错，形成一问一答的交替输出：

| order | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| fib | 1 | 1 | 2 | 3 | 5 | 8 | 13 | 21 | 34 | 55 |

运行：

```bash
ros2 run cpp_service_pkg server    # 终端 A
ros2 run cpp_service_pkg client    # 终端 B（约 10 秒后自动退出）
```

### 题目3 · 动作 + 自定义动作接口

自定义动作 `action/Accumulate.action`，三段分别对应目标 / 结果 / 反馈：

```
int32 target                          # 目标：要累加到的数字 N
---
int32 total                           # 结果：最终累加和
---
int32 current_number                  # 反馈：当前已累加的数字
int32 current_sum                     # 反馈：当前和
```

- `server.cpp`：
  - `handle_goal` 校验 N > 0，否则 `REJECT`
  - `handle_accepted` 开独立线程执行，避免阻塞
  - `execute` 从 1 逐个累加，每步 `publish_feedback` 后休眠 500ms
  - 全部累加完毕后 `succeed(result)`
  - 循环内检查 `is_canceling()`，收到取消请求时 `canceled(result)` 提前返回
- `client.cpp`：发送目标 N（默认 10），挂 `feedback_callback` 实时打印，`result_callback` 打印最终结果后退出

运行：

```bash
ros2 run cpp_action_pkg server              # 终端 A
ros2 run cpp_action_pkg client              # 终端 B，默认 N=10
ros2 run cpp_action_pkg client 20           # 也可指定 N
```

N=10 时累加结果为 **55**。

### 截图索引

| 文件 | 内容 |
|---|---|
| `screenshots/1_topic_publisher.png` | 发布端 `[PUBLISH]` 持续输出 |
| `screenshots/2_topic_subscriber.png` | 订阅端 `[RECEIVE]` 同步接收 |
| `screenshots/3_service_server.png` | 服务端 `[SERVER]` 逐项应答 |
| `screenshots/4_service_client.png` | 客户端 `[CLIENT]` 收到 1~55 |
| `screenshots/5_action_server.png` | 服务端 `[FEEDBACK]` 逐步累加 |
| `screenshots/6_action_client.png` | 客户端实时反馈 + `final sum = 55` |

## task4 · basic6 题目清单

| 题号 | 题目 | 考点 |
|------|------|------|
| P5735 | 距离函数 | 自定义函数 + 返回值 |
| P5739 | 计算阶乘 | 函数递归（附循环版） |
| P5740 | 最厉害的学生 | struct + stable_sort |
| P5741 | 旗鼓相当的对手 - 加强版 | struct + 双循环枚举 |
| P5742 | 评等级 | struct + bool 判断函数 |
| P5744 | 培训 | struct 批量处理 + 返回值回传 |
