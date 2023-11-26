#include "scriptManager.h"

sol::state ScriptingManager::lua;

void ScriptingManager::setup()
{
  lua.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);
}

void ScriptingManager::run(const std::string &script)
{
  lua.script(script);
}

void ScriptingManager::runFile(const std::string &scriptFile)
{
  lua.script_file("assets/" + scriptFile);
}
