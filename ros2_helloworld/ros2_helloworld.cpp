#include<iostream>
#include "rclcpp/rclcpp.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc,argv);
  auto node = rclcpp::Node::make_shared("helloworld_node");
  std::cout<<"Hello World!"<<std::endl;
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
