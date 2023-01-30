#include "Package.h"
#include <sstream>


Package::Package() {
    PackageName = "";
    SSPDXID = "";
    PackageComment = "";
    ExternalRef = "";
    PackageVersion = "";
    PackageSupplier = "";
    Relationship = "";
    PackageDownloadLocation = "";
    FilesAnalyzed = false;
    PackageLicenseConcluded = "";
    PackageLicenseDeclared = "";
    PackageCopyrightText = "";
}

Package::Package(
        string PackageName,
        string SSPDXID,
        string PackageComment,
        string ExternalRef,
        string PackageVersion,
        string PackageSupplier,
        string Relationship,
        string PackageDownloadLocation,
        bool FilesAnalyzed,
        string PackageLicenseConcluded,
        string PackageLicenseDeclared,
        string PackageCopyrightText) 
    {
        PackageName = PackageName;
        SSPDXID = SSPDXID;
        PackageComment = PackageComment;
        ExternalRef = ExternalRef;
        PackageVersion = PackageVersion;
        PackageSupplier = PackageSupplier;
        Relationship = Relationship;
        PackageDownloadLocation = PackageDownloadLocation;
        FilesAnalyzed = FilesAnalyzed;
        PackageLicenseConcluded = PackageLicenseConcluded;
        PackageLicenseDeclared = PackageLicenseDeclared;
        PackageCopyrightText = PackageCopyrightText;
    }

string Package::getPackageName() { return PackageName; }
string Package::getSSPDXID() { return SSPDXID; }
string Package::getPackageComment() { return PackageComment; }
string Package::getExternalRef() { return ExternalRef; }
string Package::getPackageVersion() { return PackageVersion; }
string Package::getPackageSupplier() { return PackageSupplier; }
string Package::getRelationship() { return Relationship; }
string Package::getPackageDownloadLocation() { return PackageDownloadLocation; }
bool Package::getFilesAnalyzed() { return FilesAnalyzed; }
string Package::getPackageLicenseConcluded() { return PackageLicenseConcluded; }
string Package::getPackageLicenseDeclared() { return PackageLicenseDeclared; }
string Package::getPackageCopyrightText() { return PackageCopyrightText; }

void Package::setPackageName(string n) { this->PackageName = n; }
void Package::setSSPDXID(string sspdxid) { this->SSPDXID = sspdxid; }
void Package::setPackageComment(string c) { this->PackageComment = c; }
void Package::setExternalRef(string eR) { this->ExternalRef = eR; }
void Package::setPackageVersion(string v) { this->PackageVersion = v; }
void Package::setPackageSupplier(string ps) { this->PackageSupplier = ps; }
void Package::setRelationship(string r) { this->Relationship = r; }
void Package::setPackageDownloadLocation(string l) { this->PackageDownloadLocation = l; }
void Package::setFilesAnalyzed(bool filesAnalysed) { this->FilesAnalyzed = filesAnalysed; }
void Package::setPackageLicenseConcluded(string plc) { this->PackageLicenseConcluded = plc; }
void Package::setPackageLicenseDeclared(string pld) { this->PackageLicenseDeclared = pld; }
void Package::setPackageCopyrightText(string t) { this->PackageCopyrightText = t; }

string Package::toString() {
    std::stringstream sstm;
    sstm << "##\n";
    sstm << "Package Name: " << getPackageName() << '\n';
    sstm << "SSPDXID: " << getSSPDXID() << '\n';
    sstm << "PackageComment: " << getPackageComment() << '\n';
    sstm << "ExternalRef: " << getExternalRef() << '\n';
    sstm << "PackageVersion: " << getPackageVersion() << '\n';
    sstm << "PackageSupplier: " << getPackageSupplier() << '\n';
    sstm << "Relationship: " << getRelationship() << '\n';
    sstm << "PackageDownloadLocation: " << getPackageDownloadLocation() << '\n';
    sstm << "FilesAnalyzed: " << getFilesAnalyzed() << '\n';
    sstm << "PackageLicenseConcluded: " << getPackageLicenseConcluded() << '\n';
    sstm << "PackageLicenseDeclared: " << getPackageLicenseDeclared() << '\n';
    sstm << "PackageCopyrightText: " << getPackageCopyrightText() << '\n';

    return sstm.str();
}