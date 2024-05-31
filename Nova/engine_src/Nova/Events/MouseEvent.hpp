#pragma once

#include "Event.hpp"

namespace Nova {

    class NOVA_API MouseButtonPressedEvent : public Event {
    public:
        MouseButtonPressedEvent(int button) : m_Button(button) {}
    
        EVENT_CLASS_TYPE(MouseButtonPressed)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
    
        int GetMouseButton() const { return m_Button; }
    
        std::string ToString() const override {
            return std::string("MouseButtonPressedEvent: ") + std::to_string(m_Button);
        }
    
    private:
        int m_Button;
    };
    
    class NOVA_API MouseButtonReleasedEvent : public Event {
    public:
        MouseButtonReleasedEvent(int button) : m_Button(button) {}
    
        EVENT_CLASS_TYPE(MouseButtonReleased)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
    
        int GetMouseButton() const { return m_Button; }
    
        std::string ToString() const override {
            return std::string("MouseButtonReleasedEvent: ") + std::to_string(m_Button);
        }
    
    private:
        int m_Button;
    };
    
    class NOVA_API MouseMovedEvent : public Event {
    public:
        MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}
    
        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    
        float GetX() const { return m_MouseX; }
        float GetY() const { return m_MouseY; }
    
        std::string ToString() const override {
            return std::string("MouseMovedEvent: ") + std::to_string(m_MouseX) + ", " + std::to_string(m_MouseY);
        }
    
    private:
        float m_MouseX, m_MouseY;
    };
    
    class NOVA_API MouseScrolledEvent : public Event {
    public:
        MouseScrolledEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}
    
        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    
        float GetXOffset() const { return m_XOffset; }
        float GetYOffset() const { return m_YOffset; }
    
        std::string ToString() const override {
            return std::string("MouseScrolledEvent: ") + std::to_string(m_XOffset) + ", " + std::to_string(m_YOffset);
        }
    
    private:
        float m_XOffset, m_YOffset;
    };
    
}