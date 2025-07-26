#ifndef MAGICNUMBERDETECTOR_H
#define MAGICNUMBERDETECTOR_H

#include <vector>
#include <string>
#include "../Issue.h"

class MagicNumberDetector {
public:
    std::vector<Issue> detect(const std::vector<std::string>& codeLines);
};

#endif