#include "FindEqSeq.hpp"
#include "FindDecSeq.hpp"
#include <iostream>
#include <stdexcept>

using namespace reznikova;

int main()
{
  MaxEqualSequense maxEqualSequense;
  MaxDecreasingSequence maxDecreasingSequence;
  long long number = 0;
  do
  {
   std::cin >> number;
   if(!std::cin)
   {
     std::cerr << "Not a sequence.\n";
     return 1;
   }
   else if (number != 0)
   {
     try
     {
       maxEqualSequense(number);
       maxDecreasingSequence(number);
     }
     catch (const std::exception & e)
     {
       std::cerr << "Error: " << e.what() << "\n";
       return 2;
     }
   }
  }
  while (number != 0);
  std::cout << "максимальное число подряд идущих равных элементов: ";
  std::cout << maxEqualSequense() << "\n";
  std::cout << "наибольшая длина монотонно-убывающего фрагментa: ";
  std::cout << maxDecreasingSequence() << "\n";
}
