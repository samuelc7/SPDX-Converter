// creationInfo

#ifndef CREATION_INFO_H
#define CREATION_INFO_H

#include <string>
#include <vector>
#include "../DateTime.h"
using std::string;
using std::vector;

struct CreationInfo {
    DateTime created;
    vector<string> creators;
};

#endif