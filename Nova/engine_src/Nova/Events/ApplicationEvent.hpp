#pragma once

#include "Event.hpp"

namespace Nova {

    class NOVA_API WindowCloseEvent : public Event {
    public:
        WindowCloseEvent() = default;
    
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
    
    class NOVA_API WindowResizedEvent : public Event {
    public:
        WindowResizedEvent(int width, int height)
            : m_Width(width), m_Height(height) {}
    
        EVENT_CLASS_TYPE(WindowResized)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    
        int GetWidth() const { return m_Width; }
        int GetHeight() const { return m_Height; }
    
        std::string ToString() const override {
            return std::string("WindowResizedEvent: ") + std::to_string(m_Width) + ", " + std::to_string(m_Height);
        }
    
    private:
        int m_Width, m_Height;
    };
    
    class NOVA_API WindowFocusEvent : public Event {
    public:
        WindowFocusEvent() = default;
    
        EVENT_CLASS_TYPE(WindowFocus)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
    
    class NOVA_API WindowLostFocusEvent : public Event {
    public:
        WindowLostFocusEvent() = default;
    
        EVENT_CLASS_TYPE(WindowLostFocus)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
    
    class NOVA_API WindowMovedEvent : public Event {
    public:
        WindowMovedEvent(int x, int y) : m_X(x), m_Y(y) {}
    
        EVENT_CLASS_TYPE(WindowMoved)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    
        int GetX() const { return m_X; }
        int GetY() const { return m_Y; }
    
        std::string ToString() const override {
            return std::string("WindowMovedEvent: ") + std::to_string(m_X) + ", " + std::to_string(m_Y);
        }
    
     private:
        int m_X, m_Y;
    };
    
    class NOVA_API AppTickEvent : public Event {
    public:
        AppTickEvent() = default;
    
        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
    
    class NOVA_API AppUpdateEvent : public Event {
    public:
        AppUpdateEvent() = default;
    
        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
    
    class NOVA_API AppRenderEvent : public Event {
    public:
        AppRenderEvent() = default;
    
        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
    
}