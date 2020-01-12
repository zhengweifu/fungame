cmake_minimum_required(VERSION 3.0.0)

# 设置项目
project(FunGame)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/deps/glew/include)

include_directories(${CMAKE_SOURCE_DIR}/deps/glfw3/include)


find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})  


set(GLEW_LIBPATH ${CMAKE_SOURCE_DIR}/deps/glew/prebuilt/x64)
set(GLFW_LIBPATH ${CMAKE_SOURCE_DIR}/deps/glfw3/prebuilt/x64/lib-vc2019)
set(SELF_LIBPATH ${CMAKE_BINARY_DIR}/lib)

if(MSVC)
	set(CMAKE_CXX_FLAGS "/nologo /J /Gd /EHsc /MP" CACHE STRING "MSVC MT C++ flags " FORCE)
	set(CMAKE_C_FLAGS   "/nologo /J /Gd /MP"       CACHE STRING "MSVC MT C++ flags " FORCE)

	if(CMAKE_CL_64)
		set(CMAKE_CXX_FLAGS_DEBUG "/Od /RTC1 /MTd /Zi /MP" CACHE STRING "MSVC MT flags " FORCE)
	else()
		set(CMAKE_CXX_FLAGS_DEBUG "/Od /RTC1 /MTd /ZI /MP" CACHE STRING "MSVC MT flags " FORCE)
	endif()
	set(CMAKE_CXX_FLAGS_RELEASE "/O2 /Ob2 /MT /MP" CACHE STRING "MSVC MT flags " FORCE)
	set(CMAKE_CXX_FLAGS_MINSIZEREL "/O1 /Ob1 /MT /MP" CACHE STRING "MSVC MT flags " FORCE)
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/O2 /Ob1 /MT /Zi /MP" CACHE STRING "MSVC MT flags " FORCE)
	if(CMAKE_CL_64)
		set(CMAKE_C_FLAGS_DEBUG "/Od /RTC1 /MTd /Zi /MP" CACHE STRING "MSVC MT flags " FORCE)
	else()
		set(CMAKE_C_FLAGS_DEBUG "/Od /RTC1 /MTd /ZI /MP" CACHE STRING "MSVC MT flags " FORCE)
	endif()
	set(CMAKE_C_FLAGS_RELEASE "/O2 /Ob2 /MT /MP" CACHE STRING "MSVC MT flags " FORCE)
	set(CMAKE_C_FLAGS_MINSIZEREL "/O1 /Ob1 /MT /MP" CACHE STRING "MSVC MT flags " FORCE)
	set(CMAKE_C_FLAGS_RELWITHDEBINFO "/O2 /Ob1 /MT /Zi /MP" CACHE STRING "MSVC MT flags " FORCE)
endif()

add_subdirectory(src)