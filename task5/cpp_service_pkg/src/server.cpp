#include "rclcpp/rclcpp.hpp"
#include "cpp_service_pkg/srv/fibonacci.hpp"

// Service server: receives an order n, returns the n-th fibonacci number
class FibonacciServer : public rclcpp::Node
{
public:
    FibonacciServer() : Node("fibonacci_server")
    {
        service_ = this->create_service<cpp_service_pkg::srv::Fibonacci>(
            "fibonacci",
            std::bind(&FibonacciServer::handle_request, this,
                      std::placeholders::_1, std::placeholders::_2));

        RCLCPP_INFO(this->get_logger(), "Fibonacci server is ready.");
    }

private:
    void handle_request(
        const std::shared_ptr<cpp_service_pkg::srv::Fibonacci::Request> request,
        std::shared_ptr<cpp_service_pkg::srv::Fibonacci::Response> response)
    {
        int n = request->order;

        // f(0)=0, f(1)=1, f(2)=1, f(3)=2 ...
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            int next = a + b;
            a = b;
            b = next;
        }

        response->result = a;

        RCLCPP_INFO(this->get_logger(),
                    "[SERVER] got order=%d, send back fib(%d)=%d", n, n, a);
    }

    rclcpp::Service<cpp_service_pkg::srv::Fibonacci>::SharedPtr service_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FibonacciServer>());
    rclcpp::shutdown();
    return 0;
}
