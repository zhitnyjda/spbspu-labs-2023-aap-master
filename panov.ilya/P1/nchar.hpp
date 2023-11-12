#ifndef NCHAR_HPP
#define NCHAR_HPP
namespace panov
{
  struct Nchar
  {
    public:
      Nchar();
      void operator()(int number);
      size_t operator()() const;
    private:
      int count;
      int first;
  };
}
#endif
