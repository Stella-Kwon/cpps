#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &other) { (void)other; }
Serializer &Serializer::operator=(const Serializer &other) {
  (void)other;
  return *this;
}
Serializer::~Serializer() {}

// reinterpret_cast<>(): is very powerful tool which converts between pointers,
// references, and integer types on a bit-level (conversion).
uintptr_t Serializer::serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr); //data *ptr -> uintprt_t (int)
}

Data *Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw); //int -> ptr
}