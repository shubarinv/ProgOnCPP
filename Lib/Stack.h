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
  } * pstack;

public:
  Stack() { pstack = nullptr; }

  ~Stack();

  int Empty();

  Tdata Pop();

  int Push(Tdata x);

  Tdata showData();
};

template <class Tdata> Stack<Tdata>::~Stack() {
  Element *temp;
  while (pstack) {
    temp = pstack;
    pstack = pstack->next;
    delete temp;
  }
}

template <class Tdata> int Stack<Tdata>::Empty() { return pstack == nullptr; }

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
  pstack = ins;;
  return 1;
}

template <class Tdata> Tdata Stack<Tdata>::showData() { return pstack->data; }

#endif // PROGONCPP_STACK_H
