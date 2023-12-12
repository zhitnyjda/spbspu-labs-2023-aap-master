#include "RMVVOW.h"
#include <cctype>
#include <cstring>
#include "line.h"

bool isVowel(char c) {
  c = std::tolower(c);
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void dropVowels(Line &line){
  char *new_string = new char[line.size()];
  size_t j = 0;
  for (size_t i = 0; i < line.size() && line[i] != '\0'; ++i) {
    if (!isVowel(line[i])) {
      new_string[j++] = line[i];
    }
  }
  new_string[j] = '\0';
  line.set_line(new_string);
  delete[] new_string;
}
