# === modules/window/tests/CMakeLists.txt ===
add_executable(WindowTests
    test_window.cpp
)

target_link_libraries(WindowTests PRIVATE Window)

# Optional: Copy DLL next to test EXE for runtime linking
add_custom_command(TARGET WindowTests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Window>
        $<TARGET_FILE_DIR:WindowTests>
)

add_test(NAME WindowTests COMMAND WindowTests)
