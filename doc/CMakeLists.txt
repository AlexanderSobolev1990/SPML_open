cmake_minimum_required(VERSION 3.7)
set(DOXYGEN_TARGET_NAME project_documentation) # Вторая часть имени файла с настройками Doxygen
get_filename_component(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../ ABSOLUTE) # Путь к корневой директории решения (solution)

set(DOXYGEN_INPUT_DIRECTORY # Откуда брать исходники для документации
    ${ROOT_DIR}/program/spml
)
set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}) # Куда положить сгенерированную документацию

if(${CMAKE_VERSION} VERSION_GREATER "3.8")
#if(CMAKE_VERSION VERSION_LESS 3.9)
    # Версия CMake >= 3.9 умеет сама создавать файл настроек doxygen, что мы и делаем:
    message(WARNING "Doxygen do not need config file, options are taken from CMakeLists.txt")

    # Укажем ключи Doxygen
    set(DOXYGEN_DOXYFILE_ENCODING UTF-8)
    set(DOXYGEN_PROJECT_NAME "SPML open version")
    set(DOXYGEN_PROJECT_BRIEF "Special Program Modules Library")
    set(DOXYGEN_EXTRACT_ALL YES) #NO) #
#    set(DOXYGEN_EXTRACT_PRIVATE YES) # NO) #
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "${ROOT_DIR}/README.md")
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_LATEX NO)
    set(DOXYGEN_GENERATE_TREEVIEW YES)
#    set(DOXYGEN_SOURCE_BROWSER NO) # Не включать исходники! *.cpp
    set(DOXYGEN_SOURCE_BROWSER YES) # Включать исходники! *.cpp
    set(DOXYGEN_HTML_TIMESTAMP YES)
    set(DOXYGEN_EXCLUDE ${ROOT_DIR}/program/tpcl/src/radar.h) # Исключить обработку файла с координатами изделия!

    # Создадим файл настроек Doxygen
    doxygen_add_docs(
        ${DOXYGEN_TARGET_NAME}
        ${ROOT_DIR}/README.md
        ${DOXYGEN_INPUT_DIRECTORY}
        ALL
        WORKING_DIRECTORY ${DOXYGEN_OUTPUT_DIRECTORY}
        COMMENT "Generating doxygen project documentation"
    )
else()
    # Версия CMake <= 3.9 НЕ умеет сама создавать файл настроек doxygen, поэтому файл должен быть заранее подготовлен!
    set(DOXYGEN_SETTINGS_FILE ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.${DOXYGEN_TARGET_NAME}) # CMake дает имя файлу настроек Doxyfile.{user_defined}

    if(EXISTS ${DOXYGEN_SETTINGS_FILE}) # Если файл настроек есть
        add_custom_target(
            ${DOXYGEN_TARGET_NAME}
            ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_SETTINGS_FILE} # doxygen-у надо передать имя файла с настройками
            WORKING_DIRECTORY ${DOXYGEN_OUTPUT_DIRECTORY}
            COMMENT "Generating doxygen project documentation"
        )
    else()
        message(WARNING "Doxygen config file was not found, project documenation creation skipped!")
    endif()

endif()


