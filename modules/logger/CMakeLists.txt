# Logger as a shared library
add_library(Logger SHARED
    src/logger.cpp
)

target_include_directories(Logger PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# === Tests ===
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()