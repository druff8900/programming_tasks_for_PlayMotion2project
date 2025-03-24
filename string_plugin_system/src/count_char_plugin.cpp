#include "string_plugin_system/string_plugin_base.hpp"
#include <pluginlib/class_list_macros.hpp>

class CountCharPlugin : public StringPluginBase {
public:
    std::string process(const std::string &input) override {
        return "Length: " + std::to_string(input.length());
    }
};

// Register the plugin with ROS 2 pluginlib
PLUGINLIB_EXPORT_CLASS(CountCharPlugin, StringPluginBase)

