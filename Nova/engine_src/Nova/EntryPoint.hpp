#pragma once

#ifdef NA_PLATFORM_WINDOWS

extern Nova::Application* Nova::CreateApplication();

int main(int argc, char** argv) {

    auto app = Nova::CreateApplication();
    app->Run();
    delete app;
}

#endif