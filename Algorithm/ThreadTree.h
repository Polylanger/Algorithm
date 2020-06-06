#pragma once
#include "TreeNode.h"

// 线索二叉树

template <class T>
class ThreadTree {
protected:
  // 树的根指针
  TreeNode<T>* root;
  // 中序遍历建立线索二叉树
  void createInThread(TreeNode<T>* current, TreeNode<T>*& pre);
  // 寻找父节点
  TreeNode<T>* parent(TreeNode<T>* t);
public:
  ThreadTree() {
    root = NULL;
  }
  // 建立中序线索二叉树
  void createInThread();
  // 寻找中序下第一个节点
  TreeNode<T>* first(TreeNode<T>* current);
  // 寻找中序下最后一个节点
  TreeNode<T>* last(TreeNode<T>* current);
  // 寻找中序下的后继节点
  TreeNode<T>* next(TreeNode<T>* current);
  // 寻找中序下的前驱节点
  TreeNode<T>* proir(TreeNode<T>* current);
  // 中序遍历中序线索化二叉树
  void inorder();
};

template<class T>
inline void ThreadTree<T>::createInThread(TreeNode<T>* current, TreeNode<T>*& pre)
{
  if (current == NULL) return;

  // 左子树线索化
  createInThread(current->left, pre);

  // 当前节点的左子女指针为空，让其存放前驱节点
  if (current->left == NULL) {
    current->left = pre;
    current->ltag = true;
  }

  // 前驱节点的右子女指针为空，让其存放当前节点
  if (pre != NULL && pre->right == NULL) {
    pre->right = current;
    pre->rtag = true;
  }

  pre = current;

  // 右子树线索化
  createInThread(current->right, pre);
}

template<class T>
inline void ThreadTree<T>::createInThread()
{
  TreeNode<T>* pre = NULL;

  if (root != NULL) {
    createInThread(root, pre);
    // 最后一个节点设置为空
    pre->right = NULL;
    pre->rtag = 1;
  }
}

template<class T>
inline TreeNode<T>* ThreadTree<T>::first(TreeNode<T>* current)
{
  TreeNode<T>* p = current;
  while (!p->ltag) {
    p = p->left;
  }
  return p;
}

template<class T>
inline TreeNode<T>* ThreadTree<T>::last(TreeNode<T>* current)
{
  TreeNode<T>* p = current;
  while (!p->rtag) {
    p = p->right;
  }
  return p;
}

template<class T>
inline TreeNode<T>* ThreadTree<T>::next(TreeNode<T>* current)
{
  TreeNode<T>* p = current;
  if (p == NULL) return NULL;

  if (p->rtag) 
    return p->right;

  return first(p->right);
}

template<class T>
inline TreeNode<T>* ThreadTree<T>::proir(TreeNode<T>* current)
{
  TreeNode<T>* p = current;

  if (p == NULL) return NULL;

  if (p->ltag) 
    return p->left;

  return last(p->left);
}

template<class T>
inline void ThreadTree<T>::inorder()
{
  for (TreeNode<T>* p = first(); p != null; p = next()) {
    cout << p;
  }
}
