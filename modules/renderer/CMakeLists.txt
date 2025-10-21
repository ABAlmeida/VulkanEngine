add_engine_module(Renderer
    SRC src/renderer.cpp
    INCLUDE include
)

# Link Platform into Renderer
target_link_libraries(Renderer PUBLIC Platform)