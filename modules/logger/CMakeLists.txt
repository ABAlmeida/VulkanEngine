# Logger as a shared library
add_library(Logger SHARED
    src/logger.cpp
)

target_include_directories(Logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(Logger PRIVATE LOGGER_EXPORTS)

# Add debug-only flags (optional)
target_compile_options(Logger PRIVATE
    $<$<CONFIG:Debug>:/Zi>
    $<$<CONFIG:Release>:/O2>
)

# === Tests ===
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()