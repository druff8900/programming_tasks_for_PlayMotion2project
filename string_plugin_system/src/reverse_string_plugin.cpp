#include "string_plugin_system/string_plugin_base.hpp"
#include <algorithm>
#include <pluginlib/class_list_macros.hpp>

class ReverseStringPlugin : public StringPluginBase {
public:
    std::string process(const std::string &input) override {
        std::string reversed = input;
        std::reverse(reversed.begin(), reversed.end());
        return reversed;
    }
};

// Register the plugin with ROS 2 pluginlib
PLUGINLIB_EXPORT_CLASS(ReverseStringPlugin, StringPluginBase)
