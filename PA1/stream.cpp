#include "stream.h"
#include "utility.h"

#include <string>
#include <iostream>

using namespace std;

void streamCipher(const string& message, const string& outputFilePath, const string& key) {
    int dataSize = message.size();
    int keySize = key.size();

    string result(dataSize, '\0');

    for (int i = 0; i < dataSize; ++i) {
        result[i] = message[i] ^ key[i % keySize];
    }

    writeToFile(outputFilePath, result);
}