#include "buffer.hpp"
namespace miheev
{
  class String
  {
  public:
    String();
    void fillFromBuff(Buffer buff);
    void expand(size_t size);

  private:
    char* string_;
    size_t size_;
    size_t indexOfFirstFree_;
  }
}
