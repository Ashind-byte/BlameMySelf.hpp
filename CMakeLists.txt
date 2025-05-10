cmake_minimum_required(VERSION 3.10)
project(HeaderGen)

set(CMAKE_CXX_STANDARD 17)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/HeaderGen)


add_executable(HeaderGen
    main.cpp
    BlameMyself.cpp
)
set(CONFIG_FILE ${CMAKE_SOURCE_DIR}/Includes.conf)

add_custom_command(
    TARGET HeaderGen POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CONFIG_FILE}
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Includes.conf
)