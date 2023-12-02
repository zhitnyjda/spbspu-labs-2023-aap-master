#include "RMVVOW.h"
#include <cctype>
#include <cstring>

bool isVowel(char c) {
  c = std::tolower(c);
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

char *dropVowels(char *string, size_t len){
  char *new_string = new char[len];
  size_t j = 0;
  for (size_t i = 0; i < strlen(string) + 1; ++i) {
    if (!isVowel(string[i])) {
      new_string[j++] = string[i];
    }
  }
  delete[] string;
  string = new char[len];
  for (size_t i = 0; i < len; ++i) {
    string[i] = new_string[i];
  }
  delete[] new_string;
  return string;
}
