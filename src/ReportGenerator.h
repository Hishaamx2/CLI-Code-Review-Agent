#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <vector>
#include <string>
#include "Issue.h"

class ReportGenerator {
public:
    static void printReport(const std::vector<Issue>& issues, const std::string& filename);
};

#endif