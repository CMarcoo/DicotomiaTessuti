cmake_minimum_required(VERSION 3.17)
project(DicotomiaTessuti C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(DicotomiaTessuti
        dicotomia_tessuti.c
        chiavi.h
        chiavi_dicotomiche.c
        tessuti.c
        tessuti.h)
