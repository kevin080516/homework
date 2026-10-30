#include "rclcpp/rclcpp.hpp"
#include "cpp_service_pkg/srv/fibonacci.hpp"

// Service client: asks for fibonacci numbers one by one and prints them
int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("fibonacci_client");

    auto client = node->create_client<cpp_service_pkg::srv::Fibonacci>("fibonacci");

    RCLCPP_INFO(node->get_logger(), "Waiting for server ...");
    while (!client->wait_for_service(std::chrono::seconds(1))) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(node->get_logger(), "Interrupted while waiting.");
            return 1;
        }
        RCLCPP_INFO(node->get_logger(), "Still waiting ...");
    }
    RCLCPP_INFO(node->get_logger(), "Server connected.");

    // Ask for the 1st to the 10th fibonacci number, one per second
    for (int n = 1; n <= 10; n++) {
        auto request = std::make_shared<cpp_service_pkg::srv::Fibonacci::Request>();
        request->order = n;

        auto future = client->async_send_request(request);

        if (rclcpp::spin_until_future_complete(node, future) ==
            rclcpp::FutureReturnCode::SUCCESS)
        {
            auto response = future.get();
            RCLCPP_INFO(node->get_logger(),
                        "[CLIENT] order=%d -> fib=%d", n, response->result);
        } else {
            RCLCPP_ERROR(node->get_logger(), "Failed to call service.");
        }

        rclcpp::sleep_for(std::chrono::seconds(1));
    }

    rclcpp::shutdown();
    return 0;
}
