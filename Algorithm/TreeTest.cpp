#include "TreeTest.h"
#include "StackTest.h"

// 先序遍历构建二叉树
void preorderConstructor(char*& s, TreeNode<char>*& root)
{
  if (*s == 0 || *s == '#')
    return;

  root = new TreeNode<char>(*s);

  s += 1;
  preorderConstructor(s, root->left);

  s += 1;
  preorderConstructor(s, root->right);
}

// 递归后序遍历输出
void postorderOutputer(TreeNode<char>* root)
{
  if (root == NULL) return;

  postorderOutputer(root->left);
  postorderOutputer(root->right);
  cout << root->data;
}

// 非递归后序遍历输出
void postorderOutputerInLoop(TreeNode<char>* root)
{
  TreeNode<char>* p = root;
  ArrayStack<TreeNode<char>*>* stack = new ArrayStack<TreeNode<char>*>();
  while (p != NULL || !stack->isEmpty()) {
    // 节点第一次被访问：入栈，并添加L标记
    if (p != NULL) {
      stack->push(p);
      p->tag = 'L';
      p = p->left;
    }
    else {
      // 栈顶节点先出栈，判断该节点第几次被访问到
      stack->pop(p);
      // 第二次被访问：重新入栈，并修改标记为R，并且继续访问右边子树
      if (p->tag == 'L') {
        p->tag = 'R';
        stack->push(p);
        p = p->right;
      }
      // 第三次被访问：输出节点，并继续从栈顶POP节点（待POP节点是当前节点的父节点）
      else {
        cout << p->data;
        p = NULL;
      }
    }
  }
}

void runTreeTest() {
  TreeNode<char>* root;
  // 1. preorderConstructor
  char* s = (char*)"ABC##DE#G##F###";
  preorderConstructor(s, root);

  // 2. postorderOutputer
  TreeNode<char>* root1 = root;
  cout << "二叉树后序遍历：" << endl;
  postorderOutputer(root1);

  // 3. postorderOutputerInLoop
  TreeNode<char>* root2 = root;
  cout << endl << "非递归二叉树后序遍历：" << endl;
  postorderOutputerInLoop(root2);
}