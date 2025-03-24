cmake_minimum_required(VERSION 3.8)
project(string_plugin_system)
include_directories(include)


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(pluginlib REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()
add_library(reverse_string_plugin SHARED src/reverse_string_plugin.cpp)
ament_target_dependencies(reverse_string_plugin pluginlib)

add_library(count_char_plugin SHARED src/count_char_plugin.cpp)
ament_target_dependencies(count_char_plugin pluginlib)

add_executable(plugin_loader_node src/plugin_loader_node.cpp)
ament_target_dependencies(plugin_loader_node rclcpp pluginlib)

install(TARGETS
  reverse_string_plugin
  count_char_plugin
  plugin_loader_node
  DESTINATION lib/${PROJECT_NAME})

install(FILES plugin.xml DESTINATION share/${PROJECT_NAME})


ament_package()
