# Root CMakeLists for VulkanEngine
cmake_minimum_required(VERSION 3.29)
project(VulkanEngine LANGUAGES CXX)

option(BUILD_TESTS "Build all module tests" ON)
if(BUILD_TESTS)
    enable_testing()
endif()

# Use the most modern features available
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include our helper
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(addmodule)

# Make Final a valid build type
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Final" CACHE STRING "" FORCE)

# Optional: set default build type if none provided
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE $<CONFIG> CACHE STRING "Build type" FORCE)
endif()

# Set build output directories (organized by config)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIG>)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIG>)

# Allow IDEs to show folders (nice organization in Visual Studio)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
# Override for Final build
if(CMAKE_BUILD_TYPE STREQUAL "Final")
	add_definitions(-DFINAL_BUILD)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)  # Enables /GL for MSVC, -flto for GCC/Clang
endif()

# Force /std:c++latest for MSVC to unlock C++26 features
if(MSVC)
    add_compile_options(/std:c++latest)
endif()

# Add subprojects (modules and engine)
add_subdirectory(modules/logger)
add_subdirectory(modules/platform)
add_subdirectory(modules/renderer)
add_subdirectory(modules/window)
add_subdirectory(engine)
