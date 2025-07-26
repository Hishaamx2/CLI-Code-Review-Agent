#include "FileParser.h"
#include <fstream>
#include <iostream>

// Reads the file at the given path and returns its contents line-by-line
std::vector<std::string> FileParser::readFile(const std::string& filepath) {
    std::vector<std::string> lines;
    std::ifstream file(filepath);
    std::string line;

    // If the file couldn't be opened, print an error and return an empty vector
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file: " << filepath << "\n";
        return lines;
    }

    // Read each line from the file and add it to the vector
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    // Close the file after reading
    file.close();

    // Return the vector containing all lines from the file
    return lines;
} //reads a source file from disk and returns all the lines of code