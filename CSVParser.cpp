//
// Created by Evisual on 8/8/2021.
//

#include "CSVParser.h"

#include <fstream>
#include <iostream>
#include <sstream>

namespace Parser
{

    void CSVParser::ParseFile(std::string filepath)
    {
        std::fstream file;
        file.open(filepath, std::ios::in);

        if(!file.is_open())
        {
            throw std::runtime_error("Failed to open specified file! \n Filepath: " + filepath);
        }

        std::string line;

        int i=0;
        while(std::getline(file, line))
        {
            std::cout << "Line: " << ++i << " " << line << std::endl;
            CSVParser::m_Rows.emplace_back(line);
        }
    }

}
