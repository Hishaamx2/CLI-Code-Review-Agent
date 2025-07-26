#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <string>
#include <vector>

class FileParser {
public:
    static std::vector<std::string> readFile(const std::string& filepath);
};

#endif