#pragma once

#include "Event.hpp"

namespace Nova {

    class EventListener {
        template <typename T>
        using EventFn = std::function<bool(T&)>;
    
    public:
        EventListener() : m_NextListenerID(0) {}
    
        template <typename T>
        int AddListener(EventFn<T> func, std::function<bool(const T&)> filter = nullptr) {
            auto eventType = T::GetStaticType();
            int listenerID = m_NextListenerID++;
    
            m_Listeners[eventType].push_back({ listenerID, [func](Event& event) { 
                return func(*(T*)&event); 
            }, [filter](const Event& event) -> bool {
                if (filter) 
                    return filter(*(T*)&event);
                return true;
            } });
    
            return listenerID;
        }
    
        void RemoveListener(EventType eventType, int listenerID) {
             auto& listeners = m_Listeners[eventType];
             listeners.erase(std::remove_if(listeners.begin(), listeners.end(),
                 [listenerID](const ListenerEntry& entry) {
                    return entry.ID == listenerID;
                 }), listeners.end());
        }
    
        void Dispatch(Event& event, int categoryMask) {
            auto eventType = event.GetEventType();
            if (m_Listeners.find(eventType) != m_Listeners.end()) {
                for (auto& listener : m_Listeners[eventType]) {
                    if (event.Handled) 
                        break;
                    if (categoryMask & event.GetCategoryFlags() && listener.Filter(event)) {
                    event.Handled = listener.Func(event);
                    }
                }
            }
        }
    
    private:
        struct ListenerEntry {
            int ID;
            std::function<bool(Event&)> Func;
            std::function<bool(const Event&)> Filter;
        };
    
        std::unordered_map<EventType, std::vector<ListenerEntry>> m_Listeners;
        std::atomic<int> m_NextListenerID;
    };
    
}