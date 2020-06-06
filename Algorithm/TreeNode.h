#pragma once

#include "Common.h"

template <class T>
class TreeNode {

public:
  T data;
  TreeNode<T>* left;
  TreeNode<T>* right;

  // 用于非递归后续遍历，取值：L R
  char tag;

  // 用于线索二叉树，取值：true false
  bool ltag, rtag;

  TreeNode(T x, TreeNode<T>* l = NULL, TreeNode<T>* r = NULL, bool lt = false, bool rt = false) {
    data = x;
    left = l;
    right = r;
    ltag = lt;
    rtag = rt;
  }
};