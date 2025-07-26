#ifndef BADNAMEDETECTOR_H
#define BADNAMEDETECTOR_H

#include <vector>
#include <string>
#include "../Issue.h"

class BadNameDetector {
public:
    std::vector<Issue> detect(const std::vector<std::string>& codeLines);
};

#endif