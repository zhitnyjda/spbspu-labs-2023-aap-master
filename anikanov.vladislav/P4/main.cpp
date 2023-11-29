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
    printErrorByErrcode(std::cerr, e.what());
    return 1;
  }
  int num = std::stoi(argv[1]);
  std::ifstream cin(argv[2]);
  std::ofstream cout(argv[3]);
  int n = 0, m = 0;
  if (!(cin >> n >> m)) {
    printErrorByErrcode(std::cerr, "2");
    return 1;
  }
  if (n == 0 || m == 0) {
    printErrorByErrcode(std::cout, "2");
    return 0;
  }
  int *arrayP = nullptr;
  try {
    if (num == 1) {
      int array[n * m];
      int countReaded = inputArray(cin, array, n, m);
      if (countReaded != n * m){
        throw std::logic_error("2");
      }
      spiralIncrease(array, n, m);
      printArray(cout, array, n, m);
    } else {
      int *array = new int[n * m];
      arrayP = array;
      int countReaded = inputArray(cin, array, n, m);
      if (countReaded != n * m){
        throw std::logic_error("2");
      }
      spiralIncrease(array, n, m);
      printArray(cout, array, n, m);
      delete[] array;
    }
  } catch (const std::logic_error &err) {
    printErrorByErrcode(std::cout, err.what());
    if (arrayP) {
      delete[] arrayP;
      arrayP = nullptr;
    }
    return 1;
  }
  arrayP = nullptr;
}
