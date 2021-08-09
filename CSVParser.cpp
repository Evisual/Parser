//
// Created by Evisual on 8/8/2021.
//

#include "CSVParser.h"

#include <fstream>
#include <iostream>
#include <sstream>

namespace Parser
{

    void CSVParser::ParseFile(std::string filepath, bool printLines)
    {
        std::fstream file;
        file.open(filepath, std::ios::in);

        if(!file.is_open())
        {
            throw std::runtime_error("Failed to open specified file! \n Filepath: " + filepath);
        }

        std::string line;

        int i=0;

        std::string row;

        while(std::getline(file, line))
        {
            std::string cell;
            std::vector<std::string> currentRowCells;
            for(auto &c : line)
            {
                if(c == ',')
                {
                    c = ' ';
                    currentRowCells.push_back(cell);
                    cell.clear();
                }
                cell.push_back(c);
                row.push_back(c);
            }

            i++;

            if(printLines)
                std::cout << "Line: " << i << " " << line << std::endl;

            m_Rows.push_back(row);
            m_Cells.push_back(currentRowCells);
            row.clear();
        }
    }

}
