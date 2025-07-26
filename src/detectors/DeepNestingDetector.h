#ifndef DEEPNESTINGDETECTOR_H
#define DEEPNESTINGDETECTOR_H

#include <vector>
#include <string>
#include "../Issue.h"

class DeepNestingDetector {
public:
    std::vector<Issue> detect(const std::vector<std::string>& codeLines);
};

#endif