#ifndef __APPLICATION_EVENT_HPP__
#define __APPLICATION_EVENT_HPP__

#include "stdafx.hpp"
#include "event/event.hpp"


namespace Engine {
  class WindowResizeEvent : Event {
  public:
    WindowResizeEvent(unsigned int width, unsigned int height)
        : m_Width(width), m_Height(height) {}

    unsigned int GetWidth() { return m_Width; }
    unsigned int GetHeight() { return m_Height; }

    std::string ToString() const override {
      std::stringstream ss;

      ss << "WindowResizeEvent:" << m_Width << ", " << m_Height;
      return ss.str();
    }


    EVENT_CLASS_TYPE(WindowResize);
    EVENT_CLASS_CATEGORY(EventCategoryApplication);


  private:
    unsigned int m_Width;
    unsigned int m_Height;
  };

  class WindowCloseEvent : Event {
  public:
    WindowCloseEvent() = default;
    
    EVENT_CLASS_TYPE(WindowClose);
    EVENT_CLASS_CATEGORY(EventCategoryApplication);
  };

  class AppTickEvent : Event {
  public:
    AppTickEvent() = default;

    EVENT_CLASS_TYPE(AppTick);
    EVENT_CLASS_CATEGORY(EventCategoryApplication);
  };

  class AppUpdateEvent : Event {
  public:
    AppUpdateEvent() = default;

    EVENT_CLASS_TYPE(AppUpdate);
    EVENT_CLASS_CATEGORY(EventCategoryApplication);
  };

  class AppRenderEvent : Event {
  public:
    AppRenderEvent() = default;
    
    EVENT_CLASS_TYPE(AppRender);
    EVENT_CLASS_CATEGORY(EventCategoryApplication);
  };
}

#endif
