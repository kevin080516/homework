#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "cpp_action_pkg/action/accumulate.hpp"
#include <thread>
#include <chrono>

using Accumulate = cpp_action_pkg::action::Accumulate;
using GoalHandleAccumulate = rclcpp_action::ServerGoalHandle<Accumulate>;

// Action server: receives target N, adds 1+2+...+N,
// publishes feedback after every step, returns the final sum.
class AccumulateServer : public rclcpp::Node
{
public:
    AccumulateServer() : Node("accumulate_server")
    {
        action_server_ = rclcpp_action::create_server<Accumulate>(
            this,
            "accumulate",
            std::bind(&AccumulateServer::handle_goal, this,
                      std::placeholders::_1, std::placeholders::_2),
            std::bind(&AccumulateServer::handle_cancel, this, std::placeholders::_1),
            std::bind(&AccumulateServer::handle_accepted, this, std::placeholders::_1));

        RCLCPP_INFO(this->get_logger(), "Accumulate action server is ready.");
    }

private:
    rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GoalUUID & uuid,
        std::shared_ptr<const Accumulate::Goal> goal)
    {
        (void)uuid;
        RCLCPP_INFO(this->get_logger(), "Received goal: target=%d", goal->target);
        if (goal->target <= 0) {
            RCLCPP_WARN(this->get_logger(), "Target must be positive, reject.");
            return rclcpp_action::GoalResponse::REJECT;
        }
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse handle_cancel(
        const std::shared_ptr<GoalHandleAccumulate> goal_handle)
    {
        (void)goal_handle;
        RCLCPP_INFO(this->get_logger(), "Received cancel request.");
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted(const std::shared_ptr<GoalHandleAccumulate> goal_handle)
    {
        // run the work in a separate thread so the server stays responsive
        std::thread{std::bind(&AccumulateServer::execute, this, goal_handle)}.detach();
    }

    void execute(const std::shared_ptr<GoalHandleAccumulate> goal_handle)
    {
        auto goal = goal_handle->get_goal();
        auto feedback = std::make_shared<Accumulate::Feedback>();
        auto result = std::make_shared<Accumulate::Result>();

        int sum = 0;

        for (int i = 1; i <= goal->target; i++) {
            if (goal_handle->is_canceling()) {
                result->total = sum;
                goal_handle->canceled(result);
                RCLCPP_INFO(this->get_logger(), "Goal canceled.");
                return;
            }

            sum += i;

            feedback->current_number = i;
            feedback->current_sum = sum;
            goal_handle->publish_feedback(feedback);

            RCLCPP_INFO(this->get_logger(),
                        "[FEEDBACK] add %d, current sum = %d", i, sum);

            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

        result->total = sum;
        goal_handle->succeed(result);

        RCLCPP_INFO(this->get_logger(), "[RESULT] final sum = %d", sum);
    }

    rclcpp_action::Server<Accumulate>::SharedPtr action_server_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AccumulateServer>());
    rclcpp::shutdown();
    return 0;
}
