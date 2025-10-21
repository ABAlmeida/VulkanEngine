# cmake/AddModule.cmake
function(add_engine_module MODULE_NAME)
    # Parse arguments like:
    # add_engine_module(Logger SRC src/logger.cpp INCLUDE include)
    cmake_parse_arguments(MOD "" "" "SRC;INCLUDE" ${ARGN})

    # 1️ Build type (shared)
    add_library(${MODULE_NAME} SHARED ${MOD_SRC})

    # 2️ Include directories
    target_include_directories(${MODULE_NAME} PUBLIC ${MOD_INCLUDE})

    # 3️ Compilation definitions
    target_compile_definitions(${MODULE_NAME} PRIVATE ${MODULE_NAME}_EXPORTS)

	set_target_properties(${MODULE_NAME} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)

    # 4️ Configuration-based compile flags
    target_compile_options(${MODULE_NAME} PRIVATE
        $<$<CONFIG:Debug>:/Zi>
        $<$<CONFIG:Release>:/O2>
        $<$<CONFIG:Final>:/O2 /GL>
    )

    # 6️ Auto-include tests if they exist
    if(BUILD_TESTS)
		set(TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests")
        if(EXISTS "${TEST_DIR}/CMakeLists.txt")
            add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
			
			# Look for any test executables defined in that subdir and register them
            # Convention: test target is <ModuleName>Tests
            if(TARGET ${MODULE_NAME}Tests)
                add_test(
                    NAME ${MODULE_NAME}Tests
                    COMMAND ${MODULE_NAME}Tests
                )
            endif()
        endif()
    endif()

    message(STATUS "✅ Registered module: ${MODULE_NAME}")
endfunction()
