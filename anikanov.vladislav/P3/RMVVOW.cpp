#include "RMVVOW.h"
#include <iostream>
#include <cctype>

bool isVowel(char c) {
  c = std::tolower(c);
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

char* dropVowels(char* line){
  try{
  char *new_string = new char[strlen(line) + 1];
  size_t j = 0;
  for (size_t i = 0; i < strlen(line) && line[i] != '\0'; ++i) {
    if (!isVowel(line[i])) {
      new_string[j++] = line[i];
    }
  }
  new_string[j] = '\0';
  return new_string;
  } catch (const std::exception &ex){
    return line;
  }
}
