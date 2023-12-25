#ifndef INPUT_H
#define INPUT_H
#include <iosfwd>

size_t input(std::istream &, char *, size_t);

size_t resize(char *line, size_t len);

#endif
