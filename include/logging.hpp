#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unistd.h>


namespace logging {

  // Logger for more personalized logging
  struct Logger {
    std::string name;
    std::size_t loglevel;
    bool use_color;

    std::map<std::size_t, std::string> level_colors;
    std::map<std::size_t, std::string> level_names;

    explicit Logger(std::string value1, std::size_t value2);
    explicit Logger(std::string value1);

    // Get loglevel (public)
    void set_level(std::size_t level);
    auto get_level() -> std::size_t;

    // Get name (public)
    auto get_name() -> std::string;
    void set_name(const std::string& value);

    auto get_color(std::size_t level) -> std::string;
    auto get_level_name(std::size_t level) -> std::string;

    // Convenience methods
    void log(std::size_t level, const std::string& msg);
    void fatal(const std::string& msg);
    void critical(const std::string& msg);
    void error(const std::string& msg);
    void warning(const std::string& msg);
    void warn(const std::string& msg);
    void info(const std::string& msg);
    void debug(const std::string& msg);
  };

  extern std::map<std::string, Logger> _logger_registry;

  Logger& get_logger(const std::string& name);

  void set_level(std::size_t level);
  std::size_t get_level();

  void set_name(const std::string&);
  std::string get_name();

  void log(std::size_t level, const std::string& msg);
  void fatal(const std::string& msg);
  void critical(const std::string& msg);
  void error(const std::string& msg);
  void warning(const std::string& msg);
  void warn(const std::string& msg);
  void info(const std::string& msg);
  void debug(const std::string& msg);
};
