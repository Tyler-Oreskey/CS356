#ifndef UTILITY_H
#define UTILITY_H

#include <string>

bool fileExists(const std::string&);
void writeToFile(const std::string&, const std::string&);
std::string readFromFile(const std::string&);
std::string padString(const std::string&, int);

#endif