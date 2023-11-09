#include <iostream>
int main()
{
  int number =0;
  size_t seqLenght = 0;
  do{
    std::cin>> number;
    if (!std::cin)
    {
      std::cerr<< "not a sequence\n";
      return 1;
    } else if (number != 0) {
      ++seqLenght;
    }
  } while (number!=0);
  std::cout<< seqLenght<< "\n";
}
