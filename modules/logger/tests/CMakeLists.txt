# === modules/logger/tests/CMakeLists.txt ===
add_executable(LoggerTests
    test_logger.cpp
)

target_link_libraries(LoggerTests PRIVATE Logger)

# Optional: Copy DLL next to test EXE for runtime linking
add_custom_command(TARGET LoggerTests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Logger>
        $<TARGET_FILE_DIR:LoggerTests>
)

add_test(NAME LoggerTests COMMAND LoggerTests)
