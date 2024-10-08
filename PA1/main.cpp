#include "block.h"
#include "stream.h"
#include "utility.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 6) {
        cerr << "Invalid number of arguments." << endl;
        return 1;
    }

    string cipherType = argv[1];
    string inputFilePath = argv[2];
    string outputFilePath = argv[3];
    string keyFilePath = argv[4];
    string modeType = argv[5];

    if (cipherType != "B" && cipherType != "S") {
        cerr << "Invalid Function Type" << endl;
        return 1;
    }

    if (!fileExists(inputFilePath)) {
        cerr << "Input File Does Not Exist" << endl;
        return 1;
    }

    if (!fileExists(keyFilePath)) {
        cerr << "Key File Does Not Exist" << endl;
        return 1;
    }

    if (modeType != "E" && modeType != "D") {
        cerr << "Invalid Mode Type" << endl;
        return 1;
    }

    string text = readFromFile(inputFilePath);
    string key = readFromFile(keyFilePath);

    if (cipherType == "B") {
        if (modeType == "E") {
            blockCypherEncrypt(text, outputFilePath, key);
        }
        else if (modeType == "D") {
            blockCypherDecrypt(text, outputFilePath, key);
        }
    }
    else if (cipherType == "S") {
        streamCipher(text, outputFilePath, key);
    }

    return 0;
}