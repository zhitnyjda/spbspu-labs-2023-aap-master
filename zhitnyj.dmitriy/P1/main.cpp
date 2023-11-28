#include <iostream>
#include "funcEqlSeq.h"
#include "funcSumDup.h"

int main()
{
  int elm = 0;
  int var = 0;
  std::cin >> var;

  if (var == 0) {
    zhitnyj::funcEqlSeq funcEqlSeq;
    try {
      if (!(std::cin >> elm)) {
        throw std::logic_error("Invalid input");
      }
      while (elm) {
        funcEqlSeq(elm);
        if (!(std::cin >> elm)) {
          throw std::logic_error("Invalid input");
        }
      }
      std::cout << funcEqlSeq() << "\n";
    } catch (const std::logic_error &exc) {
      std::cerr << exc.what() << "\n";
      return 1;
    } catch (const std::length_error &exc) {
      std::cerr << exc.what() << "\n";
      return 2;
    }
  } else if (var == 1){
    zhitnyj::funcSumDup funcSumDup;

    try {
      if (!(std::cin >> elm)) {
        throw std::logic_error("Invalid input");
      }
      while (elm) {
        funcSumDup(elm);
        if (!(std::cin >> elm)) {
          throw std::logic_error("Invalid input");
        }
      }
      std::cout << funcSumDup() << "\n";
    } catch (const std::logic_error &exc) {
      std::cerr << exc.what() << "\n";
      return 1;
    } catch (const std::length_error &exc) {
      std::cerr << exc.what() << "\n";
      return 2;
    }
  } else {
    std::cerr << "Invalid var\n";
    return 1;
  }

  return 0;
}