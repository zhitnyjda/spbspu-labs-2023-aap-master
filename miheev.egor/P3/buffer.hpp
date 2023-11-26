namespace miheev
{
  class Buffer
  {
  public:
    Buffer(size_t size);
    void clean();
    size_t getSize();
    char operator[](size_t index);

  private:
    char* buff_;
    size_t size_;
  }
}
