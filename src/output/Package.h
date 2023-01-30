// Package
#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
using std::string;

class Package {
    private:
        string PackageName;
        string SSPDXID;
        string PackageComment;
        string ExternalRef;
        string PackageVersion;
        string PackageSupplier;
        string Relationship;
        string PackageDownloadLocation;
        bool FilesAnalyzed;
        string PackageLicenseConcluded;
        string PackageLicenseDeclared;
        string PackageCopyrightText;
    public:
        // Constructors
        Package();
        Package(
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
            string PackageCopyrightText);
           
        // Getters
        string getPackageName();
        string getSSPDXID();
        string getPackageComment();
        string getExternalRef();
        string getPackageVersion();
        string getPackageSupplier();
        string getRelationship();
        string getPackageDownloadLocation();
        bool getFilesAnalyzed();
        string getPackageLicenseConcluded();
        string getPackageLicenseDeclared();
        string getPackageCopyrightText();

        // Setters
        void setPackageName(string PackageName);
        void setSSPDXID(string SSPDXID);
        void setPackageComment(string PackageComment);
        void setExternalRef(string ExternalRef);
        void setPackageVersion(string PackageVersion);
        void setPackageSupplier(string PackageSupplier);
        void setRelationship(string Relationship);
        void setPackageDownloadLocation(string PackageDownloadLocation);
        void setFilesAnalyzed(bool FilesAnalyzed);
        void setPackageLicenseConcluded(string PackageLicenseConcluded);
        void setPackageLicenseDeclared(string PackageLicenseConcluded);
        void setPackageCopyrightText(string PackageCopyrightText);

        string toString();
};

#endif