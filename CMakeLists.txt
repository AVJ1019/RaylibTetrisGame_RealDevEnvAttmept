cmake_minimum_required(VERSION 3.10)
project(TetrisSpil)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    "${CMAKE_SOURCE_DIR}/external/includes"
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/include/entities"
    "${CMAKE_SOURCE_DIR}/include/game"
    "${CMAKE_SOURCE_DIR}/include/managers"
    "${CMAKE_SOURCE_DIR}/include/scenes"
    "${CMAKE_SOURCE_DIR}/include/scenes/start"
    "${CMAKE_SOURCE_DIR}/src/scene/start"
    )

file( GLOB_RECURSE glob_files
    "${CMAKE_SOURCE_DIR}/include/*.h"
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

# Vi peger nu på .a filen i stedet for .lib
add_library(raylib_static STATIC IMPORTED)
set_target_properties(raylib_static PROPERTIES 
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/external/libraries/libraylib.a"
)

add_executable(${PROJECT_NAME} ${glob_files})

# Sørg for at linke til shell32 og user32 også, da de er vigtige for Windows-vinduer
target_link_libraries(${PROJECT_NAME} 
    raylib_static 
    opengl32 
    gdi32 
    winmm
    shell32
    user32
    -static-libgcc
    -static-libstdc++
)

# Denne linje fikser din "WinMain" fejl ved at fortælle compileren, 
# at vi kører en konsol-applikation (standard main)
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-mconsole")