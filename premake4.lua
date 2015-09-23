-- A solution contains projects, and defines the available configurations
solution "CQueue"
	configurations { "Debug", "Release" }
	location "build"
 
	-- A project defines one build target
	project "queue"
		location "build"
		kind "ConsoleApp"
		language "C"
		--files { "*.h", "*.c" }
		files
		{
			"main.c",
			"queue_i.c",
			"queue_i.h",
			"queue_d.c",
			"queue_d.h",
			"queue_str.c",
			"queue_str.h",
			"queue_void.c",
			"queue_void.h",
			"queue_tests.c"
		}
		excludes
		{
		}
--      libdirs { }
		links { "cunit" } 
	  targetdir "build"
  
		configuration "Debug"
			defines { "DEBUG" }
			flags { "Symbols" }
 
		configuration "Release"
			defines { "NDEBUG" }
			flags { "Optimize" }
 
		configuration { "linux", "gmake" }
			buildoptions { "-ansi", "-pedantic-errors", "-fno-strict-aliasing", "-Wunused-variable", "-Wreturn-type" }

--[[

	project "cqueue"
		location "build"
		kind "ConsoleApp"
		language "C"
		files
		{
		}
	 --  excludes { "vector_template.*", "vector_tests.c" }
--      libdirs { }
		links { "cunit" } 
	  targetdir "build"
  
		configuration "Debug"
			defines { "DEBUG" }
			flags { "Symbols" }
 
		configuration "Release"
			defines { "NDEBUG" }
			flags { "Optimize" }
 
		configuration { "linux", "gmake" }
			buildoptions { "-ansi", "-pedantic-errors", "-fno-strict-aliasing", "-Wunused-variable", "-Wreturn-type" }


	project "queuecpp"
		location "build"
		kind "ConsoleApp"
		language "C++"
		files
		{
			"main.cpp",
		}
	 --  excludes { }
--      libdirs { }
 --     links { "cunit" } 
	  targetdir "build"
  
		configuration "Debug"
			defines { "DEBUG" }
			flags { "Symbols" }
 
		configuration "Release"
			defines { "NDEBUG" }
			flags { "Optimize" }
 
		configuration { "linux", "gmake" }
			buildoptions { "-ansi", "-pedantic-errors", "-fno-strict-aliasing", "-Wunused-variable", "-Wreturn-type", "-x c++" }


	project "cvectorcpp"
		location "build"
		kind "ConsoleApp"
		language "C++"
		files
		{
			  "main2.cpp",
			  "cvector.h"
		}
	 --  excludes { "vector_template.*", "vector_tests.c" }
--      libdirs { }
		links { "cunit" } 
	  targetdir "build"
  
		configuration "Debug"
			defines { "DEBUG" }
			flags { "Symbols" }
 
		configuration "Release"
			defines { "NDEBUG" }
			flags { "Optimize" }
 
		configuration { "linux", "gmake" }
			buildoptions { "-ansi", "-pedantic-errors", "-fno-strict-aliasing", "-Wunused-variable", "-Wreturn-type", "-x c++" }
		  
]]

