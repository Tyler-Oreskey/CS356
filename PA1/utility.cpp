#include "utility.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

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

string padString(const string& str, const int chunkSize) {
    int strSize = str.size();

    if (strSize >= chunkSize) {
        cerr << "No padding needed";
        return str;
    }
    
    char paddingByte = static_cast<char>(0x81);

    string result = str;
    result.append(chunkSize - strSize, paddingByte);

    return result;
}

string xorBlock(const string& str1, const string& str2, const int chunkSize) {
    string xorResult(chunkSize, '\0');

    for (int i = 0; i < chunkSize; ++i) {
        xorResult[i] = str1[i] ^ str2[i];
    }

    return xorResult;
}

string swapBytes(const string& block) {
    // implement this
    return "";
}