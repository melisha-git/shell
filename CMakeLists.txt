cmake_minimum_required(VERSION 3.8)
project(shell)

set(SOURCE_FILES main.cpp CommandLine.cpp utility.cpp ICommand.cpp EchoCommand.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
