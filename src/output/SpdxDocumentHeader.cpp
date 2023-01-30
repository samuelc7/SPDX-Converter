#include "SpdxDocumentHeader.h"
#include <sstream>

SpdxDocumentHeader::SpdxDocumentHeader() {
    SPDXVersion = "";
    DataLicence = "";
    SPDXID = "";
    DocumentName = "";
    DocumentNamespace = "";
    Creators = {};
    Created = "";
    CreatorComment = "";
}

SpdxDocumentHeader::SpdxDocumentHeader(
        string SPDXVersion,
        string DataLicence,
        string SPDXID,
        string DocumentName,
        string DocumentNamespace,
        std::vector<string> Creators,
        string Created,
        string CreatorComment) 
{
    SPDXVersion = SPDXVersion;
    DataLicence = DataLicence;
    SPDXID = SPDXID;
    DocumentName = DocumentName;
    DocumentNamespace = DocumentNamespace;
    Creators = Creators;
    Created = Created;
    CreatorComment = CreatorComment;
}

string SpdxDocumentHeader::getSPDXVersion() { return SPDXVersion; }
string SpdxDocumentHeader::getDataLicence() { return DataLicence; }
string SpdxDocumentHeader::getSPDXID() { return SPDXID; }
string SpdxDocumentHeader::getDocumentName() { return DocumentName; }
string SpdxDocumentHeader::getDocumentNamespace() { return DocumentNamespace; }
std::vector<string> SpdxDocumentHeader::getCreators() { return Creators; }
string SpdxDocumentHeader::getCreatorComment() { return CreatorComment; }
string SpdxDocumentHeader::getCreated() { return Created; }

void SpdxDocumentHeader::setSPDXVersion(string spdxVersion) { this->SPDXVersion = spdxVersion; }
void SpdxDocumentHeader::setDataLicence(string dataLicense) { this->DataLicence = dataLicense; }
void SpdxDocumentHeader::setSPDXID(string spdxid) { this->SPDXID = spdxid; }
void SpdxDocumentHeader::setDocumentName(string docName) { this->DocumentName = docName; }
void SpdxDocumentHeader::setDocumentNamespace(string documentNameSpace) { this->DocumentNamespace = documentNameSpace; }
void SpdxDocumentHeader::setCreators(std::vector<string> creators) { this->Creators = creators; }
void SpdxDocumentHeader::setCreatorComment(string comment) { this->CreatorComment = comment; }
void SpdxDocumentHeader::setCreated(string created) { this->Created = created; }

string SpdxDocumentHeader::toString() {
    std::stringstream sstm;
    sstm << "## Document Header\n";
    sstm << "SPDXVersion: " << getSPDXVersion() << '\n';
    sstm << "DataLicence: " << getDataLicence() << '\n';
    sstm << "SPDXID: " << getSPDXID() << '\n';
    sstm << "DocumentName: " << getDocumentName() << '\n';
    sstm << "DocumentNameSpace: " << getDocumentNamespace() << '\n';
    sstm << "Creator: ";
    for (string creator : getCreators()) {
        sstm << creator << ' ';
    }
    sstm << "\nCreated: " << getCreated() << '\n';
    sstm << "CreatorComment: " << getCreatorComment() << '\n';

    return sstm.str();
}