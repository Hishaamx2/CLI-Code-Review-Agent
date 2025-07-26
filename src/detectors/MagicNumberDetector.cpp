#include "MagicNumberDetector.h"
#include <regex>

#include "MagicNumberDetector.h"
#include <regex>

std::vector<Issue> MagicNumberDetector::detect(const std::vector<std::string>& codeLines) {
    std::vector<Issue> issues;  // Holds all the issues found

    // Regex pattern to match standalone numbers (e.g. 42, 3.14) that are not part of a word
    std::regex numberPattern(R"([^a-zA-Z_](\d+(\.\d+)?)[^a-zA-Z_])");

    // Loop through each line of the code
    for (size_t i = 0; i < codeLines.size(); ++i) {
        const std::string& line = codeLines[i];

        // Skip lines that commonly and legitimately contain numbers:
        // - for loops (e.g., for (int i = 0; i < 10; ++i))
        // - array access (e.g., arr[10])
        // - constants and macros
        if (line.find("for") != std::string::npos ||
            line.find("[") != std::string::npos ||
            line.find("const") != std::string::npos ||
            line.find("#define") != std::string::npos) {
            continue;  // Don't flag these lines
        }

        // If the line contains a magic number, flag it
        if (std::regex_search(line, numberPattern)) {
            Issue issue;
            issue.lineNumber = i + 1;
            issue.description = "Magic number detected (e.g., numeric literal without explanation)";
            issue.severity = "Low";
            issues.push_back(issue);
        }
    }

    return issues;  // Return all detected issues
}