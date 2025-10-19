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

# Force /std:c++latest for MSVC to unlock C++26 features
if(MSVC)
    add_compile_options(/std:c++latest)
endif()

# Optional: set default build type if none provided
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Add subprojects (modules and engine)
enable_testing()
add_subdirectory(modules/logger)
add_subdirectory(modules/window)
add_subdirectory(modules/renderer)
add_subdirectory(engine)
