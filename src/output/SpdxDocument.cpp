#include <sstream>
#include <map>
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

    // Set up the relationshipMap
    std::map<string, std::vector<string>> relationshipMap;
    populateRelationshipMap(relationshipMap, jsonDoc.getRelationships());

    std::vector<jsonPackage> jsonPackages = jsonDoc.getPackages();
    for (jsonPackage jp : jsonPackages) {
        Package package{};
        package.setPackageName(jp.name);
        package.setSSPDXID(jp.SPDXID);
        string externalRefStr = prepareExternalRefs(jp.externalRefs);
        package.setExternalRef(externalRefStr);
        if (jp.externalRefs.size() == 1) {
            package.setPackageComment("<text>PURL is " + jp.externalRefs[0].referenceLocator + "</text>");
        } else {
            package.setPackageComment("NOASSERTION"); // TODO: make this dynamic
        }
        package.setPackageVersion(jp.versionInfo);
        package.setPackageSupplier(jp.supplier);
        package.setRelationships(relationshipMap[jp.SPDXID]);
        package.setPackageDownloadLocation(jp.downloadLocation);
        package.setFilesAnalyzed(jp.filesAnalyzed);
        package.setPackageLicenseConcluded(jp.licenseConcluded);
        package.setPackageLicenseDeclared(jp.licenseDeclared);
        package.setPackageCopyrightText(jp.copyrightText);
        this->packages.push_back(package);
    }
}

void SpdxDocument::writeToFile(std::filesystem::path filePath) {
    std::ofstream outputFile;
    outputFile.open(filePath);
    // Write the header
    outputFile << header.toString();
    // Write the packages
    outputFile << "## Packages\n";
    for (Package p : packages) {
        outputFile << p.toString();
    }
    outputFile.close();
}

string SpdxDocument::prepareExternalRefs(std::vector<externalRef> vRefs) {
    std::stringstream sstm;
    for (externalRef er : vRefs) {
        sstm << er.referenceCategory << ' ' << er.referenceType << ' ' << er.referenceLocator;
    }
    return sstm.str();
}

void SpdxDocument::populateRelationshipMap(std::map<string, std::vector<string>> &rMap, std::vector<jsonRelationship> jsonRelationships) {
    for (jsonRelationship jr : jsonRelationships) {
        // if it exists as key, append to its vector
        if (rMap.find(jr.spdxElementId) != rMap.end()) {
            rMap[jr.spdxElementId].push_back(jr.spdxElementId + ' ' + jr.relationshipType + ' ' + jr.relatedSpdxElement);
        } else {
            rMap[jr.spdxElementId] = std::vector<string> {jr.spdxElementId + ' ' + jr.relationshipType + ' ' + jr.relatedSpdxElement};
        }
    }
}