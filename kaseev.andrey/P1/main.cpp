#include <iostream>
#include "delitel.hpp"
#include <stdexcept>

int main()
{
  kaseev::delitel delitel;
  try {
    int ans;
    ans = delitel(std::cin);
    std::cout << ans << "\n";
    return 0;
  }
  catch (const std::logic_error &error) {
    std::cerr << error.what() << "\n";
    return 2;
  }
}
