#include <iostream>
#include <exception>
#include "sequence.cpp"
#include "sequence.hpp"

int main()
{
  likhachev::SequenceSignChangeCount signChangeCountSequence;
  likhachev::SequenceLocalMaxCount localMaxCountSequence;
  try {
    std::cin.exceptions(std::istream::failbit);
    int inputNumber = 0;
    do {
      std::cin >> inputNumber;
      if (!std::cin) {
        std::cerr << "Not a sequence.\n";
        return 1;
      }
      signChangeCountSequence(inputNumber);
      localMaxCountSequence(inputNumber);
    } while (inputNumber != 0);
  } catch (const std::istream::failure & e) {
    std::cerr << "Input error\n";
    return 1;
  } catch (const std::logic_error & e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  if (signChangeCountSequence.getCount() == 0 || localMaxCountSequence.getCount() == 0) {
    std::cerr << "The sequence is too small" << "\n";
    return 2;
  }
  std::cout << "[SGN-CHG] count of sign changes: " <<   signChangeCountSequence() << "\n";
  std::cout << "[LOC-MAX] count of local maxima: " << localMaxCountSequence() << "\n";
  return 0;
}
