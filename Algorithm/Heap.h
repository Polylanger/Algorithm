#pragma once
#include "Common.h"

template<class T, class E>
class Heap {
public:
  Heap(int size = defaultSize);

  Heap(E arr[], int n);

  bool insert(const E& x);

  bool removeFirst(E& x);

  bool isEmpty() const {
    return currentSize == 0;
  }

  bool isFull() const {
    return currentSize == maxHeapSize;
  }

  void makeEmpty() {
    currentSize = 0;
  }

private:
  E* heap;
  int currentSize;
  int maxHeapSize;
  // ��start��m�»�����
  void siftDown(int start, int m);
  // ��start��0�ϻ�����
  void siftUp(int start);

};

template<class T, class E>
inline Heap<T, E>::Heap(int size)
{
  maxHeapSize = size > maxHeapSize ? size : maxHeapSize;
  heap = new E[maxHeapSize];
  assert(heap == NULL);
  currentSize = 0;
}

template<class T, class E>
inline Heap<T, E>::Heap(E arr[], int n)
{
  maxHeapSize = size > maxHeapSize ? size : maxHeapSize;
  heap = new E[maxHeapSize];
  assert(heap == NULL);
}
