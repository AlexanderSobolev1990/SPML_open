cmake_minimum_required(VERSION 3.7)
project(spml LANGUAGES CXX) # SPML (Special Program Modules Library) - Cпециальная Библиотека Программных Модулей (СБПМ)
get_filename_component(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../ ABSOLUTE) # Путь к корневой директории решения (solution)
message(STATUS "CMake version: ${CMAKE_VERSION}, Project: ${PROJECT_NAME}, ROOT_DIR: ${ROOT_DIR}")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
    include/spml.h    
    include/consts.h
    include/convert.h
    include/compare.h
    include/geodesy.h    
    include/lap.h    
    include/statistics.h
    include/timekeeper.h
    include/units.h
    )

set(SOURCES
    src/spml.cpp
    src/convert.cpp
    src/geodesy.cpp    
    src/lap.cpp    
    src/statistics.cpp
    src/timekeeper.cpp
    )

add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES}) # Динамическая библиотека

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include        
)

find_package(BLAS REQUIRED)
#find_package(LAPACK REQUIRED)
find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${ARMADILLO_LIBRARIES}        
)

target_compile_options(${PROJECT_NAME} PUBLIC -fPIC) # Position Independent Code

#if(CMAKE_VERSION VERSION_GREATER 3.16) # Опция простого добавления PCH доступна при версии CMake >= 3.16
#    target_precompile_headers(${PROJECT_NAME}
#        PRIVATE
#            <cmath>
#            <ctime>
#            <string>
#            <cassert>
#            <type_traits>
#            <limits>
#            <armadillo>
#    )
#endif()

# Включить замеры времени сборки
set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")
set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CMAKE_COMMAND} -E time")
