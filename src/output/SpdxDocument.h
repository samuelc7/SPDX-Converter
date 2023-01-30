#ifndef SPDX_DOCUMENT_H
#define SPDX_DOCUMENT_H

#include <vector>
#include <iostream>
#include "SpdxDocumentHeader.h"
#include "Package.h"
#include "../input/JsonDocument.h"

class SpdxDocument{
    private: 
        SpdxDocumentHeader header;
        std::vector<Package> packages;
    public:
        // Constructors
        SpdxDocument();
        SpdxDocument(SpdxDocumentHeader h, std::vector<Package> p);

        // Getters
        SpdxDocumentHeader getHeader();
        std::vector<Package> getPackages();

        // Setters
        void setHeader(SpdxDocumentHeader h);
        void setPackages(std::vector<Package> p);

        /**
         * @brief Populates all of the mem vars with the passed in 
         *          JsonDocument
         * 
         * @param jsonDoc 
         */
        void populateFromJsonDoc(JsonDocument jsonDoc);

        /**
         * @brief Creates a file at the passed in filePath.
         *          Writes all of the content to the file. 
         * 
         * @param file 
         */
        void writeToFile(std::filesystem::path filePath);

};




#endif