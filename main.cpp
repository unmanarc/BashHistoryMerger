#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <stdint.h>
#include <string>
#include <unordered_set>

typedef std::unordered_set<std::string> StringSet;
typedef std::map<uint64_t, StringSet> TimeCommandMap;

void processFile(const char *filePath, TimeCommandMap &data)
{
    std::ifstream file(filePath);
    std::string line;
    uint64_t currentTimestamp = 0;
    std::regex timestampRegex("^#[0-9]+$");

    while (std::getline(file, line))
    {
        if (std::regex_match(line, timestampRegex))
        {
            // New timestamp
            currentTimestamp = std::stoull(line.substr(1));
        }
        else
        {
            // Command
            data[currentTimestamp].insert(line);
        }
    }
}

int main(int argc, char *argv[])
{
    // Print author, program name, copyright, and license to stderr
    if ( argc < 2 )
    {
        std::cerr << "Author: Aaron Mizrachi <aaron@unmanarc.com>" << std::endl;
        std::cerr << "Program: BashHistoryMerger v1.0" << std::endl;
        std::cerr << "Copyright (c) 2023 Aaron Mizrachi. All rights reserved." << std::endl;
        std::cerr << "This program is licensed under the GNU General Public License, version 3." << std::endl;
        std::cerr << "For more details, see: https://www.gnu.org/licenses/gpl-3.0.txt" << std::endl << std::endl;
        std::cerr << "Usage: BashHistoryMerger file1 file2 filen..." << std::endl;
        return 0;
    }

    TimeCommandMap data;

    // Process each file from argv
    for (int i = 1; i < argc; ++i)
    {
        processFile(argv[i], data);
    }

    // Print out data
    for (const auto &kv : data)
    {
        std::cout << "#" << kv.first << std::endl;
        for (const auto &command : kv.second)
        {
            std::cout << command << std::endl;
        }
    }

    return 0;
}
