cmake_minimum_required(VERSION 3.20)
project(ParserLib)

set(CMAKE_CXX_STANDARD 14)

add_library(ParserLib library.cpp Parser.cpp Parser.h ParserIncludes.h CSVParser.cpp CSVParser.h)
target_include_directories(ParserLib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        #$<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
        )

export(TARGETS ParserLib FILE ParserLibTargets.cmake)