#include "rclcpp/rclcpp.hpp"
#include "cpp_topic_pkg/msg/item.hpp"
#include <chrono>

using namespace std::chrono_literals;

// Publisher node: sends item info to topic /item_info once per second
class ItemPublisher : public rclcpp::Node
{
public:
    ItemPublisher() : Node("item_publisher"), count_(1)
    {
        pub_ = this->create_publisher<cpp_topic_pkg::msg::Item>("item_info", 10);
        timer_ = this->create_wall_timer(1s, std::bind(&ItemPublisher::publish_item, this));
    }

private:
    void publish_item()
    {
        auto msg = cpp_topic_pkg::msg::Item();
        msg.id = count_;
        msg.name = "apple_" + std::to_string(count_);
        msg.price = count_ * 10;
        msg.description = "fruit from shelf " + std::to_string(count_);

        RCLCPP_INFO(this->get_logger(),
                    "[PUBLISH] id=%d name=%s price=%d desc=%s",
                    msg.id, msg.name.c_str(), msg.price, msg.description.c_str());

        pub_->publish(msg);
        count_++;
    }

    rclcpp::Publisher<cpp_topic_pkg::msg::Item>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    int count_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ItemPublisher>());
    rclcpp::shutdown();
    return 0;
}
