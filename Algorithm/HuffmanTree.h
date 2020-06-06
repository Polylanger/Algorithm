#pragma once
#include "HuffmanNode.h"

const int defaultSize = 20;

// E��Ȩ����������
// T���ڵ���������
template <class T, class E> 
class HuffmanTree {
public:
  HuffmanTree(E w[], int n);

protected:
  
  HuffmanNode<T, E>* root;
  // ɾ����tΪ��������
  void deleteTree(HuffmanNode<T, E>* t);  
  // �ϲ�������
  void mergeTree(HuffmanNode<T, E>& htree1, HuffmanNode<T, E>& htree2, HuffmanNode<T, E>*& parent);
};