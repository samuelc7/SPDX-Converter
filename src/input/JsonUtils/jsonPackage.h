// jsonPackage
#include <string>
#include <vector>
#include "externalRef.h"
using std::string;
using std::vector;

struct jsonPackage {
    string name;
    string SPDXID;
    string downloadLocation;
    bool filesAnalyzed;
    string licenseConcluded;
    vector<string> licenseInfoFromFiles;
    string licenseDeclared;
    string copyrightText;
    string versionInfo;
    vector<externalRef> externalRefs;
    string supplier;
};