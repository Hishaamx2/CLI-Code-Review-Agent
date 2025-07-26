#ifndef LONGFUNCTIONDETECTOR_H
#define LONGFUNCTIONDETECTOR_H

#include <vector>
#include <string>
#include "../Issue.h"

class LongFunctionDetector {
public:
    std::vector<Issue> detect(const std::vector<std::string>& codeLines);
};

#endif