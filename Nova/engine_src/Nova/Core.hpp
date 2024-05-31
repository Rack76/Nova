#pragma once

#ifdef NA_PLATFORM_WINDOWS
    #ifdef NA_BUILD_DLL
        #define NOVA_API __declspec(dllexport)
    #else
        #define NOVA_API __declspec(dllimport)
    #endif
#else
    #error Nova only supprts Windows!
#endif
