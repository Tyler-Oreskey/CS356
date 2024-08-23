#include "block.h"
#include "stream.h"
#include "utility.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 6) {
        cerr << "Invalid number of arguments.";
        return 1;
    }

    string cipherType = argv[1];
    string inputFilePath = argv[2];
    string outputFilePath = argv[3];
    string keyFilePath = argv[4];
    string modeType = argv[5];

    if (cipherType != "B" && cipherType != "S") {
        cerr << "Invalid Function Type";
        return 1;
    }

    if (!fileExists(inputFilePath)) {
        cerr << "Input File Does Not Exist";
        return 1;
    }

    if (!fileExists(keyFilePath)) {
        cerr << "Key File Does Not Exist";
        return 1;
    }

    if (modeType != "E" && modeType != "D") {
        cerr << "Invalid Mode Type";
        return 1;
    }

    return 0;
}