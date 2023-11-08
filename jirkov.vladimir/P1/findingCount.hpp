#ifndef FINDINGCOUNT_HPP
#define FINDINGCOUNT_HPP
#include <cstddef>
namespace jirkov
{
  struct FindingCount
  {
    public:
      FindingCount();
      void operator()(size_t prev, size_t current, size_t next);
      size_t operator()() const;
    private:
      size_t lenghts_;
      size_t count_;
  };
}
#endif
