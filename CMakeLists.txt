cmake_minimum_required(VERSION 3.5)

project(Containers)

add_executable(Containers Containers.cpp SerialContainer.cpp SingleLinkContainer.cpp DoubleLinkContainer.cpp)

set_target_properties(Containers PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

