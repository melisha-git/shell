cmake_minimum_required(VERSION 3.8)
project(shell)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

set(COMMANDS_FILES
    Commands/ICommand.cpp
    Commands/EchoCommand.cpp
    Commands/LsCommand.cpp
    Commands/CdCommand.cpp
    Commands/PwdCommand.cpp
    Commands/ExportCommand.cpp
    Commands/UnsetCommand.cpp
    Commands/EnvCommand.cpp
    Commands/ExitCommand.cpp
)

set(SOURCE_FILES
    ${COMMANDS_FILES}
    main.cpp
    CommandLine.cpp
    utility.cpp
    Parser.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE Boost::unit_test_framework)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)