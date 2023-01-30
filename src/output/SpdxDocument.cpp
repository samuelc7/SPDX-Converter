#include "SpdxDocument.h"

SpdxDocument::SpdxDocument() : header{}, packages{} {};
SpdxDocument::SpdxDocument(SpdxDocumentHeader h, std::vector<Package> p) {
    header = h;
    packages = p;
}

SpdxDocumentHeader SpdxDocument::getHeader() { return header; }
std::vector<Package> SpdxDocument::getPackages() { return packages; }

void SpdxDocument::setHeader(SpdxDocumentHeader h) { this->header = h; }
void SpdxDocument::setPackages(std::vector<Package> p) { this->packages = p; }

void SpdxDocument::populateFromJsonDoc(JsonDocument jsonDoc) {
    header.setSPDXVersion(jsonDoc.getSpdxVersion());
    header.setDataLicence(jsonDoc.getDataLicense());
    header.setSPDXID(jsonDoc.getSPDXID());
    header.setDocumentName(jsonDoc.getName());
    header.setDocumentNamespace(jsonDoc.getDocumentNamespace());
    header.setCreators(jsonDoc.getCreationInfo().creators);
    header.setCreated(jsonDoc.getCreationInfo().created.toString());
    header.setCreatorComment("<text></text>"); // TODO: make this dynamic

    //TODO: Add the packages
}

void SpdxDocument::writeToFile(std::filesystem::path filePath) {
    std::ofstream outputFile;
    outputFile.open(filePath);
    outputFile << header.toString();
    outputFile << "## Packages\n";
    for (Package p : packages) {
        p.toString();
    }

    outputFile.close();
}