#include <iostream>
#include <vector>
#include <string>

#include "FileParser.h"
#include "StaticAnalyzer.h"
#include "ReportGenerator.h"

int main(int argc, char* argv[]) {
    // Check if the user provided a file path argument
    if (argc < 2) {
        std::cerr << "Usage: ./review_agent <source_file.cpp>\n";
        return 1; // Exit with error code if no file is provided
    }

    // Get the path to the source file from command-line arguments
    std::string filepath = argv[1];

    // Use FileParser to read the file and return a vector of code lines
    std::vector<std::string> codeLines = FileParser::readFile(filepath);
    
    // Create a StaticAnalyzer object to run detectors
    StaticAnalyzer analyzer;

    // Run all detectors on the code lines and collect any issues found
    std::vector<Issue> issues = analyzer.runAllDetectors(codeLines);

    // Print a formatted report of all detected issues
    ReportGenerator::printReport(issues, filepath);

    return 0;
}