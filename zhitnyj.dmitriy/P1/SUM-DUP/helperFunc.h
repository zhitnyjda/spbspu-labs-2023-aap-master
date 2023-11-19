#ifndef SOURCES_1_HELPERSFUNC_H
#define SOURCES_1_HELPERSFUNC_H
#include <iostream>

struct helperFunc
{
public:
  helperFunc(int count = 0, int n = 0, int l_ = 0, int s_ = 0)
  {
    helperFunc::count = count;
    
    helperFunc::n = n;
    
    helperFunc::l_ = l_;
    
    helperFunc::s = s_; 
  }
  int operator()(std::istream *str);
  int operator()(int n);
private:
  int count, n, l_, s;
};

#endif
