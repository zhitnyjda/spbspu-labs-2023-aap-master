#include "line.h"
#include <fstream>
#include <cstring>

Line::Line(const char *string, size_t len)
{
  this->len = len;
  try {
    data = new char[len]{};
    for (int i = 0; i < (string == nullptr ? 0 : strlen(string)); ++i) {
      data[i] = string[i];
    }
  } catch (std::exception const &ex) {
    throw std::runtime_error(ex.what());
  }
}

Line::Line(const Line &line)
{
  (*this) = Line(line.data, line.len);
}

Line::~Line()
{
  len = 0;
  delete[] data;
}

size_t Line::size() const
{
  return len;
}

char *Line::get_line() const
{
  return data;
}

void Line::resize(size_t new_len)
{
  if (new_len == 0 && len == 0) {
    new_len = 1;
  }
  if (new_len <= len) {
    throw std::logic_error("Invalid resize");
  }
  try {
    char *new_data = new char[new_len]{};
    for (int i = 0; i < len; ++i) {
      new_data[i] = data[i];
    }
    delete[] data;
    len = new_len;
    data = new char[len];
    for (int i = 0; i < len; ++i) {
      data[i] = new_data[i];
    }
    delete[] new_data;
  } catch (std::exception const &ex) {
    throw std::runtime_error(ex.what());
  }
}

Line &Line::operator=(const Line &line)
{
  if (this == &line) {
    return *this;
  }
  len = line.len;
  delete data;
  data = new char[len];
  for (int i = 0; i < len; ++i) {
    data[i] = line.data[i];
  }
  return *this;
}

char &Line::operator[](long long i)
{
  if (i < 0 || i >= this->len) {
    throw std::overflow_error("Invalid index\n");
  }
  return data[i];
}

std::istream &operator>>(std::istream &in, Line &line)
{
  long long i = 0;
  char c;
  do {
    std::cin.get(c);
    if (i == line.size()) {
      line.resize(line.len * 2);
    }
    line[i++] = c;
  } while (c != '\n');
  line[i - 1] = '\0';
  return in;
}

std::ostream &operator<<(std::ostream &out, const Line &line)
{
  for (long long i = 0; i < line.len; ++i) {
    if (line.data[i] != '\0') {
      out << line.data[i];
    } else {
      break;
    }
  }
  return out;
}
