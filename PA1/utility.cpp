#include "utility.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <algorithm>

using namespace std;

bool fileExists(const string& filePath) {
    ifstream file(filePath);
    return file.good();
}

void writeToFile(const string& filePath, const string& data) {
    ofstream outputFile(filePath);

    if (!outputFile) {
        cerr << "Could not open output file for writing";
        exit(1);
    }

    outputFile << data;
    outputFile.close();
}

string readFromFile(const string& filePath) {
    if (!fileExists(filePath)) {
        cerr << "File Does Not Exist";
        exit(1);
    }

    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Error opening the file" << endl;
        exit(1); 
    }

    stringstream buffer;

    buffer << file.rdbuf();

    string fileContents = buffer.str();

    file.close();

    return fileContents;
}