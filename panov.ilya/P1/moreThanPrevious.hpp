#ifndef MORETHENPREVIOUS_HPP
#define MORETHENPREVIOUS_HPP
namespace panov
{
  struct MoreThanPrevious
  {
    public:
      MoreThanPrevious();
      void operator()(int number);
      size_t operator()() const;
    private:
      int count;
      size_t first;
  };
}
#endif
