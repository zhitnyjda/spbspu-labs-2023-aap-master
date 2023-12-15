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
    char *line_c = new char[answerRMVVOW.size()];
    strcpy(line_c, answerRMVVOW.get_line());
    answerRMVVOW.set_line(line_c);
    delete[] line_c;
    std::cout << answerRMVVOW << "\n";
    std::cout << hasDuplicateDigits(line.get_line()) << "\n";
  } catch (const std::exception &ex) {
    std::cerr << ex.what() << "\n";
    return 1;
  }
}
