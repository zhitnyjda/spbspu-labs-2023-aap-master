miheev::Buffer::Buffer(size_t size):
  size_(size)
{
  buff_ = new char[size];
}

miheev::Buffer::clean()
{
  for (size_t i = 0; i < size_; i++)
  {
    buff_[i] = 0;
  }
}

miheev::Buffer::getSize()
{
  return size_;
}

char miheev::Buffer::operator[](size_t index)
{
  return buff_[index];
}
