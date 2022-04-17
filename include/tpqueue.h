// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T, int size>
class TPQueue {
 private:
    T as[size] = {0};
    int frst = 0, lst = 0;
 public:
  void push(T value) {
      int i = lst;
      while ((--i >= frst) && (value.prior > as[i % size].prior)) {
          as[(i + 1) % size] = as[i % size];
      }
      as[(i+1) % size] = value;
     lst ++;
  }
  T pop() {
      return as[(frst ++) % size];
  }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
