#include "maxel.h"
int maxel(int n, int& k, int& mx)
{
  if (n > mx)
  {
    mx = n;
    k = 1;
  }
  else if (n == mx)
  {
    k++;
  }
  return k;
}