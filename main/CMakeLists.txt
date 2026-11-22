idf_component_register(
    SRCS "Main.cpp"
    INCLUDE_DIRS "."
    REQUIRES freertos esp_system soc Contribs Platform App
)


#if(NOT CMAKE_BUILD_EARLY_EXPANSION)
#    idf_component_get_property(PLATFORM_LIB Platform COMPONENT_LIB)
#
##    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../Drivers    ${CMAKE_BINARY_DIR}/Drivers)
#
##    target_link_libraries(${COMPONENT_LIB} PUBLIC Supervisor)
#endif()