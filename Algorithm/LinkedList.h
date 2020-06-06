#pragma once

#include "Common.h"
#include "LinkNode.h"

// 带附加头结点，降低程序结构的复杂性
template <class T>
class LinkedList {
protected:
  LinkNode<T>* first;
public:
  LinkedList() {
    first = new LinkNode<T>();
  }

  LinkedList(const T& x) {
    // 构造默认的附加头结点，再在后面附加初始的节点数据
    first = new LinkNode<T>();
    first->next = new LinkNode<T>(x);
  }

  LinkedList(LinkedList<T>& list);

  int length() const;

  T* getData(int i) const;

  LinkNode<T>* search(T x) const;

  LinkNode<T>* locate(int i) const;

  bool insert(int i, T& x) const;

  bool remove(int i);

  void output() const;

  LinkNode<T> getHead() const {
    return first;
  }
};

template<class T>
inline LinkedList<T>::LinkedList(LinkedList<T>& list)
{
  T value;

  LinkNode<T>* n1 = list.getHead();
  LinkNode<T>* n2 = first = new LinkNode<T>();

  while (n1->next != NULL) {
    value = n1->next->data;

    n2->next = new LinkNode<T>(value);

    n1 = n1->next;
    n2 = n2->next;
  }

  n2->next = NULL;
}

template<class T>
inline int LinkedList<T>::length() const
{
  int length = 0;
  LinkNode<T>* n = first;

  while (n->next != NULL) {
    length++;
  }
  return length;
}

template<class T>
inline T* LinkedList<T>::getData(int i) const
{
  assert(i > 0);

  LinkNode<T> n = first;
  while (n.next != NULL && i-- > 0) {
    n = n->next;
  }
  return n;
}

template<class T>
inline LinkNode<T>* LinkedList<T>::search(T x) const
{
  LinkNode<T>* node = first;
  while (node->next != NULL) {
    if (node->next->data = x) {
      return node->next;
    }
    node = node->next;
  }
  return NULL;
}

template<class T>
inline LinkNode<T>* LinkedList<T>::locate(int i) const
{
  // 返回第i个节点的指针，若i=0，则返回空的头结点
  assert(i >= 0);

  int k = 0;
  LinkNode<T>* node = first;
  while (node != NULL && k < i) {
    k++;
    node = node->next;
  }
  return node;
}

template<class T>
inline bool LinkedList<T>::insert(int i, T& x) const
{
  // 插入到第i个节点的后面，如果i=0，则插入到第一个节点的前面
  assert(i >= 0);

  int cursor = 0;
  LinkNode<T>* current = locate(i);
  if (current == NULL) {
    return false;
  }

  LinkNode<T>* newNode = new LinkNode<T>(x);
  newNode->next = current->next;
  current->next = newNode;

  return true;
}

template<class T>
inline bool LinkedList<T>::remove(int i)
{
  // 删除第i个节点
  assert(i > 0);

  LinkNode<T>* current = locate(i - 1);
  if (current == NULL || current->next == NULL) {
    return false;
  }

  LinkNode<T>* del = current->next;
  current->next = current->next->next;
  delete del;

  return true;
}

template<class T>
inline void LinkedList<T>::output() const
{
  cout << "LINKEDLIST: " << endl;
  LinkNode<T>* node = first;
  while (node->next != NULL) {
    cout << node->next->data << "->";
    node = node->next;
  }
  cout << "NULL" << endl;
}
