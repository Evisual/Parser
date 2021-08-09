# Parser
Parser to parse different filetypes. Currently only supports CSV.

## CSV Parser

### Parse File
```C++
#include <CSVParser.h>

int main() 
{

   Parser::CSVParser parser; // Initialize parser object
   parser.ParseFile("filepath"); // Parse file "filepath"

}
```

### Accessing Data

```C++
#include <CSVParser.h>

Parser::CSVParser parser; // Initialize parser object

std::vector<std::string> rows = parser.getRows(); // Load all rows in the CSV File 
std::string row = parser.getRow((int)row); // Loads data from one row

std::vector<std::vector<std::string>> cells = parser.getCells(); // Loads all cells
std::string cell = std::getCell((int)row, (int)column); // Loads data from one cell
```
