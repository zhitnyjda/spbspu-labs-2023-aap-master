#ifndef COUNT_COUNT_HPP
#define COUNT_COUNT_HPP
#include <cstddef>
namespace kovshikov
{
  struct Counter
  {
    public:
      Counter();
      void operator()(size_t num);
      size_t operator()();
    private:
      size_t count_;
      size_t max_count_;
  };
}
#endif
