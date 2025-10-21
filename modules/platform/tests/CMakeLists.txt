# === modules/platform/tests/CMakeLists.txt ===
add_executable(PlatformTests
    test_platform.cpp
)

target_link_libraries(PlatformTests PRIVATE Logger)

# Optional: Copy DLL next to test EXE for runtime linking
add_custom_command(TARGET PlatformTests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Platform>
        $<TARGET_FILE_DIR:PlatformTests>
)

add_test(NAME PlatformTests COMMAND PlatformTests)
