#include <Nova.hpp>
#include <Nova/Core/EntryPoint.hpp>

class Sandbox : public Nova::Application {
public:
    Sandbox() {}

    ~Sandbox() {}
};

Nova::Application* Nova::CreateApplication() { 
    return new Sandbox();
}