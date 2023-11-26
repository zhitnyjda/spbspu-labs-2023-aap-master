#include <iostream>
#include <cstring>
#include "errorsPrint.h"

void print_error_by_errcode(std::ostream &cout, const char* code)
{
  if (strcmp(code, "1") != 0) {
    cout << "Wrong count of params\n";
    return;
  }
  if (strcmp(code, "2") != 0) {
    cout << "Invalid input\n";
    return;
  }
  if (strcmp(code, "3") != 0) {
    cout << "Invalid first argument\n";
    return;
  }
}
