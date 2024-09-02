#include "block.h"
#include "utility.h"

#include <string>
#include <iostream>

using namespace std;

string addPadding(const string& str, const int chunkSize) {
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

void blockCypherEncrypt(const string& message, const string& outputFilePath, const string& key) {
    const int chunkSize = 16;
    int dataSize = message.size();

    string paddedMessage = addPadding(message, chunkSize);
    string encryptedMessage;

    for (int i = 0; i < dataSize; i += chunkSize) {
        string chunk = paddedMessage.substr(i, chunkSize);
        string xorResult = xorBlock(chunk, key, chunkSize);
        string swapped = swapBytes(xorResult, key);

        encryptedMessage += swapped;
    }

    writeToFile(outputFilePath, encryptedMessage);
}

void blockCypherDecrypt(const string& message, const string& outputFilePath, const string& key) {
    const int chunkSize = 16;
    int dataSize = message.size();
    string decryptedMessage;

    for (int i = 0; i < dataSize; i += chunkSize) {
        string chunk = message.substr(i, chunkSize);
        string swapped = swapBytes(chunk, key);
        string xorResult = xorBlock(swapped, key, chunkSize);

        decryptedMessage += xorResult;
    }

    decryptedMessage = removePadding(decryptedMessage);

    writeToFile(outputFilePath, decryptedMessage);
}