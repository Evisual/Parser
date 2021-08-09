cmake_minimum_required(VERSION 3.20)
project(ParserLib)

set(CMAKE_CXX_STANDARD 14)

add_library(ParserLib src/Parser.cpp src/Parser.h ParserIncludes.h src/CSVParser.cpp src/CSVParser.h)
target_include_directories(ParserLib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        #$<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
        )

export(TARGETS ParserLib FILE ParserLibTargets.cmake)