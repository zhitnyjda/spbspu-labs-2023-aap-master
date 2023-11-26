#include <iostream>
#include <string>
#include <string.h>
 
size_t addArr = 10;
 
struct DinString
{
public:
  size_t size;
  size_t size2;
  char *dinstr;
  size_t counterCurrent;
  DinString(size_t n, char c)
  {
    this->dinstr = new char[n + 1];
    for (size_t i = 0; i < n; i++)
    {
        this->dinstr[i] = c;
    }
    this->dinstr[n] = '\0';
    size = n;
    counterCurrent = 0;
  }  
  ~DinString()
  {
    delete[] dinstr;
  }

  void dinResize()
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

  void dinAppend(char elem)
  {
    dinstr[counterCurrent++] = elem;
  }    
  void dinOutput()
  {
    for (size_t i = 0; i < size; i++)
    {
      std::cout << dinstr[i];
    }
    std::cout << std::endl;  
  }
};
 
int main()
{
  char element = 0;    
  DinString s1(10, '0');
  DinString s2(10, '0');
     
  std::cin >> std::noskipws;
 
  while ((std::cin >> element) && (element != '\n'))
  {
    if (s1.counterCurrent < s1.size)
    {
        s1.dinAppend(element);
    }
    else
    {
        s1.dinResize();
        s1.dinAppend(element);
    }
  }
  s1.dinOutput();
 
  while ((std::cin >> element) && (element != '\n'))
  {
    if (s2.counterCurrent < s2.size)
    {
        s2.dinAppend(element);
    }
    else
    {
        s2.dinResize();
        s2.dinAppend(element);
    }
  }  
  s2.dinOutput();
  return 0;
}
