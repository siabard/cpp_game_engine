#ifndef __KEY_EVENT_HPP__
#define __KEY_EVENT_HPP__

#include "stdafx.hpp"

#include "event/event.hpp"
#include "core/key_code.hpp"

namespace Engine {

  class KeyEvent : public Event {
  public:
    KeyCode GetKeyCode() const { return m_KeyCode; }

    EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard);
    
  protected:
    KeyCode m_KeyCode;
    KeyEvent(const KeyCode keycode) : m_KeyCode(keycode) {}
  };

  class KeyPressedEvent : public KeyEvent {
  public:
    KeyPressedEvent(const KeyCode keycode, bool isRepeat = false) : KeyEvent(keycode), m_IsRepeat(isRepeat) {}

    bool IsRepeat() const { return m_IsRepeat; }

    std::string ToString() const override {
      std::stringstream ss;
      ss << "KeyPressEvent " << m_KeyCode << " (repeat = " << m_IsRepeat << ")";
      return ss.str();
    }

    EVENT_CLASS_TYPE(KeyPressed);

  private:
    bool m_IsRepeat;
  };

  class KeyReleasedEvent : public KeyEvent {
  public:
    KeyReleasedEvent(const KeyCode keycode) : KeyEvent(keycode) {}

    std::string ToString() const override {
      std::stringstream ss;
      ss << "KeyReleasedEvent: " << m_KeyCode;
      return ss.str();
    }

    EVENT_CLASS_TYPE(KeyReleased);
  };

  class KeyTypedEvent : public KeyEvent {

  public:
    KeyTypedEvent(const KeyCode keycode) : KeyEvent(keycode) {}

    std::string ToString() const override {
      std::stringstream ss;
      ss << "KeyTypedEvent: " << m_KeyCode;
      return ss.str();
    }

    EVENT_CLASS_TYPE(KeyTyped);
  };
}

#endif 
