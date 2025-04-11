
template <typename T> Array<T>::Array() : _array(nullptr), _size(0){};

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n){};

template <typename T> // copy
Array<T>::Array(const Array<T> &other) : _array(nullptr), _size(other._size) {
  if (_size > 0) {

    _array = new T[_size]();
    // sams as c; ++i or i++ will still start from 0 (in for loop);

    //++i is much efficient as it directly changes its own value
    // MyClass &operator++() {
    //   // 1. 현재 객체 직접 수정
    //   value += 1; // 간단한 예시, 실제로는 클래스의 내부 상태를 변경
    //   // 2. 수정된 자기 자신의 참조 반환
    //   return *this;
    // }
    // i++ will have its own value increased and make tmp value to return the
    // previous originla value
    // MyClass operator++(int) { // int 매개변수는 후위 증가를 구분하는 표시
    //   MyClass temp = *this;   // 1. 현재 객체의 복사본 생성
    //   ++(*this);              // 2. 현재 객체 증가
    //   return temp;            // 3. 원래(증가 전) 값 반환
    // }
    for (unsigned int i = 0; i < _size; ++i) {
      _array[i] = other._array[i];
    }
  }
}

// template <typename T> //other is not exist

// Array &&is an rvalue reference that binds to temporary objects or objects
// explicitly moved with std::move(), enabling efficient transfer of resources
// without copying. Array<T>::Array(Array<T>&& other):
// _array(std::move(other.data),_size(other._size)
// {
//      other._array = nullptr;
//      other._size = 0;
// }

template <typename T> // let other exist still
Array<T> &Array<T>::operator=(const Array<T> &other) {
  if (this != &other) {

    // 1. way :
    //  Array temp(other); //copy
    //  //will exchange the value;
    //  std::swap(_array, temp._array);
    //  std::swap(_size, temp._size);

    // 2. way : if you used new T[n]();
    delete[] _array;
    _size = other._size;
    if (_size > 0) {
      _array = new T[_size]();
      // copy
      for (unsigned int i = 0; i < _size; ++i) {
        _array[i] = other._array[i];
      }
    } else
      _array = nullptr;
  }
  return *this;
}

// template <typename T> // other is no more exist
// // why noexcept is there?
// // Using noexcept on move operations :

// // Performance boost: Enables standard library containers like std::vector to
// // use faster move operations instead of copies during reallocation. Compiler
// // optimization : Tells the compiler the function won't throw exceptions,
// // allowing additional optimizations.
// //  Clear intent : Signals to other developers that the operation is
// guaranteed
// //  not to throw exceptions.Array<T> &

// // 이동하는 행위 : noexcept가 있어야 복사하지않고 바로 그 값을 전달
// Array<T>& Array<T>::operator=(Array<T>&& other) noexcept {
//   if (this != &other) {
//     _array = std::move(other._array);
//     _size = other._size;
//     other._data = nullptr; // necessary as move does not really do it itself.
//     (if it is a unique_ptr then it would) other._size = 0;
//   }
//   return *this;
// }

// template <typename T>
// Array<T>::~Array(){};

// if you used new T[n]();
template <typename T> Array<T>::~Array() { delete[] _array; };

template <typename T> T &Array<T>::operator[](unsigned int index) {
  if (index >= _size) {
    throw OutOfBoundsException();
  }
  return _array[index];
}

template <typename T> const T &Array<T>::operator[](unsigned int index) const {
  if (index >= _size) {
    throw OutOfBoundsException();
  }
  return _array[index];
}

template <typename T> unsigned int Array<T>::size() const { return _size; }

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const noexcept {
  return "Array index out of bounds";
}