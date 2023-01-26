// externalDocumentRef
#ifndef EXTERNAL_DOCUMENT_REF_H
#define EXTERNAL_DOCUMENT_REF_H

#include <string>
#include <vector>
#include "checksum.h"
using std::string;
using std::vector;

struct externalDocumentRef {
    string externalDocumentId;
    string spdxDocument;
    Checksum checksum;
};

#endif