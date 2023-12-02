#include <iostream>
#include "line.h"
#include "RMVVOW.h"
#include "REPDGT.h"

int main()
{
  try {
    Line line;
    std::cin >> line;
    Line answerRMVVOW = line;
    dropVowels(answerRMVVOW.get_line(), answerRMVVOW.size());
    std::cout << answerRMVVOW << "\n";
    std::cout << hasDuplicateDigits(line.get_line()) << "\n";
  } catch (const std::exception &ex) {
    std::cerr << ex.what() << "\n";
    return 1;
  }
}