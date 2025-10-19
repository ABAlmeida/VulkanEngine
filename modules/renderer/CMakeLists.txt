add_library(Renderer SHARED
    src/renderer.cpp
)

target_include_directories(Renderer PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# === Tests ===
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()