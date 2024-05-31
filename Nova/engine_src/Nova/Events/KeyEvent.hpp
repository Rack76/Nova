#pragma once

#include "Event.hpp"

namespace Nova {

    class NOVA_API KeyEvent : public Event {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }
    
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    
    protected:
        KeyEvent(int keycode) : m_KeyCode(keycode) {}
    
        int m_KeyCode;
    };
    
    class KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount) {}
    
        EVENT_CLASS_TYPE(KeyPressed)
    
        inline int GetRepeatCount() const { return m_RepeatCount; }
    
        std::string ToString() const override {
            return std::string("KeyPressedEvent: ") + std::to_string(m_KeyCode) + " (repeated " + std::to_string(m_RepeatCount) + " times)";
        }
    
    private:
        int m_RepeatCount;
    };
    
    class KeyReleasedEvent : public KeyEvent {
    public:
        KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}
    
        EVENT_CLASS_TYPE(KeyReleased)
    
        std::string ToString() const override { 
            return std::string("KeyReleasedEvent: ") + std::to_string(m_KeyCode);
        }
    };
    
}