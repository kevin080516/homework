#include "rclcpp/rclcpp.hpp"
#include "cpp_topic_pkg/msg/item.hpp"

// Subscriber node: receives item info from topic /item_info and prints it
class ItemSubscriber : public rclcpp::Node
{
public:
    ItemSubscriber() : Node("item_subscriber")
    {
        sub_ = this->create_subscription<cpp_topic_pkg::msg::Item>(
            "item_info", 10,
            std::bind(&ItemSubscriber::on_message, this, std::placeholders::_1));
    }

private:
    void on_message(const cpp_topic_pkg::msg::Item::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(),
                    "[RECEIVE] id=%d name=%s price=%d desc=%s",
                    msg->id, msg->name.c_str(), msg->price, msg->description.c_str());
    }

    rclcpp::Subscription<cpp_topic_pkg::msg::Item>::SharedPtr sub_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ItemSubscriber>());
    rclcpp::shutdown();
    return 0;
}
