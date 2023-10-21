#include "maxelement.hpp"
  int maxelement(int n, int k, int mx)
  {
  if (n > mx)
  {
    mx = n;
    k = 1;
  }
  if (n == mx)
  {
    k += 1;
  }
  return k;
  }
  