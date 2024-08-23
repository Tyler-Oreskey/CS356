#include "block.h"
#include "utility.h"

#include <string>
#include <iostream>

using namespace std;

void blockEncrypt(const string& inputFileText, const string& outputFilePath, const string& keyFileText) {
    const int chunkSize = 16;
    int dataSize = inputFileText.size();

    for (int i = 0; i < dataSize; i += chunkSize) {
        string chunk = inputFileText.substr(i, chunkSize);

        if (chunk.size() < chunkSize) {
            chunk = padString(chunk, chunkSize);
        }

        string xorResult = xorBlock(chunk, keyFileText, chunkSize);

        // swap bytes
    }
    
}

void blockDecrypt(const string& inputFilePath, const string& outputFilePath, const string& keyFilePath) {
    // TODO: implement this
}