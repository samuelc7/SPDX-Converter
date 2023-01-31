// Json Document
#ifndef JSON_DOCUMENT_H
#define JSON_DOCUMENT_H

#include <vector>
#include <fstream>
#include "JsonUtils/File.h"
#include "JsonUtils/jsonPackage.h"
#include "JsonUtils/externalDocumentRef.h"
#include "JsonUtils/externalRef.h"
#include "JsonUtils/jsonRelationship.h"
#include "JsonUtils/creationInfo.h"
#include "../nlohmann/json.hpp"
using std::vector;
using json = nlohmann::json;

class JsonDocument {
    private:
        vector<File> files;
        vector<jsonPackage> packages;
        vector<externalDocumentRef> externalDocumentRefs;
        vector<jsonRelationship> relationships;
        string spdxVersion;
        string dataLicense;
        string SPDXID;
        string name;
        string documentNamespace;
        CreationInfo creationInfo;
        vector<string> documentDescribes;

        vector<File> prepareDocumentFiles(json files);
        vector<jsonPackage> prepareDocumentPackages(json packages);
        vector<externalDocumentRef> prepareExternalDocumentRefs(json eDRs);
        vector<jsonRelationship> prepareDocumentRelationships(json relationships);
        CreationInfo prepareCreationInfo(json creationInfo);
    public:
        // Constructors
        JsonDocument();
        JsonDocument(
            vector<File> files,
            vector<jsonPackage> packages,
            vector<externalDocumentRef> externalDocumentRefs,
            vector<jsonRelationship> relationships,
            string spdxVersion,
            string dataLicense,
            string SPDXID,
            string name,
            string documentNamespace,
            CreationInfo creationInfo,
            vector<string> documentDescribes);

        // Getters
        vector<File> getFiles();
        vector<jsonPackage> getPackages();
        vector<externalDocumentRef> getExternalDocumentRefs();
        vector<jsonRelationship> getRelationships();
        string getSpdxVersion();
        string getDataLicense();
        string getSPDXID();
        string getName();
        string getDocumentNamespace();
        CreationInfo getCreationInfo();
        vector<string> getDocumentDescribes();

        // Setters
        void setFiles(vector<File> files);
        void setPackages(vector<jsonPackage> packages);
        void setExternalDocumentRefs(vector<externalDocumentRef> externalDocumentRefs);
        void setRelationships(vector<jsonRelationship> relationships);
        void setSpdxVersion(string spdxVersion);
        void setDataLicense(string dataLicense);
        void setSPDXID(string spdxid);
        void setName(string name);
        void setDocumentNamespace(string documentNameSpace);
        void setCreationInfo(CreationInfo creationInfo);
        void setDocumentDescribes(vector<string> documentDescribes);

        /**
         * @brief Parses json file and grabs the data neccessary for 
         *         the spdx file. This includes the files, packages, 
         *         externalDocumentRefs, relationships, creationInfo,
         *         spdxVersion, dataLicense, SPDXID, name, documentNameSpace,
         *         and documentDescribes. 
         * 
         * @param file - ifstream& of json file to be patched.
         */
        void parseJsonFile(std::ifstream &file);

        /**
         * @brief This will convert the JsonDocument obj into 
         *         a readable string with the data it contains.
         *         Used for testing mainly. 
         * @return string 
         */
        string toString();
};

#endif