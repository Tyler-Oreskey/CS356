#ifndef UTILITY_H
#define UTILITY_H

#include <string>

bool fileExists(const std::string&);
void writeToFile(const std::string&, const std::string&);
std::string readFromFile(const std::string&);
std::string padString(const std::string&, const int);
std::string xorBlock(const std::string&, const std::string&, const int);
std::string swapBytes(const std::string&, const std::string&);

#endif