#pragma once

#include "Common.h"

template <class T>
class TreeNode {

public:
  T data;
  TreeNode<T>* left;
  TreeNode<T>* right;

  // ���ڷǵݹ����������ȡֵ��L R
  char tag;

  // ����������������ȡֵ��true false
  bool ltag, rtag;

  TreeNode(T x, TreeNode<T>* l = NULL, TreeNode<T>* r = NULL, bool lt = false, bool rt = false) {
    data = x;
    left = l;
    right = r;
    ltag = lt;
    rtag = rt;
  }
};