#ifndef __ENTRY_POINT_HPP__
#define __ENTRY_POINT_HPP__

#include "application.hpp"
#include "log.hpp"

extern Engine::Application* Engine::CreateApplication();

int main() {

  Engine::Log::Init();
  // Engine::Log::GetCoreLogger()->warn("initialize log()");
  EG_CORE_WARN("Initlize Log");
  
  // Engine::Log::GetClientLogger()->warn("initialize log()");
  EG_CLIENT_INFO("Initialize Log");

  auto app = Engine::CreateApplication();
  
  app->Run();

  delete app;
}


#endif
