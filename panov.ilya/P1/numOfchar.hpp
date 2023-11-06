#ifndef NUMOFCHAR_HPP
#define NUMOFCHAR_HPP
namespace ranov
{
    struct NumOfchar
    {
    public:
        NumOfchar();
        void operator()(int number);
        int operator()() const;
    private:
        int count;
        int first;
    };
}
#endif
