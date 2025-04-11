#pragma once
#include <exception>
template <typename T> class Array {
public:
  Array();
  Array(unsigned int a);
  Array(const Array<T> &other);
  Array<T> &operator=(const Array<T> &other); // deep copy or move copy?
  ~Array();
  T &operator[](unsigned int index);
  const T &operator[](unsigned int index) const;
  unsigned int size() const;

  class OutOfBoundsException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

private:
  // std::unique_ptr<T[]> _data;
  T *_array;
  unsigned int _size;
};
#include "Array.tpp"
