#pragma once

#include "Common.h"
#include "LinkNode.h"

template <class T>
class DoubleCircleList {
protected:
  LinkNode<T>* first;
public:
  DoubleCircleList() {
    first = new LinkNode<T>();
    first->next = first;
    first->last = first;
  }

  DoubleCircleList(const T& x) {
    first = new LinkNode<T>();

    LinkNode<T>* node = new LinkNode<T>(x);

    first->next = node;
    first->last = node;

    node->next = first;
    node->last = first;
  }

  int length() const;

  LinkNode<T>* search(T x) const;

  LinkNode<T>* locate(int i) const;

  bool insert(int i, T& x) ;

  bool remove(int i);

  void output() const;

  LinkNode<T> getHead() const {
    return first;
  }

};

template<class T>
inline int DoubleCircleList<T>::length() const
{
  int k = 0;
  LinkNode<T>* current = first;
  while (current->next != first) {
    k++;
  }
  return k;
}

// VALUABLE : 循环条件与返回结果相互配合，天衣无缝

template<class T>
inline LinkNode<T>* DoubleCircleList<T>::search(T x) const
{
  LinkNode<T>* node = first;
  while (node->next != first && node->data != x) node = node->next;

  return node->data == x ? node : NULL;
}

template<class T>
inline LinkNode<T>* DoubleCircleList<T>::locate(int i) const
{
  assert(i >= 0);
  // 返回第i个节点，i=0时，返回空的附加头节点

  if (i == 0) return first;

  LinkNode<T>* current = first;
  
  int k = 1;

  while (current->next != first && k != i) {
    k++;
    current = current->next;
  }
  return k == i ? current->next : NULL;
}

template<class T>
inline bool DoubleCircleList<T>::insert(int i, T& x) 
{
  LinkNode<T>* current = locate(i);
  LinkNode<T>* newNode = new LinkNode<T>(x);
  newNode->next = current->next;
  newNode->last = current;
  current->next->last = newNode;
  current->next = newNode;
  return true;
}

template<class T>
inline bool DoubleCircleList<T>::remove(int i)
{
  assert(i > 0);

  LinkNode<T>* current = locate(i);
  LinkNode<T>* pre = current->last;
  pre->next = current->next;
  current->next->last = pre;
  delete current;
  return true;
}

template<class T>
inline void DoubleCircleList<T>::output() const
{
  cout << "Double-Circle-List:" << endl;
  LinkNode<T>* current = first;
  while (current->next != first) {
    cout << current->next->data << "<->";
    current = current->next;
  }
  cout << "oxo" << endl;
}
