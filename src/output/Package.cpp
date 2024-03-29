#include "Package.h"
#include <sstream>
#include <vector>
using std::string;


Package::Package() {
    PackageName = "";
    SPDXID = "";
    PackageComment = "";
    ExternalRef = "";
    PackageVersion = "";
    PackageSupplier = "";
    Relationships = {};
    PackageDownloadLocation = "";
    FilesAnalyzed = false;
    PackageLicenseConcluded = "";
    PackageLicenseDeclared = "";
    PackageCopyrightText = "";
}

Package::Package(
        string PackageName,
        string SPDXID,
        string PackageComment,
        string ExternalRef,
        string PackageVersion,
        string PackageSupplier,
        std::vector<string> Relationships,
        string PackageDownloadLocation,
        string FilesAnalyzed,
        string PackageLicenseConcluded,
        string PackageLicenseDeclared,
        string PackageCopyrightText) 
    {
        PackageName = PackageName;
        SPDXID = SPDXID;
        PackageComment = PackageComment;
        ExternalRef = ExternalRef;
        PackageVersion = PackageVersion;
        PackageSupplier = PackageSupplier;
        Relationships = Relationships;
        PackageDownloadLocation = PackageDownloadLocation;
        FilesAnalyzed = FilesAnalyzed;
        PackageLicenseConcluded = PackageLicenseConcluded;
        PackageLicenseDeclared = PackageLicenseDeclared;
        PackageCopyrightText = PackageCopyrightText;
    }

string Package::getPackageName() { return PackageName; }
string Package::getSPDXID() { return SPDXID; }
string Package::getPackageComment() { return PackageComment; }
string Package::getExternalRef() { return ExternalRef; }
string Package::getPackageVersion() { return PackageVersion; }
string Package::getPackageSupplier() { return PackageSupplier; }
std::vector<string> Package::getRelationships() { return Relationships; }
string Package::getPackageDownloadLocation() { return PackageDownloadLocation; }
string Package::getFilesAnalyzed() { return FilesAnalyzed; }
string Package::getPackageLicenseConcluded() { return PackageLicenseConcluded; }
string Package::getPackageLicenseDeclared() { return PackageLicenseDeclared; }
string Package::getPackageCopyrightText() { return PackageCopyrightText; }

void Package::setPackageName(string n) { this->PackageName = n; }
void Package::setSPDXID(string spdxid) { this->SPDXID = spdxid; }
void Package::setPackageComment(string c) { this->PackageComment = c; }
void Package::setExternalRef(string eR) { this->ExternalRef = eR; }
void Package::setPackageVersion(string v) { this->PackageVersion = v; }
void Package::setPackageSupplier(string ps) { this->PackageSupplier = ps; }
void Package::setRelationships(std::vector<string> r) { this->Relationships = r; }
void Package::setPackageDownloadLocation(string l) { this->PackageDownloadLocation = l; }
void Package::setFilesAnalyzed(string filesAnalysed) { this->FilesAnalyzed = filesAnalysed; }
void Package::setPackageLicenseConcluded(string plc) { this->PackageLicenseConcluded = plc; }
void Package::setPackageLicenseDeclared(string pld) { this->PackageLicenseDeclared = pld; }
void Package::setPackageCopyrightText(string t) { this->PackageCopyrightText = t; }

string Package::toString() {
    std::stringstream sstm;
    sstm << "##\n";
    sstm << "PackageName: " << getPackageName() << '\n';
    sstm << "SPDXID: " << getSPDXID() << '\n';
    sstm << "PackageComment: " << getPackageComment() << '\n';
    sstm << "ExternalRef: " << getExternalRef() << '\n';
    sstm << "PackageVersion: " << getPackageVersion() << '\n';
    sstm << "PackageSupplier: " << getPackageSupplier() << '\n';
    for (string r : getRelationships()) {
        sstm << "Relationship: " << r << '\n';
    }
    sstm << "PackageDownloadLocation: " << getPackageDownloadLocation() << '\n';
    sstm << "FilesAnalyzed: " << getFilesAnalyzed() << '\n';
    sstm << "PackageLicenseConcluded: " << getPackageLicenseConcluded() << '\n';
    sstm << "PackageLicenseDeclared: " << getPackageLicenseDeclared() << '\n';
    sstm << "PackageCopyrightText: " << getPackageCopyrightText() << '\n';

    return sstm.str();
}