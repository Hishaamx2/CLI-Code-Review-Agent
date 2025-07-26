#include "LongFunctionDetector.h"
#include <regex>

std::vector<Issue> LongFunctionDetector::detect(const std::vector<std::string>& codeLines) {
    std::vector<Issue> issues;  // List to store any long function issues

    bool inFunction = false;       // Tracks whether were inside a function body
    int braceCount = 0;            // Tracks nested braces to know when function ends
    int functionStartLine = -1;    // Records the line where the function starts

    for (size_t i = 0; i < codeLines.size(); ++i) {
        const std::string& line = codeLines[i];

        // Regex to detect the beginning of a function definition
        std::regex funcRegex(R"((\w[\w\s*&:<>,]+)\s+(\w+)\s*\(.*\)\s*\{)");
        
        // If we're not inside a function and we find a function start
        if (!inFunction && std::regex_search(line, funcRegex)) {
            inFunction = true;         // Now were inside a function
            braceCount = 1;            // One opening brace found
            functionStartLine = i;     // Record where the function starts
            continue;
        }

        // If we're already inside a function
        if (inFunction) {
            // Count additional braces to keep track of when the function ends
            for (char c : line) {
                if (c == '{') braceCount++;
                if (c == '}') braceCount--;
            }

            // When brace count returns to zero, we have exited the function
            if (braceCount == 0) {
                int length = (i - functionStartLine) + 1;  // Calculate function length

                // If function is too long, flag it
                if (length > 20) {
                    Issue issue;
                    issue.lineNumber = functionStartLine + 1;
                    issue.description = "Function exceeds 20 lines (" + std::to_string(length) + " lines)";
                    issue.severity = "Moderate";
                    issues.push_back(issue);
                }

                // Reset for next function
                inFunction = false;
            }
        }
    }

    return issues;
}