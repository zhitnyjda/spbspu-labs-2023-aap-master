#ifndef LINE_H
#define LINE_H
#include <fstream>

class Line {
  size_t len;
  char *data;

public:
  explicit Line();
  explicit Line(const char *string=nullptr, size_t=0);
  Line(const Line &);
  ~Line();

  size_t size() const;
  char *get_line() const;
  void resize(size_t);
  Line &operator=(const Line &);
  char &operator[](size_t);

  friend std::istream &operator>>(std::istream &, Line &);
  friend std::ostream &operator<<(std::ostream &, const Line &);
};

#endif
