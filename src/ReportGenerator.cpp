#include "ReportGenerator.h"
#include <iostream>

// This method prints a formatted report of all detected issues in the given source file
void ReportGenerator::printReport(const std::vector<Issue>& issues, const std::string& filename) {
    //header
    std::cout << "===== Code Review Report for " << filename << " =====\n";

    // If no issues were found, print a success message and exit
    if (issues.empty()) {
        std::cout << " No major issues found. Great job!\n";
        return;
    }

    // Loop through each issue and print its details
    for (const auto& issue : issues) {
        std::cout << "[Line " << issue.lineNumber << "] "
                  << issue.description
                  << " | Severity: " << issue.severity << "\n";
    }

    // Print a footer
    std::cout << "===== End of Report =====\n";
}