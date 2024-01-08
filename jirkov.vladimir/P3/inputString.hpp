#ifndef INPUTSTRING_HPP
#define INPUTSTRING_HPP
#include <iostream>
#include <cstddef>

char* inputString(std::istream& input);
char* resizeString(char* string, size_t currentSize, size_t newSize);
#endif
