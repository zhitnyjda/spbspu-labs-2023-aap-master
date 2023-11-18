#ifndef EVENNUMBER_HPP
#define EVENNUMBER_HPP
#include <cstddef>
#include <stdexcept>
#include <limits>

namespace gorbunova
{
  struct EvenNumber
  {
  public:
    EvenNumber();
    void operator()(size_t value);
    size_t operator()();
  private:
    size_t count_;
    size_t maxCount_;
  };
}

#endif
