#include "block.h"
#include "utility.h"

#include <string>
#include <iostream>

using namespace std;

void blockEncrypt(const string& inputFileText, const string& outputFilePath, const string& key) {
    const int chunkSize = 16;
    int dataSize = inputFileText.size();

    string paddedMessage = padString(inputFileText, 16);
    string encryptedMessage;

    for (int i = 0; i < dataSize; i += chunkSize) {
        string chunk = paddedMessage.substr(i, chunkSize);
        string xorResult = xorBlock(chunk, key, chunkSize);
        string swapped = swapBytes(xorResult, key);

        encryptedMessage += swapped;
    }

    writeToFile(outputFilePath, encryptedMessage);
}

void blockDecrypt(const string& inputFileText, const string& outputFilePath, const string& key) {
    const int chunkSize = 16;
    int dataSize = inputFileText.size();
    string decryptedMessage;

    for (int i = 0; i < dataSize; i += chunkSize) {
        string chunk = inputFileText.substr(i, chunkSize);
        string swapped = swapBytes(chunk, key);
        string xorResult = xorBlock(swapped, key, chunkSize);

        decryptedMessage += xorResult;
    }

    decryptedMessage = removePadding(decryptedMessage);

    writeToFile(outputFilePath, decryptedMessage);
}