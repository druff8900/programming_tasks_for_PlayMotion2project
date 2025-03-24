#ifndef STRING_PLUGIN_BASE_HPP
#define STRING_PLUGIN_BASE_HPP

#include <string>

class StringPluginBase {
public:
    virtual ~StringPluginBase() = default;
    
    // Pure virtual function: every plugin must implement this function
    virtual std::string process(const std::string &input) = 0;
};

#endif // STRING_PLUGIN_BASE_HPP
