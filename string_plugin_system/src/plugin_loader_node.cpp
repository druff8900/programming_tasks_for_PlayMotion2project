#include "rclcpp/rclcpp.hpp"
#include "string_plugin_system/string_plugin_base.hpp"
#include <pluginlib/class_loader.hpp>

class StringPluginLoader : public rclcpp::Node {
public:
    StringPluginLoader() : Node("string_plugin_loader") {
        // Create plugin loader
        plugin_loader_ = std::make_shared<pluginlib::ClassLoader<StringPluginBase>>(
            "string_plugin_system", "StringPluginBase");

        // Choose which plugin to load
        std::string plugin_name;
        RCLCPP_INFO(this->get_logger(), "Enter plugin name (ReverseStringPlugin / CountCharPlugin):");
        std::cin >> plugin_name;

        try {
            auto plugin = plugin_loader_->createSharedInstance(plugin_name);
            std::string input;
            RCLCPP_INFO(this->get_logger(), "Enter a string:");
            std::cin >> input;
            RCLCPP_INFO(this->get_logger(), "Processed Output: %s", plugin->process(input).c_str());
        } catch (const pluginlib::PluginlibException &ex) {
            RCLCPP_ERROR(this->get_logger(), "Failed to load plugin: %s", ex.what());
        }
    }

private:
    std::shared_ptr<pluginlib::ClassLoader<StringPluginBase>> plugin_loader_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<StringPluginLoader>());
    rclcpp::shutdown();
    return 0;
}
