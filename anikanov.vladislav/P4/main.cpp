#include <iostream>
#include <fstream>
#include <string>
#include "arrayModifications.cpp"
#include "validationAndConversationToInt.cpp"

int main(int argc, char **argv)
{
  try {
    check(argc, argv);
  } catch (std::exception &e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
  int num = getInt(std::string(argv[1]));
  std::ifstream cin(argv[2]);
  std::ofstream cout(argv[3]);
  int n = 0, m = 0;
  if (!(cin >> n >> m)) {
    std::cerr << INVALID_INPUT << "\n";
    return 1;
  }
  if (num == 1) {
    int array[n * m];
    inputArray(cin, array, n, m);
    spiralIncrease(array, n, m);
    printArray(cout, array, n, m);
  } else {
    int *array = new int[n * m];
    inputArray(cin, array, n, m);
    spiralIncrease(array, n, m);
    printArray(cout, array, n, m);
    delete[] array;
  }
}

