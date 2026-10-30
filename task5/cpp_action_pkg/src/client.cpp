#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "cpp_action_pkg/action/accumulate.hpp"
#include <chrono>

using Accumulate = cpp_action_pkg::action::Accumulate;
using GoalHandleAccumulate = rclcpp_action::ClientGoalHandle<Accumulate>;

// Action client: sends target N, prints feedback in real time,
// and prints the final result when the goal is done.
class AccumulateClient : public rclcpp::Node
{
public:
    AccumulateClient() : Node("accumulate_client")
    {
        client_ = rclcpp_action::create_client<Accumulate>(this, "accumulate");
    }

    void send_goal(int target)
    {
        if (!client_->wait_for_action_server(std::chrono::seconds(10))) {
            RCLCPP_ERROR(this->get_logger(), "Action server not available.");
            return;
        }

        auto goal = Accumulate::Goal();
        goal.target = target;

        RCLCPP_INFO(this->get_logger(), "Sending goal: target=%d", target);

        auto options = rclcpp_action::Client<Accumulate>::SendGoalOptions();

        // called every time the server publishes feedback
        options.feedback_callback =
            [this](GoalHandleAccumulate::SharedPtr,
                   const std::shared_ptr<const Accumulate::Feedback> feedback)
            {
                RCLCPP_INFO(this->get_logger(),
                            "[CLIENT FEEDBACK] number=%d, sum so far=%d",
                            feedback->current_number, feedback->current_sum);
            };

        // called once when the server returns the final result
        options.result_callback =
            [this](const GoalHandleAccumulate::WrappedResult & result)
            {
                if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {
                    RCLCPP_INFO(this->get_logger(),
                                "[CLIENT RESULT] final sum = %d", result.result->total);
                } else {
                    RCLCPP_WARN(this->get_logger(), "Goal did not succeed.");
                }
                rclcpp::shutdown();
            };

        client_->async_send_goal(goal, options);
    }

private:
    rclcpp_action::Client<Accumulate>::SharedPtr client_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<AccumulateClient>();

    // target number N, default is 10
    int target = 10;
    if (argc > 1) {
        target = std::atoi(argv[1]);
    }

    node->send_goal(target);

    rclcpp::spin(node);

    rclcpp::shutdown();
    return 0;
}
