#include <iostream>
#include <cmath>
#include "myStruct.hpp"
 
DinString::DinString(size_t n, char c)
{
  this->dinstr = new char[n + 1];
 
  for (size_t i = 0; i < n; i++)
  {
    this->dinstr[i] = c;
  }
  this->dinstr[n] = '\0';
  size = n;
  counterCurrent = 0;
  addArr = 10;
}  
DinString::~DinString()
{
  delete[] dinstr;
}
 
void DinString::dinResize()
{
  char* tmp = new char[size + addArr];
  char * newInput = new char[size + addArr];
  for (size_t i = 0; i < size; i++)
  {
    newInput[i] = dinstr[i];
  }
  size = size + addArr;
  delete [] dinstr;
  dinstr = newInput;
}
 
void DinString::dinAppend(char elem)
{
  dinstr[counterCurrent++] = elem;
}    
void DinString::dinOutput()
{
  for (size_t i = 0; i < size; i++)
  {
    std::cout << dinstr[i];
  }
   std::cout << std::endl;  
}
