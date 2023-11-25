#include <iostream>
#include <exception>
#include "sequence.hpp"

int main()
{
  likhachev::Sequence sequence;
  int prevMax = sequence.getLmax();
  int singChangeCount = 0;
  int localMaxCount = 0;
  try {
    std::cin.exceptions(std::istream::failbit);
    while (sequence.read() != 0) {
      if (!sequence.have_samge_sing()) {
          singChangeCount++;
      }
      if (prevMax != sequence.getLmax()){
        localMaxCount = 0;
      }
      if (sequence.getCvalue() == sequence.getLmax()){
        localMaxCount++;
      }
      prevMax = sequence.getLmax();
    }
  } catch (const std::istream::failure & e) {
    std::cerr << "Input error\n";
    return 1;
  } catch (const std::logic_error & e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  if (sequence.getCount() == 0) {
    std::cerr << "The sequence is too small" << "\n";
    return 2;
  }
  std::cout << "[SGN-CHG] count of sign changes: " <<   singChangeCount << "\n";
  std::cout << "[LOC-MAX] count of local maxima: " << localMaxCount << "\n";
  return 0;
}
