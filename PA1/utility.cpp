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

string padString(const string& str, const int chunkSize) {
    int strSize = str.size();
    string result = str;

    const char paddingByte = static_cast<char>(0x81);

    if (strSize % chunkSize != 0) {
        result.append(chunkSize - (strSize % chunkSize), paddingByte);
    }

    return result;
}

string removePadding(const string& block) {
    const char paddingByte = static_cast<char>(0x81);
    string result = block;

    size_t position = result.find_last_not_of(paddingByte);
    
    return result.substr(0, position + 1);
}

string xorBlock(const string& str1, const string& str2, const int chunkSize) {
    string result(chunkSize, '\0');

    for (int i = 0; i < chunkSize; ++i) {
        result[i] = str1[i] ^ str2[i];
    }

    return result;
}

string swapBytes(const string& block, const string& key) {
    int start = 0;
    int end = block.size() - 1;
    int keySize = key.size();
    string result = block;

    while (start < end) {
        if (key[start % keySize] % 2 == 0) {
            start++;
        } else {
            swap(result[start++], result[end--]);
        }
    }

    return result;
}