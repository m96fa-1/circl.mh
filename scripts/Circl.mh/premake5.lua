outputdir = "%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}"
workspc = "Circl.mh"
prj1 = "Circl.mh"
cppver = "C++23"
cver = "C17"

workspace (workspc)
    architecture "x86_64"
    configurations { "Debug", "Release", "Dist" }

IncludeDir = {}
IncludeDir["spdlog"] = (prj1 .. "/vendor/spdlog/include")
IncludeDir["glfw"] = (prj1 .. "/vendor/glfw/include")
IncludeDir["glad"] = (prj1 .. "/vendor/glad/include")
IncludeDir["imgui"] = (prj1 .. "/vendor/imgui")

group "Dependencies"
    include (prj1 .. "/vendor/glfw")
    include (prj1 .. "/vendor/glad")
    include (prj1 .. "/vendor/imgui")
group ""

project (prj1)
    location (prj1)
    kind "ConsoleApp"
    language "C++"
    staticruntime "Off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.glad}",
        "%{IncludeDir.imgui}",
    }

    links {
        "glfw",
        "glad",
        "imgui",
        "Opengl32",
    }

    defines "GLFW_INCLUDE_NONE"

    filter "system:windows"
        cppdialect (cppver)
        cdialect (cver)
        systemversion "latest"

    filter "configurations:Debug"
        defines "MH_DEBUG"
        runtime "Debug"
        symbols "On"
        
    filter "configurations:Release"
        defines "MH_RELEASE"
        runtime "Release"
        optimize "On"
        symbols "On"
        
    filter "configurations:Dist"
        kind "WindowedApp"
        defines "MH_DIST"
        runtime "Release"
        optimize "On"
        symbols "Off"
