// JsonDocument.cpp

#include <fstream>
#include <iostream>
#include <vector>
#include "nlohmann/json.hpp"
#include "JsonDocument.h"
using json = nlohmann::json;

void JsonDocument::parseFile(std::ifstream &file) {
    json data = json::parse(file);
    vector<File> files = prepareDocumentFiles(data["files"]);
    vector<jsonPackage> packages = prepareDocumentPackages(data["packages"]);
    vector<externalDocumentRef> externalDocumentRefs = prepareExternalDocumentRefs(data["externalDocumentRefs"]);
    vector<jsonRelationship> relationships = prepareDocumentRelationships(data["relationships"]);
    CreationInfo creationInfo = prepareCreationInfo(data["creationInfo"]);

    setFiles(files);
    setPackages(packages);
    setExternalDocumentRefs(externalDocumentRefs);
    setRelationships(relationships);
    setSpdxVersion(data["spdxVersion"]);
    setDataLicense(data["dataLicense"]);
    setSPDXID(data["SPDXID"]);
    setName(data["name"]);
    setDocumentNamespace(data["documentNamespace"]);
}
vector<File> JsonDocument::getFiles() { return files; }
vector<jsonPackage> JsonDocument::getPackages() { return packages; }
vector<externalDocumentRef> JsonDocument::getExternalDocumentRefs() { return externalDocumentRefs; }
vector<jsonRelationship> JsonDocument::getRelationships() { return relationships; }
string JsonDocument::getSpdxVersion() { return spdxVersion; }
string JsonDocument::getDataLicense() { return dataLicense; }
string JsonDocument::getSPDXID() { return SPDXID; }
string JsonDocument::getName() { return name; }
string JsonDocument::getDocumentNamespace() { return documentNamespace; }
// CreationInfo JsonDocument::getCreationInfo() {}
// vector<string> JsonDocument::getDocumentDescribes() {}

void JsonDocument::setFiles(vector<File> files) { this->files = files; }
void JsonDocument::setPackages(vector<jsonPackage> packages) { this->packages = packages; }
void JsonDocument::setExternalDocumentRefs(vector<externalDocumentRef> externalDocumentRefs) { this->externalDocumentRefs = externalDocumentRefs; }
void JsonDocument::setRelationships(vector<jsonRelationship> relationships) { this->relationships = relationships; }
void JsonDocument::setSpdxVersion(string spdxVersion) { this->spdxVersion = spdxVersion; }
void JsonDocument::setDataLicense(string dataLicense) { this->dataLicense = dataLicense; }
void JsonDocument::setSPDXID(string spdxid) { this->SPDXID = spdxid; }
void JsonDocument::setName(string name) { this->name = name; }
void JsonDocument::setDocumentNamespace(string documentNamespace) { this->documentNamespace = documentNamespace; }
void JsonDocument::setCreationInfo(CreationInfo creationInfo) { creationInfo = creationInfo; }
void JsonDocument::setDocumentDescribes(vector<string> documentDescribes) { documentDescribes = documentDescribes; }

vector<File> JsonDocument::prepareDocumentFiles(json files) {
    vector<File> docFiles; 
    for (auto it = files.begin(); it != files.end(); it++) {
        File file;
        file.fileName = ((json) *it)["fileName"];
        file.SPDXID = ((json) *it)["SPDXID"];
        file.licenseConcluded = ((json) *it)["licenseConcluded"];
        file.copyrightText = ((json) *it)["copyrightText"];

        auto checksums = ((json) *it)["checksums"];
        for (auto cs : checksums) {
            Checksum checksum;
            checksum.algorithm = cs["algorithm"];
            checksum.checksumValue = cs["checksumValue"];
            file.checksums.push_back(checksum);
        }
        auto licenseInfoInFiles = ((json) *it)["lisenceInfoInFiles"];
        for (auto li : licenseInfoInFiles) {
            file.licenseInfoInFiles.push_back(li);
        }
        auto fileTypes = ((json) *it)["fileTypes"];
        for (auto ft : fileTypes) {
            file.fileTypes.push_back(ft);
        }
        docFiles.push_back(file);
    }
    return docFiles;
}

vector<jsonPackage> JsonDocument::prepareDocumentPackages(json packages) {
    vector<jsonPackage> docPackages; 
    for (auto it = packages.begin(); it != packages.end(); it++) {
        jsonPackage jsonPackage;
        jsonPackage.name = ((json) *it)["name"];
        jsonPackage.SPDXID = ((json) *it)["SPDXID"];
        jsonPackage.downloadLocation = ((json) *it)["downloadLocation"];
        jsonPackage.filesAnalyzed = ((json) *it)["filesAnalyzed"];
        jsonPackage.licenseConcluded = ((json) *it)["licenseConcluded"];
        jsonPackage.licenseDeclared = ((json) *it)["licenseDeclared"];
        jsonPackage.copyrightText = ((json) *it)["copyrightText"];
        jsonPackage.versionInfo = ((json) *it)["versionInfo"];
        jsonPackage.supplier = ((json) *it)["supplier"];

        auto licenseInfoFromFiles = ((json) *it)["lisenceInfoInFiles"];
        for (auto li : licenseInfoFromFiles) {
            jsonPackage.licenseInfoFromFiles.push_back(li);
        }
        auto externalRefs = ((json) *it)["externalRefs"];
        for (auto er : externalRefs) {
            externalRef externalRef;
            externalRef.referenceCategory = er["referenceCategory"];
            externalRef.referenceLocator = er["referenceLocator"];
            externalRef.referenceType = er["referenceType"];
            jsonPackage.externalRefs.push_back(externalRef);
        }
        docPackages.push_back(jsonPackage);
    }
    return docPackages;
}

vector<externalDocumentRef> JsonDocument::prepareExternalDocumentRefs(json eDRs) {
    vector<externalDocumentRef> externalDocumentRefs;
    for (auto it = eDRs.begin(); it != eDRs.end(); it++) {
        externalDocumentRef edf; 
        edf.externalDocumentId = ((json) *it)["externalDocumentId"];
        edf.spdxDocument = ((json) *it)["spdxDocument"];
        Checksum checksum;
        checksum.algorithm = ((json) *it)["checksum"]["algorithm"];
        checksum.checksumValue = ((json) *it)["checksum"]["checksumValue"];
        edf.checksum = checksum;
        externalDocumentRefs.push_back(edf);
    }
    return externalDocumentRefs;
}

vector<jsonRelationship> JsonDocument::prepareDocumentRelationships(json relationships) {
    vector<jsonRelationship> documentRelationships;
    for (auto it = relationships.begin(); it != relationships.end(); it++) {
        jsonRelationship relationship;
        relationship.relationshipType = ((json) *it)["relationshipType"];
        relationship.relatedSpdxElement = ((json) *it)["relatedSpdxElement"];
        relationship.spdxElementId = ((json) *it)["spdxElementId"];
        documentRelationships.push_back(relationship);
    }
    return documentRelationships;
}

CreationInfo prepareCreationInfo(json creationInfo) {
    //TODO: Finish this method.
    CreationInfo ci; 
    // ci.created = creationInfo["created"];
}