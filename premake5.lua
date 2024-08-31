workspace "Reytracing Challenge"
	configurations { "Debug", "Release", "Dist" }
	conformancemode "On"
	architecture "x64"
		
	project "Raytracer"
		kind "ConsoleApp"
		
		language "C++"
		cppdialect "C++20"
		outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
		targetdir ("../build/bin/" .. outputdir .. "/%{prj.name}")
		objdir ("../build/bin-int/" .. outputdir .. "/%{prj.name}")
		
		files {
			"src/**.h",
			"src/**.c",
			"src/**.hpp",
			"src/**.cpp",
		}
		includedirs { 
			"src/",
			"libs/GLFW3/include",
		}
		
		links {
			"opengl32",
			"libs/GLFW3/lib/glfw3",
		}

		flags { "MultiProcessorCompile" }
			defines { "_CRT_SECURE_NO_WARNINGS", "_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING" }


		filter "configurations:Debug"
			optimize "Off"
			symbols "On"

		filter "configurations:Release"
			optimize "On"
			symbols "Default"

		filter "configurations:Dist"
			optimize "Full"
			symbols "Off"

	


