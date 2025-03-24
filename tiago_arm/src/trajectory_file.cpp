#include "rclcpp/rclcpp.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"

class SimpleTiagoArm : public rclcpp::Node {
public:
    SimpleTiagoArm() : Node("simple_tiago_arm") {
        // Create a publisher for TIAGo's arm
        publisher_ = this->create_publisher<trajectory_msgs::msg::JointTrajectory>(
            "/arm_controller/joint_trajectory", 10);

        // Wait to ensure everything is initialized
        rclcpp::sleep_for(std::chrono::seconds(2));

        // Send a simple trajectory command
        send_trajectory();
    }

private:
    void send_trajectory() {
        // Create a simple trajectory message
        trajectory_msgs::msg::JointTrajectory traj_msg;
        traj_msg.joint_names = {"arm_1_joint", "arm_2_joint", "arm_3_joint", 
                                "arm_4_joint", "arm_5_joint", "arm_6_joint", "arm_7_joint"};

        // Define a single motion point (small movement)
        trajectory_msgs::msg::JointTrajectoryPoint point;
        point.positions = {0.1, 0.0, 0.0, 0.2, 0.0, -0.1, 0.0};  // Small movement
        point.time_from_start.sec = 2;  // Move within 2 seconds

        // Add the movement point
        traj_msg.points.push_back(point);

        // Publish the simple trajectory
        publisher_->publish(traj_msg);
        RCLCPP_INFO(this->get_logger(), "Sent simple trajectory!");
    }

    rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr publisher_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimpleTiagoArm>());
    rclcpp::shutdown();
    return 0;
}
