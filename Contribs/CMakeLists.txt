idf_component_register(
    INCLUDE_DIRS "."
)


if(NOT CMAKE_BUILD_EARLY_EXPANSION)
    set(SURE_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Sure ${CMAKE_BINARY_DIR}/Sure)

    get_target_property(_sure_type Sure TYPE)
    if(NOT _sure_type STREQUAL "INTERFACE_LIBRARY")
        idf_build_get_property(_opts     COMPILE_OPTIONS)
        idf_build_get_property(_cxx_opts CXX_COMPILE_OPTIONS)
        idf_build_get_property(_defs     COMPILE_DEFINITIONS)
        target_compile_options(Sure PRIVATE ${_opts} $<$<COMPILE_LANGUAGE:CXX>:${_cxx_opts}>)
        target_compile_definitions(Sure PRIVATE ${_defs})
    endif()

    target_link_libraries(${COMPONENT_LIB} INTERFACE Sure)
endif()