add_engine_module(Window
    SRC src/window.cpp
    INCLUDE include
)

# Platform-specific linking
if(WIN32)
    # Automatically link against user32
    target_link_libraries(Window PRIVATE user32)
endif()

# Link Platform into Window
target_link_libraries(Window PUBLIC Platform)