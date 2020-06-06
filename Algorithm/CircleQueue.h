#pragma once

#include "Common.h"

template <class T>
class CircleQueue {
public:
  CircleQueue(int size = 100);

  bool enQueue(const T& x);

  bool deQueue(T& x);

  bool getFront(T& x) const {
    return elements[front];
  }

  void makeEmpty() {
    front = 0;
    rear = 0;
  }

  bool isEmpty() const {
    return front == rear;
  }

  bool isFull() const {
    return (rear + 1) % maxSize == front;
  }

  int getSize() const {
    return (rear - front + maxSize) % maxSize;
  }

  void output() const {
    cout << "Circle-Queue [size=" << getSize() << "]" << endl;
    for (int i = 0; i < getSize(); i++)
    {
      int index = (i + front) % maxSize;
      cout << elements[index] << " ";
    }
    cout << endl << "==== END ====" << endl;
  }

protected:
  int front, rear;
  T* elements;
  int maxSize;
};

template<class T>
inline CircleQueue<T>::CircleQueue(int size)
{
  maxSize = size;
  elements = new T[maxSize];
  front = 0;
  rear = 0;
}

template<class T>
inline bool CircleQueue<T>::enQueue(const T& x)
{
  if (isFull()) {
    return false;
  }

  elements[rear] = x;
  rear = (rear + 1) % maxSize;
  return true;
}

template<class T>
inline bool CircleQueue<T>::deQueue(T& x)
{
  if (isEmpty()) return false;
  x = elements[front];
  front = (front + 1) % maxSize;
  return true;
}

template<class T>
ostream& operator<<(ostream& os, const CircleQueue<T>& queue)
{
  os << "Circle-Queue [size=" << queue.getSize() << "]" << endl;
  for (int i = 0; i < queue.getSize(); i++)
  {
    int index = (i + queue.front) % queue.getSize();
    os << queue.elements[index] << " ";
  }
  os << endl << "==== END ====" << endl;
  return os;
}
