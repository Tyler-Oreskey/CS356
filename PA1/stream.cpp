#include "stream.h"

#include <string>
#include <iostream>

using namespace std;

string xorStreamCipher(const string& data, const string& key) {
    int dataSize = data.size();
    int keySize = key.size();

    string result(dataSize, '\0');

    for (int i = 0; i < dataSize; ++i) {
        char keyChar = key[i % keySize];
        result[i] = data[i] ^ keyChar;
    }

    return result;
}

void streamCipher(const string& message, const string& outputFilePath, const string& key) {
    string encryptedData = xorStreamCipher(message, key);
    string decryptedData = xorStreamCipher(encryptedData, key);
}