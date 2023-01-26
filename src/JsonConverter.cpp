#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "DocumentHeader.h"
#include "JsonDocument.h"
#include "Package.h"
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;
namespace filesystem = std::filesystem;

int main() {
    filesystem::path filePath;
    cout << "Welcome to the SPDX_Converter tool.\n";
    cout << "Enter the absolut file location of the json file that needs to be converted to the spdx format: ";
    cin >> filePath;

    ifstream file(filePath);
    
    JsonDocument jsonDocument;
    jsonDocument.parseFile(file);

   string spdxVersion = jsonDocument.getSpdxVersion();
   cout << spdxVersion << '\n';
   cout << jsonDocument.getDataLicense() << '\n';
   cout << jsonDocument.getSPDXID() << '\n';
   cout << jsonDocument.getName() << '\n';
   cout << jsonDocument.getDocumentNamespace() << '\n';

    return 0;
}