#include <iostream>
int main()
{
  int num = 0;
  int subMax = 0;
  int max = 0;
  std::cin>>num;
  while ((std::cin) and (num !=0)) {
    if (num>max){
      subMax = max;
      max = num;
    } else if (num > subMax) {
      subMax=num;
    };
    std::cin >> num;
  };
  if (!std::cin) {
    std::cerr<< "not a sequence\n";
    return 1;
  }else if (subMax == 0) {
    std::cerr<<"too short sequence\n";
  } else {
    std::cout<< subMax << "\n";
  };
};
