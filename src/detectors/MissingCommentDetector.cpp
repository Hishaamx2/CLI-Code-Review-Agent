#include "MissingCommentDetector.h"
#include <regex>

std::vector<Issue> MissingCommentDetector::detect(const std::vector<std::string>& codeLines) {
    std::vector<Issue> issues;  // List of all issues found

    // Regex to match typical C++ function declarations with return type, name, params, and opening brace
    std::regex funcRegex(R"((\w[\w\s*&:<>,]+)\s+(\w+)\s*\(.*\)\s*\{)");

    // Start from line 1 to safely look back at line i-1
    for (size_t i = 1; i < codeLines.size(); ++i) {
        // If this line looks like a function declaration
        if (std::regex_search(codeLines[i], funcRegex)) {
            bool hasComment = false;

            // Look up to 2 lines above for a comment
            for (int j = static_cast<int>(i) - 1; j >= 0 && j >= static_cast<int>(i) - 2; --j) {
                std::string trimmed = codeLines[j];

                // Trim leading whitespace
                trimmed.erase(0, trimmed.find_first_not_of(" \t"));

                // Check if the trimmed line starts with // or /* (basic comment formats)
                if (trimmed.rfind("//", 0) == 0 || trimmed.rfind("/*", 0) == 0) {
                    hasComment = true;
                    break;
                }
            }

            // If no comment is found before the function, flag it
            if (!hasComment) {
                Issue issue;
                issue.lineNumber = i + 1;
                issue.description = "Function missing documentation comment";
                issue.severity = "Moderate";
                issues.push_back(issue);
            }
        }
    }

    return issues;  // Return all issues
}