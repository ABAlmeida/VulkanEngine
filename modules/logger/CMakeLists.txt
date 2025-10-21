add_engine_module(Logger
    SRC src/logger.cpp
    INCLUDE include
)

# Link Platform into Logger
target_link_libraries(Logger PUBLIC Platform)