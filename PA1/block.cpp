#include "block.h"
#include "utility.h"

#include <string>
#include <iostream>

using namespace std;

void blockEncrypt(const string& inputFileText, const string& outputFilePath, const string& keyFileText) {
    const size_t chunkSize = 16;
    size_t dataSize = inputFileText.size();

    for (size_t i = 0; i < dataSize; i += chunkSize) {
        string chunk = inputFileText.substr(i, chunkSize);

        if (chunk.size() < chunkSize) {
            chunk = padString(chunk, chunkSize);
        }
    }
    
}

void blockDecrypt(const string& inputFilePath, const string& outputFilePath, const string& keyFilePath) {
    // TODO: implement this
}