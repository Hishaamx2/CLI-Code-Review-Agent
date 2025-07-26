#include "BadNameDetector.h"
#include <regex>

std::vector<Issue> BadNameDetector::detect(const std::vector<std::string>& codeLines) {
    std::vector<Issue> issues;  // Stores all detected naming issues

    // Regular expression to match basic variable declarations
    // Example it matches: int x; or float val;
    std::regex varPattern(R"(\b(int|float|double|char|bool|auto)\s+(\w+))");

    // List of vague or non-descriptive variable names we want to flag
    std::vector<std::string> badNames = {"x", "y", "z", "val", "tmp", "data"};

    // Loop through every line of the code
    for (size_t i = 0; i < codeLines.size(); ++i) {
        std::smatch match;
        
        // If a variable declaration matches the regex pattern
        if (std::regex_search(codeLines[i], match, varPattern)) {
            std::string varName = match[2];  // Extract the variable name

            // Check if the name is in our list of bad names
            if (std::find(badNames.begin(), badNames.end(), varName) != badNames.end()) {
                Issue issue;
                issue.lineNumber = i + 1;  // Store the line number (1-indexed)
                issue.description = "Unclear variable name detected: '" + varName + "'";
                issue.severity = "Moderate";
                issues.push_back(issue);  // Add this issue to the list
            }
        }
    }

    return issues;  // Return all detected issues
}