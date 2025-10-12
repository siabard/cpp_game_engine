#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

namespace Engine {
  class Application {
  public:
    Application();
    virtual ~Application();
e
    void Run();

  };

  Application* CreateApplication();
} // namespace Engine

#endif 
