#ifndef MISSINGCOMMENTDETECTOR_H
#define MISSINGCOMMENTDETECTOR_H

#include <vector>
#include <string>
#include "../Issue.h"

class MissingCommentDetector {
public:
    std::vector<Issue> detect(const std::vector<std::string>& codeLines);
};

#endif