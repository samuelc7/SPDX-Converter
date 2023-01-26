// file
#ifndef FILE_H
#define FILE_H

#include <string>
#include "checksum.h"
#include <vector>
using std::string;
using std::vector;

struct File {
    string fileName;
    string SPDXID;
    vector<Checksum> checksums;
    string licenseConcluded;
    vector<string> licenseInfoInFiles;
    string copyrightText;
    vector<string> fileTypes;
};

#endif