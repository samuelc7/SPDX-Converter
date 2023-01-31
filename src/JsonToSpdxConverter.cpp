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

/***
 * Created by Samuel Cummings, Intern for the AF 309 SWEG.
 * Created on 1/31/2023
 * 
 * The purpose of this project is to take in json files generated 
 * by Microsoft's open source sbom-tool and output an spdx file in 
 * the format that works with the Daggerboard tool. This is to help 
 * test both the sbom-tool and the Daggerboard tool to see how well 
 * they do at capturing and displaying information about project 
 * dependencies and packages.
 * 
 * Future updates: 
 *  - Add error handling
 *  - Add logging
 *  - Take in command line args
 
 
  

 
 * This prompts the user for a json file, parse the json data and 
 * stores it into a JsonDocument object, creates an SpdxDocument 
 * object and uses the populateFromJsonDoc() method to populate 
 * it with the data from the json file. It then prompts for a location
 * to save the spdx file and saves it there. 
*/
int main() {
    filesystem::path inputFilePath;
    cout << "Welcome to the SPDX_Converter tool.\n";
    cout << "Enter the absolute file location of the json file that needs to be converted to the spdx format: ";
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
    outputFilePath = filesystem::current_path().string() + "/Program_Output/" + name + ".spdx";

    // If file exists, ask if the user would like to overwrite it.
    if (filesystem::exists(outputFilePath)) {
        char ow;
        cout << "File :" << outputFilePath << " already exists. Overwrite it? (y/n) ";
        cin >> ow;
        if (ow == 'n') {
            cout << "Exiting...\n";
            return 0;
        } 
    }
    spdxDocument.writeToFile(outputFilePath);
    cout << "SPDX file saved at: " << outputFilePath << '\n';
    return 0;
}