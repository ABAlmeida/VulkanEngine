add_library(Window SHARED
    src/window.cpp
)

target_include_directories(Window PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(WIN32)
    target_link_libraries(Window PRIVATE user32)
endif()

# === Tests ===
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()