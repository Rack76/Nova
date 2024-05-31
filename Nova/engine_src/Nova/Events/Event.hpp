#pragma once
#include "napch.hpp"

#include "Nova/Core.hpp"

namespace Nova {

    enum class EventType {
        None = 0,
        WindowClose, WindowResized, WindowFocus, WindowLostFocus, WindowMoved,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
        KeyPressed, KeyReleased,
        AppTick, AppUpdate, AppRender
    };
    
    enum EventCategory {
        EventCategoryApplication = BIT(0),
        EventCategoryInput       = BIT(1),
        EventCategoryKeyboard    = BIT(2),
        EventCategoryMouse       = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };
    
    #define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                                   virtual EventType GetEventType() const override { return GetStaticType(); }\
                                   virtual const char* GetName() const override { return #type; }
    
    #define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
    
    class NOVA_API Event {
    public:
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }
    
        inline bool IsInCategory(EventCategory category) const { 
            return GetCategoryFlags() & category; 
        }
    
        void SetPriority(int priority) { m_Priority = priority; }
        int GetPriority() const { return m_Priority; }
    
        void SetPropagationStopped(bool stopped) { m_PropagationStopped = stopped; }
        bool IsPropagationStopped() const { return m_PropagationStopped; }
    
        bool Handled = false;
    
    protected:
        int m_Priority = 0;
        bool m_PropagationStopped = false;
    };
    
    class EventDispatcher {
        template <typename T>
        using EventFn = std::function<bool(T&)>;
    
    public:
        EventDispatcher(Event& event) : m_Event(event) {}
    
        template <typename T>
        bool Dispatch(EventFn<T> func) {
            if (m_Event.GetEventType() == T::GetStaticType()) {
                m_Event.Handled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }
    
    private:
        Event& m_Event;
    };
    
}