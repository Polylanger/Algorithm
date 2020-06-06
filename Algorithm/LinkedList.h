#pragma once

#include "Common.h"
#include "LinkNode.h"

// ������ͷ��㣬���ͳ���ṹ�ĸ�����
template <class T>
class LinkedList {
protected:
  LinkNode<T>* first;
public:
  LinkedList() {
    first = new LinkNode<T>();
  }

  LinkedList(const T& x) {
    // ����Ĭ�ϵĸ���ͷ��㣬���ں��渽�ӳ�ʼ�Ľڵ�����
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
  // ���ص�i���ڵ��ָ�룬��i=0���򷵻ؿյ�ͷ���
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
  // ���뵽��i���ڵ�ĺ��棬���i=0������뵽��һ���ڵ��ǰ��
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
  // ɾ����i���ڵ�
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
