project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    characterset ("MBCS")
    staticruntime "on"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "app_src/**.hpp",
        "app_src/**.cpp"
    }

    includedirs
    {
        "%{wks.location}/Nova/dependencies/spdlog/include",
        "%{wks.location}/Nova/engine_src",
        "%{wks.location}/Nova/dependencies"
    }

    links
    {
        "Nova"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "NA_PLATFORM_WINDOWS"
        }

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