#pragma once

#include <sol/sol.hpp>
#include <string>

class ScriptingManager {
public:
  static sol::state lua;

  static void setup();
  static void run(const std::string& script);
  static void runFile(const std::string& scriptFile);
};

