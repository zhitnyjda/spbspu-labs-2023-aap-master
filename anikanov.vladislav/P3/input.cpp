#include "input.h"
#include <iostream>

size_t input(std::istream &in, char *line, size_t len){
  size_t i = 0;
  in >> std::noskipws;
  char c;
  do {
    if (!(in >> c)) {
      ++i;
      break;
    }
    if (i == len) {
      len = resize(line, len);
    }
    line[i++] = c;
  } while (c != '\n' && c != EOF && c != '\0');
  line[i - 1] = '\0';
  return len;
}

size_t resize(char *line, size_t len){
  try {
    char *new_data = new char[len * 2]{};
    for (size_t i = 0; i < len; ++i) {
      new_data[i] = line[i];
    }
    delete[] line;
    len *= 2;
    line = new_data;
  } catch (std::exception const &ex) {
    throw std::runtime_error(ex.what());
  }
  return len;
}
