#include "log.hpp"
#include "application.hpp"
#include "event/application_event.hpp"

namespace Engine {

  Application::Application() {}

  Application::~Application() {}

  void Application::Run() {
    WindowResizeEvent e(1280, 1080);

    if (e.IsInCategory(EventCategoryInput)) {
      EG_CLIENT_TRACE(e);
    }

    if(e.IsInCategory(EventCategoryApplication)) {
      EG_CLIENT_TRACE(e);
    }

    while(true) ;
  }

} // namespace Engine
