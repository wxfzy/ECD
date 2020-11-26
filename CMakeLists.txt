cmake_minimum_required(VERSION 3.17)
project(ECD)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)
include_directories(SOURCE_CODE)
include_directories(SOURCE_CODE/IDE_FILES_FOLDER)

add_executable(ECD
        .idea/ECD.iml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        LICENSE
        README.md)
