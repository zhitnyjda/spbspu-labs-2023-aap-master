#include <iostream>
#include <fstream>
#include "arrayModifications.h"
#include "validationAndConversationToInt.h"
#include "inOutArray.h"
#include "errorsPrint.h"

int main(int argc, char **argv)
{
  try {
    check(argc, argv);
  } catch (const std::exception &e) {
    print_error_by_errcode(std::cerr, e.what());
    return 1;
  }
  int num = std::stoi(argv[1]);
  std::ifstream cin(argv[2]);
  std::ofstream cout(argv[3]);
  int n = 0, m = 0;
  if (!(cin >> n >> m)) {
    print_error_by_errcode(std::cerr, "2");
    return 1;
  }
  if (n == 0 || m == 0) {
    print_error_by_errcode(std::cout, "2");
    return 0;
  }
  int *arrayP = nullptr;
  try {
    if (num == 1) {
      int array[n * m];
      inputArray(cin, array, n, m);
      spiralIncrease(array, n, m);
      printArray(cout, array, n, m);
    } else {
      int *array = new int[n * m];
      arrayP = array;
      inputArray(cin, array, n, m);
      spiralIncrease(array, n, m);
      printArray(cout, array, n, m);
      delete[] array;
    }
  } catch (const std::logic_error &err) {
    print_error_by_errcode(std::cout, err.what());
    if (arrayP) {
      delete[] arrayP;
      arrayP = nullptr;
    }
    return 1;
  }
  arrayP = nullptr;
}
