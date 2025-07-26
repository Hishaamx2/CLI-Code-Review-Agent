#include "DeepNestingDetector.h"

std::vector<Issue> DeepNestingDetector::detect(const std::vector<std::string>& codeLines) {
    std::vector<Issue> issues;    // Stores all deep nesting issues found
    int currentDepth = 0;         // Tracks how deep the nesting is

    // Go through each line of code
    for (size_t i = 0; i < codeLines.size(); ++i) {
        const std::string& line = codeLines[i];

        // Count braces on the line to adjust nesting level
        for (char c : line) {
            if (c == '{') currentDepth++;  // Going deeper
            if (c == '}') currentDepth--;  // Coming back up
        }

        // If nesting exceeds allowed depth (3), flag the line
        if (currentDepth > 3) {
            Issue issue;
            issue.lineNumber = i + 1;  // Line number (1-based)
            issue.description = "Nesting level exceeds 3 (current level: " + std::to_string(currentDepth) + ")";
            issue.severity = "High";
            issues.push_back(issue);
        }
    }

    return issues;  // Return all issues found
}