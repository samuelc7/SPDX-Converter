#ifndef CHECKSUM_H
#define CHECKSUM_H

#include <string>
using std::string;

struct Checksum {
    string algorithm;
    string checksumValue;
};

#endif