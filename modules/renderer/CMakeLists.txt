# Renderer as a shared library
add_library(Renderer SHARED
    src/renderer.cpp
)

target_include_directories(Renderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(Renderer PRIVATE RENDERER_EXPORTS)

# Add debug-only flags (optional)
target_compile_options(Renderer PRIVATE
    $<$<CONFIG:Debug>:/Zi>
    $<$<CONFIG:Release>:/O2>
)

# === Tests ===
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()