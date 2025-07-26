#include "StaticAnalyzer.h"
// These are all individual detectors that look for specific types of code issues
#include "detectors/LongFunctionDetector.h"
#include "detectors/MagicNumberDetector.h"
#include "detectors/DeepNestingDetector.h"
#include "detectors/BadNameDetector.h"
#include "detectors/MissingCommentDetector.h"

std::vector<Issue> StaticAnalyzer::runAllDetectors(const std::vector<std::string>& codeLines) {
    // This vector will store all issues found by every detector
    std::vector<Issue> allIssues;

    // Long Function Detector:
    // Checks for functions that are too long (i.e., hard to read/maintain)
    LongFunctionDetector longFuncDetector;
    std::vector<Issue> longFuncIssues = longFuncDetector.detect(codeLines);
    allIssues.insert(allIssues.end(), longFuncIssues.begin(), longFuncIssues.end());

    // Magic Number Detector:
    // Looks for unexplained hard-coded numbers (like "if (x > 42)")
    MagicNumberDetector magicNumDetector;
    std::vector<Issue> magicNumIssues = magicNumDetector.detect(codeLines);
    allIssues.insert(allIssues.end(), magicNumIssues.begin(), magicNumIssues.end());

    // Deep Nesting Detector:
    // Finds code with too many nested levels (like too many if/for inside each other)
    DeepNestingDetector deepDetector;
    std::vector<Issue> nestingIssues = deepDetector.detect(codeLines);
    allIssues.insert(allIssues.end(), nestingIssues.begin(), nestingIssues.end());

    // Bad Name Detector:
    // Flags variable/function names that are too short or unclear (e.g., "x", "a1")
    BadNameDetector nameDetector;
    std::vector<Issue> nameIssues = nameDetector.detect(codeLines);
    allIssues.insert(allIssues.end(), nameIssues.begin(), nameIssues.end());

    // Missing Comment Detector:
    // Detects functions that don't have any comments/documentation above them
    MissingCommentDetector commentDetector;
    std::vector<Issue> commentIssues = commentDetector.detect(codeLines);
    allIssues.insert(allIssues.end(), commentIssues.begin(), commentIssues.end()); 

    // Return the full list of issues found by all detectors
    return allIssues;
}