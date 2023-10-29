#include <iostream>
#include "delitel.cpp"
#include <stdexcept>

int main()
{
  try {
    int ans = 0;
    ans = dilitel(std::cin);
    std::cout << ans << "\n";
    return 0;
  }
  catch (const std::logic_error &error) {
    std::cerr << error.what() << "\n";
    return 2;
  }
}