// SPDX Document Header
#ifndef DOCUMENT_HEADER_H
#define DOCUMENT_HEADER_H

#include <string>
#include <vector>
#include <chrono>
using std::string;

class SpdxDocumentHeader {
    private: 
        string SPDXVersion;
        string DataLicence;
        string SPDXID;
        string DocumentName;
        string DocumentNamespace;
        std::vector<string> Creators;
        string Created;
        string CreatorComment;
    public:
        // Constructors
        SpdxDocumentHeader();
        SpdxDocumentHeader(
            string SPDXVersion,
            string DataLicence,
            string SPDXID,
            string DocumentName,
            string DocumentNamespace,
            std::vector<string> Creators,
            string Created,
            string CreatorComment);

        // Getters
        string getSPDXVersion();
        string getDataLicence();
        string getSPDXID();
        string getDocumentName();
        string getDocumentNamespace();
        std::vector<string> getCreators();
        string getCreatorComment();
        string getCreated();

        // Setters
        void setSPDXVersion(string SPDXVersion);
        void setDataLicence(string DataLicence);
        void setSPDXID(string SPDXID);
        void setDocumentName(string DocumentName);
        void setDocumentNamespace(string DocumentNameSpace);
        void setCreators(std::vector<string> Creators);
        void setCreatorComment(string CreatorComment);
        void setCreated(string Created);

        /**
         * @brief Formatts all the mem vars into a readable string.
         *         Formatts into the spdx format.
         * 
         * @return string 
         */
        string toString();
};

#endif