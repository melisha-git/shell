cmake_minimum_required(VERSION 3.8)
project(shell)

set (COMMANDS_FILES
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
