// JsonDocument.cpp

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "nlohmann/json.hpp"
#include "JsonDocument.h"
using json = nlohmann::json;


JsonDocument::JsonDocument() {
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

JsonDocument::JsonDocument(vector<File> files, 
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

void JsonDocument::parseJsonFile(std::ifstream &file) {
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
    setCreationInfo(creationInfo);
    setDocumentDescribes(data["documentDescribes"]);
}

std::string JsonDocument::toString() {
    std::stringstream sstm;
    sstm << "\nJsonDocument Information: \n";
    sstm << "---------------------------------------------------------------------------------\n";
    sstm << "Name: " << this->getName() << '\n';
    sstm << "SPDXID: " << this->getSPDXID() << '\n';
    sstm << "SPDXVersion: " << this->getSpdxVersion() << '\n';
    sstm << "DataLicense: " << this->getDataLicense() << '\n';
    sstm << "DocumentNameSpace: " << this->getDocumentNamespace() << '\n';
    sstm << "File count: " << this->getFiles().size() << '\n';
    sstm << "Package count: " << this->getPackages().size() << '\n';
    sstm << "ExertnalDocumentRefs count: " << this->getExternalDocumentRefs().size() << '\n';
    sstm << "Relationships count: " << this->getRelationships().size() << '\n';
    sstm << "CreationInfo: \n" << 
            "\t-Created: " << this->getCreationInfo().created.toString() << '\n' <<
            "\t-Creators: \n";
    for (auto creator : this->getCreationInfo().creators) {
        sstm << "\t\t--" << creator << '\n';
    }
    sstm << "DocumentDescribes: \n";
    for (auto describe : this->getDocumentDescribes()) {
        sstm << "\t-" << describe << '\n';
    }
    sstm << "---------------------------------------------------------------------------------\n";
    return sstm.str();
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
CreationInfo JsonDocument::getCreationInfo() { return creationInfo; }
vector<string> JsonDocument::getDocumentDescribes() { return documentDescribes; }

void JsonDocument::setFiles(vector<File> files) { this->files = files; }
void JsonDocument::setPackages(vector<jsonPackage> packages) { this->packages = packages; }
void JsonDocument::setExternalDocumentRefs(vector<externalDocumentRef> externalDocumentRefs) { this->externalDocumentRefs = externalDocumentRefs; }
void JsonDocument::setRelationships(vector<jsonRelationship> relationships) { this->relationships = relationships; }
void JsonDocument::setSpdxVersion(string spdxVersion) { this->spdxVersion = spdxVersion; }
void JsonDocument::setDataLicense(string dataLicense) { this->dataLicense = dataLicense; }
void JsonDocument::setSPDXID(string spdxid) { this->SPDXID = spdxid; }
void JsonDocument::setName(string name) { this->name = name; }
void JsonDocument::setDocumentNamespace(string documentNamespace) { this->documentNamespace = documentNamespace; }
void JsonDocument::setCreationInfo(CreationInfo creationInfo) { this->creationInfo = creationInfo; }
void JsonDocument::setDocumentDescribes(vector<string> documentDescribes) { this->documentDescribes = documentDescribes; }

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

CreationInfo JsonDocument::prepareCreationInfo(json creationInfo) {
    CreationInfo ci; 
    DateTime dt; 
    string date = creationInfo["created"];
    dt.parseString(creationInfo["created"]);
    ci.created = dt;
    ci.creators = creationInfo["creators"];
    return ci;
}