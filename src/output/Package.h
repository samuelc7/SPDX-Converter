// Package
#ifndef PACKAGE_H
#define PACKAGE_H
#include <vector>
#include <string>
using std::string;

class Package {
    private:
        string PackageName;
        string SPDXID;
        string PackageComment;
        string ExternalRef;
        string PackageVersion;
        string PackageSupplier;
        std::vector<string> Relationships;
        string PackageDownloadLocation;
        string FilesAnalyzed;
        string PackageLicenseConcluded;
        string PackageLicenseDeclared;
        string PackageCopyrightText;
    public:
        // Constructors
        Package();
        Package(
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
            string PackageCopyrightText);
           
        // Getters
        string getPackageName();
        string getSPDXID();
        string getPackageComment();
        string getExternalRef();
        string getPackageVersion();
        string getPackageSupplier();
        std::vector<string> getRelationships();
        string getPackageDownloadLocation();
        string getFilesAnalyzed();
        string getPackageLicenseConcluded();
        string getPackageLicenseDeclared();
        string getPackageCopyrightText();

        // Setters
        void setPackageName(string PackageName);
        void setSPDXID(string SPDXID);
        void setPackageComment(string PackageComment);
        void setExternalRef(string ExternalRef);
        void setPackageVersion(string PackageVersion);
        void setPackageSupplier(string PackageSupplier);
        void setRelationships(std::vector<string> Relationship);
        void setPackageDownloadLocation(string PackageDownloadLocation);
        void setFilesAnalyzed(string FilesAnalyzed);
        void setPackageLicenseConcluded(string PackageLicenseConcluded);
        void setPackageLicenseDeclared(string PackageLicenseConcluded);
        void setPackageCopyrightText(string PackageCopyrightText);

        string toString();
};

#endif