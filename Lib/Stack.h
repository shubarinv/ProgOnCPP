//
// Created by vhund on 24.03.2019.
//

#ifndef PROGONCPP_STACK_H
#define PROGONCPP_STACK_H

#include <iomanip>
#include <iostream>

using namespace std;
typedef int DataType;

template <class Tdata> class Stack {
private:
  struct Element {
    Tdata data;
    Element *next;
  } * pstack, *top;

public:
  Stack() { pstack = nullptr; }

  ~Stack();

  int Empty();

  Tdata Top();

  Tdata Pop();

  int Push(Tdata x);

  Tdata showData();

  void next();

  void setData(Tdata);

  void resetPstackToTop();
};

template <class Tdata> Stack<Tdata>::~Stack() {
  Element *temp;
  while (pstack) {
    temp = pstack;
    pstack = pstack->next;
    top = pstack->next;
    delete temp;
  }
}

template <class Tdata> int Stack<Tdata>::Empty() { return pstack == nullptr; }

template <class Tdata> Tdata Stack<Tdata>::Top() { return pstack->data; }

template <class Tdata> Tdata Stack<Tdata>::Pop() {
  Element *del = pstack;
  DataType temp = pstack->data;
  pstack = pstack->next;
  delete del;
  return temp;
}

template <class Tdata> int Stack<Tdata>::Push(Tdata x) {
  auto ins = new (nothrow) Element;
  if (ins == NULL)
    return 0;
  ins->data = x;
  ins->next = pstack;
  pstack = ins;
  top = pstack;
  return 1;
}

template <class Tdata> Tdata Stack<Tdata>::showData() { return pstack->data; }

template <class Tdata> void Stack<Tdata>::next() { pstack = pstack->next; }

template <class Tdata> void Stack<Tdata>::setData(Tdata newData) {
  pstack->data = newData;
}
template <class Tdata> void Stack<Tdata>::resetPstackToTop() { pstack = top; }
#endif // PROGONCPP_STACK_H
