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
└── README.md
```

## 任务说明

- **task1**：C++ 环境配置与 HelloWorld
- **task2**：洛谷入门一、入门二各 5 题 + ROS2 小乌龟键盘控制
- **task3**：洛谷入门三（basic3）、入门四（basic4）各 5 题 + ROS2 C++ 节点（ros2_helloworld）
- **task4**：洛谷入门六「函数与结构体」6 题（basic6），练习自定义函数、递归、struct、sort

## task4 · basic6 题目清单

| 题号 | 题目 | 考点 |
|------|------|------|
| P5735 | 距离函数 | 自定义函数 + 返回值 |
| P5739 | 计算阶乘 | 函数递归（附循环版） |
| P5740 | 最厉害的学生 | struct + stable_sort |
| P5741 | 旗鼓相当的对手 - 加强版 | struct + 双循环枚举 |
| P5742 | 评等级 | struct + bool 判断函数 |
| P5744 | 培训 | struct 批量处理 + 返回值回传 |
