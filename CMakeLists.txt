cmake_minimum_required(VERSION 3.17)
project(DicotomiaTessuti C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(DicotomiaTessuti
        dicotomia_tessuti.c
        chiavi.h
        chiavi.c
        colori_ansi.h
        tessuti.c
        tessuti.h
        domanda.h
        domanda.c
        errori.h
        domanda_tessuto.h)
