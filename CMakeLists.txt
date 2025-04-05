cmake_minimum_required(VERSION 3.30)
project(Lithium)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lithium src/main.cpp
        include/entity.h
        include/world.h
        src/world.cpp
        src/entity.cpp
        lib/PerlinNoise.hpp
        include/living.h
        src/living.cpp
        include/game.h
        src/game.cpp)

include_directories(headers G:/Programming/Projects/Lithium/include G:/Programming/Projects/Lithium/lib G:/SFML/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED COMPONENTS system window graphics)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Lithium ${SFML_LIBRARIES})
endif()

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
