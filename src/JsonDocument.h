// Json Document
#ifndef JSON_DOCUMENT_H
#define JSON_DOCUMENT_H

#include <vector>
#include <fstream>
#include "JsonUtils/File.h"
#include "JsonUtils/jsonPackage.h"
#include "JsonUtils/externalDocumentRef.h"
#include "JsonUtils/jsonRelationship.h"
#include "JsonUtils/creationInfo.h"
#include "nlohmann/json.hpp"
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
        JsonDocument() {
            files = {};
            packages = {};
            externalDocumentRefs = {};
            relationships = {};
            spdxVersion = "";
            dataLicense = "";
            SPDXID = "";
            name = "";
            documentNamespace = "";
            creationInfo = {};
            documentDescribes = {};
        }
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
            vector<string> documentDescribes) 
            {
                files = files;
                packages = packages;
                externalDocumentRefs = externalDocumentRefs;
                relationships = relationships;
                spdxVersion = spdxVersion;
                dataLicense = dataLicense;
                SPDXID = SPDXID;
                name = name;
                documentNamespace = documentNamespace;
                creationInfo = creationInfo;
                documentDescribes = documentDescribes;
        }
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

        void parseFile(std::ifstream &file);
};

#endif