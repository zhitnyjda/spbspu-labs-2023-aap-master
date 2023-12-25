#include <iostream>
#include <cstring>
#include "RMVVOW.h"
#include "REPDGT.h"
#include "input.h"

int main()
{
  char *line_p = nullptr;
  char *answerRMVVOW_p = nullptr;
  size_t n = 2;
  try {
    char *line = new char[n]{'\0', '\0'};
    line_p = line;
    n = input(std::cin, line, 2);
    char *answerRMVVOW = new char[n];
    answerRMVVOW_p = answerRMVVOW;
    strcpy(answerRMVVOW, dropVowels(line));
    std::cout << answerRMVVOW << "\n";
    delete[] answerRMVVOW;
    answerRMVVOW_p = nullptr;
    std::cout << hasDuplicateDigits(line) << "\n";
    delete[] line;
    line_p = nullptr;
  } catch (const std::exception &ex) {
    if (line_p != nullptr){
      delete[] line_p;
    }
    if (answerRMVVOW_p != nullptr){
      delete[] line_p;
    }
    char *line_p = nullptr;
    char *answerRMVVOW_p = nullptr;
    std::cerr << ex.what() << "\n";
    return 1;
  }
}
