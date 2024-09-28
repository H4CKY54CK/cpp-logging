#include "logging.hpp"





// Local logger
logging::Logger::Logger(std::string name, std::size_t loglevel) : name(std::move(name)), loglevel(loglevel) {
  level_names = {
    {10, "debug"},
    {20, "info"},
    {30, "warn"},
    {40, "error"},
    {50, "critical"},
  };

  level_colors = {
    {0, "\x1b[00m"},
    {10, "\x1b[36m"},
    {20, "\x1b[32m"},
    {30, "\x1b[33m"},
    {40, "\x1b[31m"},
    {50, "\x1b[41m"},
  };

  if (isatty(2) == 0) {
    level_colors = {};
  }
}

logging::Logger::Logger(std::string name) : Logger(std::move(name), 30) {}


// Get and set level
void logging::Logger::set_level(std::size_t level) { loglevel = level; }
auto logging::Logger::get_level() -> std::size_t { return loglevel; }


// Get and set name
auto logging::Logger::get_name() -> std::string { return name; }
void logging::Logger::set_name(const std::string& value) { name = value; }


// Get color by level
auto logging::Logger::get_color(std::size_t level) -> std::string { return level_colors[level]; }


// Get level name by level
auto logging::Logger::get_level_name(std::size_t level) -> std::string { return level_names[level]; }


// Emit local logger messages
void logging::Logger::log(std::size_t level, const std::string& msg) {
  if (loglevel <= level) {
    std::cerr << get_color(level) << "[" << get_name() << " " << get_level_name(level) << "]" << get_color(0) << ": " << msg << "\n";
  }
}
void logging::Logger::fatal(const std::string& msg) { log(50, msg); }
void logging::Logger::critical(const std::string& msg) { log(50, msg); }
void logging::Logger::error(const std::string& msg) { log(40, msg); }
void logging::Logger::warning(const std::string& msg) { log(30, msg); }
void logging::Logger::warn(const std::string& msg) { log(30, msg); }
void logging::Logger::info(const std::string& msg) { log(20, msg); }
void logging::Logger::debug(const std::string& msg) { log(10, msg); }


std::map<std::string, logging::Logger> logging::_logger_registry;

// Get logger by name
auto logging::get_logger(const std::string& name) -> logging::Logger& { return _logger_registry.try_emplace(name, name).first->second; }

// Get and set level
void logging::set_level(std::size_t level) { get_logger("root").loglevel = level; }
auto logging::get_level() -> std::size_t { return get_logger("root").loglevel; }

// Get and set name
void logging::set_name(const std::string& name) { get_logger("root").name = name; }
auto logging::get_name() -> std::string { return get_logger("root").name; }

// Convenience functions
void logging::log(std::size_t level, const std::string& msg) { get_logger("root").log(level, msg); }
void logging::fatal(const std::string& msg) { get_logger("root").log(50, msg); }
void logging::critical(const std::string& msg) { get_logger("root").log(50, msg); }
void logging::error(const std::string& msg) { get_logger("root").log(40, msg); }
void logging::warning(const std::string& msg) { get_logger("root").log(30, msg); }
void logging::warn(const std::string& msg) { get_logger("root").log(30, msg); }
void logging::info(const std::string& msg) { get_logger("root").log(20, msg); }
void logging::debug(const std::string& msg) { get_logger("root").log(10, msg); }


