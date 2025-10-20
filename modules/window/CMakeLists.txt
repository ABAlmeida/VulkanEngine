add_library(Window SHARED
    src/window.cpp
)

target_include_directories(Window PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(Window PRIVATE WINDOW_EXPORTS)

if(WIN32)
    target_link_libraries(Window PRIVATE user32)
endif()

# Add debug-only flags (optional)
target_compile_options(Window PRIVATE
    $<$<CONFIG:Debug>:/Zi>
    $<$<CONFIG:Release>:/O2>
)

# === Tests ===
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()