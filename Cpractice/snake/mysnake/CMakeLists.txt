cmake_minimum_required(VERSION 4.0)
project(mysnake)

set(CMAKE_CXX_STANDARD 20)
set(EGE_INC_DIR "E:/AllC_CPP/database/ege24.04_all/ege24.04/include")
set(EGE_LINK_DIR "E:/AllC_CPP/database/ege24.04_all/ege24.04/lib/mingw64/mingw-w64-gcc-8.1.0-x86_64")

include_directories(${EGE_INC_DIR})
link_directories(${EGE_LINK_DIR})

add_executable(mysnake main.cpp
        snake.cpp
        snake.h)

target_link_libraries(mysnake graphics gdi32 gdiplus)