# Parser
Parser to parse different filetypes. Currently only supports CSV.

## CSV Parser

### Parse File
```C++
#include <ParserIncludes.h>

int main() 
{

   Parser::CSVParser parser; // Initialize parser object
   parser.ParseFile("filepath"); // Parse file "filepath"
   
   parser.printLines(true); // Determine whether or not parser will print lines while parsing (Defaults to false)
   parser.skipEmptyLines(true); // Determine whether or not parser will skip empty lines (Defaults to false)
   parser.fromLine((int)line); // Determine which line parser will start from (Defaults to 0)
}
```

### Accessing Data

```C++
#include <ParserIncludes.h>

Parser::CSVParser parser; // Initialize parser object

std::vector<std::string> rows = parser.getRows(); // Load all rows in the CSV File 
std::string row = parser.getRow((int)row); // Loads data from one row
int TotalRows = parser.getTotalRows(); // Gets total amount of rows

std::vector<std::string> columns = parser.getColumns(); // Load all columns in the CSV File (Not working)
std::string column = parser.getColumn((int)column); // Loads data from one column (Not working) 
int TotalColumns = parser.getTotalColumns(); // Gets total amount of column (Not working)

std::vector<std::vector<std::string>> cells = parser.getCells(); // Loads all cells
std::string cell = parser.getCell((int)row, (int)column); // Loads data from one cell
int TotalCells = parser.getTotalCells(); // Gets total amount of cells parsed (Not working)
```
