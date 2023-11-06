#ifndef MYFUNC_H
#define MYFUNC_H
namespace psarev
{
  class maxLen
  {
  public:
    maxLen();
    void operator()(int value);
    int operator()();

    int seq_len;

  private:
    int prev_value;
    int max_len;
  };
}
#endif
