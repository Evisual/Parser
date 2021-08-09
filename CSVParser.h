//
// Created by Evisual on 8/8/2021.
//
#include "Parser.h"

namespace Parser
{
    class CSVParser : public Parse
    {
    public:
        inline std::string getLine(int line) { return m_Rows.at(line); }
        inline std::string getColumn(int column) { return m_Columns.at(column); }
        
        void ParseFile(std::string filepath) override;
    private:
        std::vector<std::string> m_Rows;
        std::vector<std::string> m_Columns;
    };
}