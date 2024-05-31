project "Nova"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    characterset ("MBCS")
    staticruntime "on"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "napch.hpp"
    pchsource "engine_src/napch.cpp"


    files
    {
        "engine_src/**.hpp",
        "engine_src/**.cpp"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "engine_src",
        "dependencies/spdlog/include"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "NA_PLATFORM_WINDOWS",
            "NA_BUILD_DLL"
        }

    postbuildcommands ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")

    filter "configurations:Debug"
        defines "NA_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Debug"
        defines "NA_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Debug"
        defines "NA_DIST"
        runtime "Release"
        optimize "On"