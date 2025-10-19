# Engine executable
add_executable(VulkanEngine
    src/main.cpp
)

target_include_directories(VulkanEngine PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# Link all modules
target_link_libraries(VulkanEngine PRIVATE
    Logger
    Window
    Renderer
)

# Copy all DLLs after build
add_custom_command(TARGET VulkanEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Logger>
        $<TARGET_FILE:Window>
        $<TARGET_FILE:Renderer>
        $<TARGET_FILE_DIR:VulkanEngine>
)