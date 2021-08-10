//
// Created by Evisual on 8/8/2021.
//
#include "Parser.h"

namespace Parser
{
    class CSVParser : public Parse
    {
    public:
        inline std::vector<std::string> getRows() { return m_Rows; }
        inline std::vector<std::string> getColumns() { return m_Columns; }
        inline std::vector<std::vector<std::string>> getCells() { return m_Cells; }

        inline std::string getRow(int row) { return m_Rows[row]; }
        inline std::string getColumn(int column) { return m_Columns[column]; }
        inline std::string getCell(int row, int column) { return m_Cells[row][column]; }

        inline int getTotalRows() { return m_Rows.size(); }
        inline int getTotalColumns() { return m_Columns.size(); }
        inline int getTotalCells() { return m_Rows.size()*m_Columns.size(); }

        void ParseFile(std::string filepath) override;

        bool printLines = false;
        bool skipEmptyLines = false;
        int fromLine = 0;
    private:
        std::vector<std::string> m_Rows;
        std::vector<std::string> m_Columns;
        std::vector<std::vector<std::string>> m_Cells;
    };
}