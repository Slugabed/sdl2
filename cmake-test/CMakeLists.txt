cmake_minimum_required(VERSION 3.3)

project (cmake-test)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

find_package(SDL2 REQUIRED COMPONENTS SDL2)
find_package(SDL2_image REQUIRED)
add_executable(${PROJECT_NAME} Game.cpp Game.hpp GameObject.cpp GameObject.hpp Map.cpp Map.hpp TextureManager.cpp TextureManager.hpp main.cpp)

target_link_libraries(cmake-test PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/Resources/ $<TARGET_FILE_DIR:cmake-test>/Resources)
