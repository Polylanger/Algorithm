#pragma once

#include "Common.h"

const int stackIncreament = 20;

template <class T>
class ArrayStack {
private:
  T* element;
  int top;
  int maxSize;
  void overflowProcess();

public:

  ArrayStack(int size = 100);

  void push(const T& x);

  bool pop(T& x);

  T getTop();

  bool makeEmpty();

  bool isEmpty() const {
    return top == -1;
  }

  void output() const;

};

template<class T>
inline void ArrayStack<T>::overflowProcess()
{
  T* newArray = new T[maxSize + stackIncreament];

  for (int i = 0; i <= top; i++) {
    newArray = element[i];
  }

  delete[]element;
  element = newArray;
}

template<class T>
inline ArrayStack<T>::ArrayStack(int size)
{
  element = new T[size];
  top = -1;
  maxSize = size;

  assert(element != NULL);
}

template<class T>
inline void ArrayStack<T>::push(const T& x)
{
  assert(top < maxSize - 1);
  element[++top] = x;
}

template<class T>
inline bool ArrayStack<T>::pop(T& x)
{
  if (isEmpty()) return false;
  x = element[top--];
  return true;
}

template<class T>
inline T ArrayStack<T>::getTop()
{
  assert(top != -1);
  return element[top];
}

template<class T>
inline bool ArrayStack<T>::makeEmpty()
{
  top = -1;
  return true;
}

template<class T>
inline void ArrayStack<T>::output() const
{
  for (int i = 0; i <= top; i++)
  {
    cout << "# " << i + 1 << ": " << element[i] << endl;
  }
}
