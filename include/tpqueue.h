// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T, int size>
class TPQueue {
 private:
    T w[size] = {0};
    int a = 0, b = 0;
 public:
  void push(T value) {
      int i = b;
      while ((--i >= a) && (value.prior > w[i % size].prior)) {
          w[(i + 1) % size] = w[i % size];
      }
      w[(i+1) % size] = value;
      b++;
  }
  T pop() {
      return w[(a++) % size];
  }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
