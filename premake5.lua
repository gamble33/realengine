workspace "realengine"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "realengine"
	location "realengine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"REALENGINE_PLATFORM_WINDOWS",
			"REALENGINE_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "REALENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "REALENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "REALENGINE_DIST"
		symbols "On"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"realengine/vendor/spdlog/include",
		"realengine/src"
	}

	links {
		"realengine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"REALENGINE_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "REALENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "REALENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "REALENGINE_DIST"
		symbols "On"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"
