#ifndef __MOUSE_EVENT_HPP__
#define __MOUSE_EVENT_HPP__

#include "stdafx.hpp"

#include "core/mouse_codes.hpp"

#include "event/event.hpp"

namespace Engine {
  class MouseMovedEvent : public Event {
  public:
    MouseMovedEvent(const float x, const float y) : m_MouseX(x), m_MouseY(y) {}
    float GetX() { return m_MouseX; }
    float GetY() { return m_MouseY; }

    std::string ToString() const override {
      std::stringstream ss;

      ss << "MouseMoveEvent: " << m_MouseX << ", " << m_MouseY;
      return ss.str();
    }


    EVENT_CLASS_TYPE(MouseMoved)
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

  private:
    float m_MouseX, m_MouseY;
  };

  class MouseScrolledEvent : public Event {

  public:
    MouseScrolledEvent(const float xOffset, const float yOffset)
        : m_XOffset(xOffset), m_YOffset(yOffset) {}

    float GetXOffset() { return m_XOffset; }
    float GetYOffset() { return m_YOffset; }

    std::string ToString() const override {
      std::stringstream ss;
      
      ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
      return ss.str();
    }

    EVENT_CLASS_TYPE(MouseScrollled)
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

  private:
    float m_XOffset, m_YOffset;
  };

  class MouseButtonEvent : public Event {
  public:
    MouseCode GetMouseButton() const { return m_Button; }
    
    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton)

    

  protected:
    MouseButtonEvent(const MouseCode button) : m_Button(button) {}
    MouseCode m_Button;
  };

  class MouseButtonPressedEvent : public MouseButtonEvent {
  public:
    MouseButtonPressedEvent(const MouseCode button)
        : MouseButtonEvent(button) {}

    std::string ToString() const override {
      std::stringstream ss;

      ss << "MouseButtonPressedEvent: " << m_Button;
      return ss.str();
    }

    EVENT_CLASS_TYPE(MouseButtonPressed)
  };

  class MouseButtonReleasedEvent : public MouseButtonEvent {
  public:
    MouseButtonReleasedEvent(const MouseCode button): MouseButtonEvent(button) {}

    std::string ToString() const override {
      std::stringstream ss;
      
      ss << "MouseButtonReleasedEvent: " << m_Button;
      return ss.str();
    }

    EVENT_CLASS_TYPE(MouseButtonReleased))
  };
}

#endif 
