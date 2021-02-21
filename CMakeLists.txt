cmake_minimum_required(VERSION 3.7)
project(spml_open)
message(STATUS "CMake version: ${CMAKE_VERSION}, Project: ${PROJECT_NAME}")

if(NOT CMAKE_BUILD_TYPE) # Если не указан тип сборки, собрать в режиме Release
  set(CMAKE_BUILD_TYPE Release)
endif()
message(WARNING "Build mode: ${CMAKE_BUILD_TYPE}")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

if(CMAKE_BUILD_TYPE MATCHES "^[Rr]elease") # Актуально для Linux
    option(BUILD_DOCUMENTATION "Build project documentation (Requires Doxygen)" ON) # Опционально построение документации: ON|OFF
endif()

add_compile_options(
    -Wall    
    "$<$<CONFIG:RELEASE>:-O3>"
    "$<$<CONFIG:DEBUG>:-O0>"
)

add_subdirectory(program/spml) # SPML (Special Program Modules Library) - Cпециальная Библиотека Программных Модулей (СБПМ)

# Тесты
#add_subdirectory(test/spml/compare)
#add_subdirectory(test/spml/lap)

# Скрипт запуска откомпилированных тестов копируется в директорию bin для удобства их запуска не из-под IDE
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}) # Нужно, чтобы директория существовала
configure_file(
    script/run_all_tests.sh
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/run_all_tests.sh
    COPYONLY
)

# Генерация документации
if(BUILD_DOCUMENTATION)
    find_package(Doxygen
        REQUIRED dot) # dot - требуется Graphviz dot утилита для построения графиков в документации
    if(DOXYGEN_FOUND)
        add_subdirectory(doc) # В поддиректории проекта /doc должен быть CMakeLists.txt с настройками Doxygen
    else()
        message(WARNING "Doxygen need to be installed to generate the doxygen documentation")
    endif()
endif()
