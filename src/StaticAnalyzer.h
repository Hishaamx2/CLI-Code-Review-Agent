#ifndef STATICANALYZER_H
#define STATICANALYZER_H

#include <vector>
#include <string>
#include "Issue.h"

// StaticAnalyzer class is responsible for running all code detectors
class StaticAnalyzer {
public:
    // This is the main method that runs all detectors on the provided source code
    // Input: a vector of code lines (strings)
    // Output: a vector of detected issues
    std::vector<Issue> runAllDetectors(const std::vector<std::string>& codeLines);
};

#endif