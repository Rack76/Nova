#pragma once

#include "Core.hpp"

namespace Nova {

    class NOVA_API Application {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

// To be defined in CLIENT
Application* CreateApplication();

}