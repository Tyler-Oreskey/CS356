#include "utility.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

bool fileExists(const string& filePath) {
    ifstream file(filePath);
    return file.good();
}

void writeToFile(const string& filePath, const std::string& data) {
    ofstream outputFile(filePath);

    if (!outputFile) {
        cerr << "Could not open output file for writing";
        exit(1);
    }

    outputFile << data;
    outputFile.close();
}