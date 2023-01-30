#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "input/JsonDocument.h"
#include "output/SpdxDocument.h"
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;
namespace filesystem = std::filesystem;

int main() {
    filesystem::path inputFilePath;
    cout << "Welcome to the SPDX_Converter tool.\n";
    cout << "Enter the absolut file location of the json file that needs to be converted to the spdx format: ";
    cin >> inputFilePath;

    ifstream inputFile(inputFilePath);
    
    JsonDocument jsonDocument;
    jsonDocument.parseJsonFile(inputFile);
    cout << jsonDocument.toString() << '\n';

    SpdxDocument spdxDocument;
    spdxDocument.populateFromJsonDoc(jsonDocument);

    filesystem::path outputFilePath;
    string name;
    cout << "Enter a name for the spdx file being created: ";
    cin >> name;
    outputFilePath = filesystem::current_path().string() + '/' + name + ".spdx";

    if (filesystem::exists(outputFilePath)) {
        char ow;
        cout << "File :" << outputFilePath << " already exists. Overwrite it? (y/n) ";
        cin >> ow;
        if (ow == 'n') {
            cout << "Exiting...\n";
            return 0;
        } else {
            spdxDocument.writeToFile(outputFilePath);
            cout << "SPDX file saved at: " << outputFilePath << '\n';
        }
    }
    return 1;
}