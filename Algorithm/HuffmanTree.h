#pragma once
#include "HuffmanNode.h"

const int defaultSize = 20;

// E：权重数据类型
// T：节点数据类型
template <class T, class E> 
class HuffmanTree {
public:
  HuffmanTree(E w[], int n);

protected:
  
  HuffmanNode<T, E>* root;
  // 删除以t为根的子树
  void deleteTree(HuffmanNode<T, E>* t);  
  // 合并二叉树
  void mergeTree(HuffmanNode<T, E>& htree1, HuffmanNode<T, E>& htree2, HuffmanNode<T, E>*& parent);
};