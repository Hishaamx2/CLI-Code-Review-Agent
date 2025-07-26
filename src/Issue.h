#ifndef ISSUE_H
#define ISSUE_H

#include <string>

struct Issue {
    int lineNumber;
    std::string description;
    std::string severity;
};

#endif