//
// Created by Evisual on 8/8/2021.
//

#include "CSVParser.h"

#include <chrono>
#include <iostream>
#include <sys/timeb.h>
#include <ctime>
#include <string>
#include <Windows.h>

namespace Parser
{

    void CSVParser::ParseFile(std::string filepath)
    {
        auto duration = std::chrono::system_clock::now().time_since_epoch();
        auto initialTime = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

        std::fstream file;
        file.open(filepath, std::ios::in);

        auto currentTime1 = std::chrono::system_clock::now().time_since_epoch();
        auto currentTimeMillis = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime1).count();

        std::cout << "File Loaded: " << currentTimeMillis-initialTime << " ms" << std::endl;

        if(!file.is_open())
        {
            throw std::runtime_error("Failed to open specified file! \n Filepath: " + filepath);
        }

        std::string line;

        int i=0;

        std::string row;

        bool lineEmpty = true;

        while(std::getline(file, line))
        {
            lineEmpty = true;
            std::cout << line << "\n";
            if(i++ < fromLine)
                continue;

            int column = 0;
            std::string cell;
            std::vector<std::string> currentRowCells;
            for(auto &c : line)
            {
                if(c == ',')
                {
                    c = ' ';
                    currentRowCells.push_back(cell);
                    cell.clear();

                    lineEmpty = false;
                    column++;
                }
                cell.push_back(c);
                row.push_back(c);
            }

            if(printLines)
                std::cout << "Line: " << i << " " << line << std::endl;

            if(!skipEmptyLines || !lineEmpty) // If line is empty (lineEmpty) & we are skipping empty lines,
                {
                    m_Rows.push_back(row);
//                    std::cout << "i = " << i << " m_Rows Size: " << m_Rows.size() << std::endl;
                    if (i != m_Rows.size())
                    {
                        std::cout << "NOT EQUAL\n";
                    }

                }
            else
            {
                std::cout << "ELSE\n";
            }

            m_Cells.push_back(currentRowCells);
            row.clear();


        }
        auto currentTime3 = std::chrono::system_clock::now().time_since_epoch();
        auto currentTimeMillis2 = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime3).count();
        std::cout << "Finished: " << currentTimeMillis2-initialTime << " ms" << std::endl;
    }

}
