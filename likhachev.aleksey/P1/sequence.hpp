#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP
namespace likhachev
{
  struct Sequence {
    public:
        Sequence();
        int read();
        bool samge_sing();

        int lmax();
        int lmin();
        int cvalue();
        int pvalue();
    private:
        int prev_value;
        int curr_value;

        int count;
        int local_max;  
        int local_min;
    };
};
#endif