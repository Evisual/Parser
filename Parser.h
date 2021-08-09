//
// Created by Evisual on 8/8/2021.
//
#pragma once

#include <fstream>
#include <vector>

namespace Parser {

    class Parse
    {
    public:
        virtual void ParseFile(std::string filepath) = 0;

    private:

    };
}