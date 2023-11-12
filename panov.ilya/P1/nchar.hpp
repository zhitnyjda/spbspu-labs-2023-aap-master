#ifndef NCHAR_HPP
#define NCHAR_HPP
namespace panov
{
  struct Nchar
  {
    public:
      Nchar();
      void operator()(int number);
      long long operator()() const;
    private:
      int count;
      int first;
  };
}
#endif
