#pragma once

template <class T>
class LinkNode {
public:
  T data;
  LinkNode* next;
  LinkNode* last;

  LinkNode(LinkNode<T>* ptr1 = NULL, LinkNode<T>* ptr2 = NULL) {
    next = ptr1;
    last = ptr2;
  }

  LinkNode(const T& item, LinkNode<T>* ptr1 = NULL, LinkNode<T>* ptr2 = NULL) {
    data = item;
    next = ptr1;
    last = ptr2;
  }
};