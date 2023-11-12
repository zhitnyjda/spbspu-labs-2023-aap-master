#include <iostream>
#include <stdexcept>

struct FindingSubMax
{
public:
  void finding (int num)
  {
  ++seqCount_;
  std:: cout<< num<<" "<< max_<<" " << subMax_<<"\n";
  if (num > max_)
  {
    subMax_ = max_;
    max_ = num;
    std::cout<< num<<max_<<subMax_<< "\n";
  }
  else if (num > subMax_)
  {
    subMax_ = num;
  }
  std:: cout<< num<<" "<< max_<<" "<<  subMax_<< "\n";
  }
  size_t getResult () const
  {
    if (seqCount_ <2)
    {
      throw std::logic_error("too short sequence");
    }
    else
    {
    return subMax_;
    }
  }
private:
  size_t subMax_ = 0;
  size_t max_ = 0;
  size_t seqCount_ = 0;
};

int main()
{
  FindingSubMax FindingSubMax;
  int num = 0;
  std::cin>>num;
  while ((std::cin) and (num !=0))
  {
    FindingSubMax.finding(num);
    std::cin >> num;
  };
  if (!std::cin) {
    std::cerr<< "not a sequence\n";
    return 1;
  }
  else
  {
    try
    {
      std::cout<< FindingSubMax.getResult() << "\n";
      return 2;
    }
    catch (const std:: exception&e)
    {
      std::cerr<<e.what() << "\n";
    }
   }
};

