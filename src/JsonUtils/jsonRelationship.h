// jsonRelationship
#ifndef JSON_RELATIONSHIP_H
#define JSON_RELATIONSHIP_H

#include <string>
using std::string;

struct jsonRelationship {
    string relationshipType;
    string relatedSpdxElement;
    string spdxElementId;
};

#endif