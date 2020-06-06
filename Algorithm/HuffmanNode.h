#pragma once

template <class T, class E>
class HuffmanNode {
public:
  E data;

  HuffmanNode<T, E> lc, rc, p;

  HuffmanNode() {
    lc = NULL;
    rc = NULL;
    p = NULL;
  }

  HuffmanNode(E elem, HuffmanNode<T, E>* left = NULL, HuffmanNode<T, E>* right = NULL, HuffmanNode<T, E>* parent = NULL) {
    data = elem;
    lc = left;
    rc = right;
    p = parent;
  }

};