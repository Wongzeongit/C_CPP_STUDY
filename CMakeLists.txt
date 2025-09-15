cmake_minimum_required(VERSION 4.0)
project(AllC_CPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(CMakeProject1/CMakeProject1)

add_executable(AllC_CPP
        C/7周课后1.c
        C/try.c
        C/zuoye.c
        CPP/zuoye.cpp
        CPP/打奖.cpp
        CPP/测试.cpp
        CMakeProject1/CMakeProject1/CMakeProject1.cpp
        CMakeProject1/CMakeProject1/CMakeProject1.h
        Cpractice/1-1.cpp
        Cpractice/1-2.cpp
        Cpractice/1-3.cpp
        Cpractice/1-4.cpp
        Cpractice/1-5.cpp
        DATASTRUCTURE/1-1.cpp
        DATASTRUCTURE/1-2.cpp
        DATASTRUCTURE/1-3.cpp
        DATASTRUCTURE/1-4.cpp
        HelloWorld.cpp
        Cpractice/3-1(peach).cpp
        DATASTRUCTURE/1-4/List.h
        Cpractice/3-2(carno).cpp
        Cpractice/3-3(pp).cpp
        "Cpractice/3-4(tranOcttoDec).cpp"
        "Cpractice/3-5(nkcs).cpp"
        "Cpractice/3-6(HIndex).cpp"
)
