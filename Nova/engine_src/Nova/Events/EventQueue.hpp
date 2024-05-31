#pragma once

#include "Event.hpp"

namespace Nova {

    class EventQueue {
    public:
        void Push(Event* event, int priority = 0) {
            m_EventQueue.push({ priority, event });
        }
    
        Event* Pop() {
            if (m_EventQueue.empty()) return nullptr;
    
            auto event = m_EventQueue.top().event;
            m_EventQueue.pop();
            return event;
        }
    
        bool IsEmpty() const { 
            return m_EventQueue.empty(); 
        }
    
    private:
        struct EventEntry {
            int priority;
            Event* event;
    
            bool operator<(const EventEntry& other) const {
                return priority < other.priority;
            }
        };
    
        std::priority_queue<EventEntry> m_EventQueue;
    };
    
}