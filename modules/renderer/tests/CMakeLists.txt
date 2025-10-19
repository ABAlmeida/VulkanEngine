# === modules/renderer/tests/CMakeLists.txt ===
add_executable(RendererTests
    test_renderer.cpp
)

target_link_libraries(RendererTests PRIVATE Renderer)

# Optional: Copy DLL next to test EXE for runtime linking
add_custom_command(TARGET RendererTests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Renderer>
        $<TARGET_FILE_DIR:RendererTests>
)

add_test(NAME RendererTests COMMAND RendererTests)
