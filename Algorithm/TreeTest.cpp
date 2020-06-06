#include "TreeTest.h"
#include "StackTest.h"

// �����������������
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

// �ݹ����������
void postorderOutputer(TreeNode<char>* root)
{
  if (root == NULL) return;

  postorderOutputer(root->left);
  postorderOutputer(root->right);
  cout << root->data;
}

// �ǵݹ����������
void postorderOutputerInLoop(TreeNode<char>* root)
{
  TreeNode<char>* p = root;
  ArrayStack<TreeNode<char>*>* stack = new ArrayStack<TreeNode<char>*>();
  while (p != NULL || !stack->isEmpty()) {
    // �ڵ��һ�α����ʣ���ջ�������L���
    if (p != NULL) {
      stack->push(p);
      p->tag = 'L';
      p = p->left;
    }
    else {
      // ջ���ڵ��ȳ�ջ���жϸýڵ�ڼ��α����ʵ�
      stack->pop(p);
      // �ڶ��α����ʣ�������ջ�����޸ı��ΪR�����Ҽ��������ұ�����
      if (p->tag == 'L') {
        p->tag = 'R';
        stack->push(p);
        p = p->right;
      }
      // �����α����ʣ�����ڵ㣬��������ջ��POP�ڵ㣨��POP�ڵ��ǵ�ǰ�ڵ�ĸ��ڵ㣩
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
  cout << "���������������" << endl;
  postorderOutputer(root1);

  // 3. postorderOutputerInLoop
  TreeNode<char>* root2 = root;
  cout << endl << "�ǵݹ���������������" << endl;
  postorderOutputerInLoop(root2);
}