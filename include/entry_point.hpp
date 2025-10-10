#ifndef __ENTRY_POINT_HPP__
#define __ENTRY_POINT_HPP__

#include "application.hpp"

extern Engine::Application* Engine::CreateApplication();

int main() {

  auto app = Engine::CreateApplication();
  
  app->Run();

  delete app;
}


#endif
