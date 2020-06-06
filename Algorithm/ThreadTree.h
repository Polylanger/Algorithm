#pragma once
#include "TreeNode.h"

// ����������

template <class T>
class ThreadTree {
protected:
  // ���ĸ�ָ��
  TreeNode<T>* root;
  // ���������������������
  void createInThread(TreeNode<T>* current, TreeNode<T>*& pre);
  // Ѱ�Ҹ��ڵ�
  TreeNode<T>* parent(TreeNode<T>* t);
public:
  ThreadTree() {
    root = NULL;
  }
  // ������������������
  void createInThread();
  // Ѱ�������µ�һ���ڵ�
  TreeNode<T>* first(TreeNode<T>* current);
  // Ѱ�����������һ���ڵ�
  TreeNode<T>* last(TreeNode<T>* current);
  // Ѱ�������µĺ�̽ڵ�
  TreeNode<T>* next(TreeNode<T>* current);
  // Ѱ�������µ�ǰ���ڵ�
  TreeNode<T>* proir(TreeNode<T>* current);
  // �����������������������
  void inorder();
};

template<class T>
inline void ThreadTree<T>::createInThread(TreeNode<T>* current, TreeNode<T>*& pre)
{
  if (current == NULL) return;

  // ������������
  createInThread(current->left, pre);

  // ��ǰ�ڵ������Ůָ��Ϊ�գ�������ǰ���ڵ�
  if (current->left == NULL) {
    current->left = pre;
    current->ltag = true;
  }

  // ǰ���ڵ������Ůָ��Ϊ�գ������ŵ�ǰ�ڵ�
  if (pre != NULL && pre->right == NULL) {
    pre->right = current;
    pre->rtag = true;
  }

  pre = current;

  // ������������
  createInThread(current->right, pre);
}

template<class T>
inline void ThreadTree<T>::createInThread()
{
  TreeNode<T>* pre = NULL;

  if (root != NULL) {
    createInThread(root, pre);
    // ���һ���ڵ�����Ϊ��
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
