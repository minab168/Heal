cmake_minimum_required(VERSION 3.22)


set(EXTRA_COMPONENT_DIRS
    ${CMAKE_CURRENT_LIST_DIR}/Common
    ${CMAKE_CURRENT_LIST_DIR}/Contribs
    ${CMAKE_CURRENT_LIST_DIR}/Platform
    ${CMAKE_CURRENT_LIST_DIR}/Drivers
    ${CMAKE_CURRENT_LIST_DIR}/App
)


include(${CMAKE_CURRENT_LIST_DIR}/App/CMakeLists.txt)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

project(Heal)
