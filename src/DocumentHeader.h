// SPDX Document Header
#ifndef DOCUMENT_HEADER_H
#define DOCUMENT_HEADER_H

#include <string>
#include <chrono>
#include "DateTime.h"
using std::string;

class DocumentHeader {
    private: 
        string SPDXVersion;
        string DataLicence;
        string SPDXID;
        string DocumentName;
        string DocumentNamespace;
        string Creator;       
        DateTime Created;
        string CreatorComment;
    public:
        // Constructors
        DocumentHeader() {
            SPDXVersion = "";
            DataLicence = "";
            SPDXID = "";
            DocumentName = "";
            DocumentNamespace = "";
            Creator = "";
            Created = *new DateTime{};
            CreatorComment = "";
        };
        DocumentHeader(
            string SPDXVersion,
            string DataLicence,
            string SPDXID,
            string DocumentName,
            string DocumentNamespace,
            string Creator,
            DateTime Created,
            string CreatorComment) 
            {
                SPDXVersion = SPDXVersion;
                DataLicence = DataLicence;
                SPDXID = SPDXID;
                DocumentName = DocumentName;
                DocumentNamespace = DocumentNamespace;
                Creator = Creator;
                Created = Created;
                CreatorComment = CreatorComment;
            }
        // Getters
        string getSPDXVersion();
        string getDataLicence();
        string getSPDXID();
        string getDocumentName();
        string getDocumentNamespace();
        string getCreator();
        string getCreatorComment();
        DateTime getCreated();

        // Setters
        void setSPDXVersion(string SPDXVersion);
        void setDataLicence(string DataLicence);
        void setSPDXID(string SPDXID);
        void setDocumentName(string DocumentName);
        void setDocumentNamespace(string DocumentNameSpace);
        void setCreator(string Creator);
        void setCreatorComment(string CreatorComment);
        void setCreated(DateTime Created);
};

#endif