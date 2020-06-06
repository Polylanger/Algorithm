#pragma once

#include "Common.h"

template <class T>
class SLinkNode {
public:
  T data;
  int link;
};

template <class T>
class StaticList {
private:
  
  SLinkNode<T> elem[defaultSize];
  
  int avil;

public:

  void initList();

  int length();

  int search(T x);

  int locate(int i);

  bool append(T x);

  bool insert(int i, T x);

  bool remove(int i);

};

template<class T>
inline void StaticList<T>::initList()
{
  // 初始化时：
  // 0 |  1 |  2 | ... | size-1 |
  //   |avil|    |     |        |
  // -1|  2 |  3 | ... |     -1 |
  elem[0].link = -1;
  avil = 1;

  for (int i = 1; i < defaultSize - 1; i++)
  {
    elem[i].link = i + 1;
  }

  elem[defaultSize - 1].link = -1;
}

template<class T>
inline int StaticList<T>::length()
{
  int l = 0;
  int p = elem[0].link;
  while (p != -1) {
    l++;
    p = elem[p].link;
  }
  return p;
}

template<class T>
inline int StaticList<T>::search(T x)
{
  int p = elem[0].link;
  while (p != -1) {
    if (elem[p].data == x) return p;
    p = elem[p].link;
  }
  return -1;
}

template<class T>
inline int StaticList<T>::locate(int i)
{
  assert(i >= 0);
  int p = elem[0].link;
  for (int j = 0; j < i; j++) {
    if (p == -1) return p;
    p = elem[p].link;
  }
  return p;
}

template<class T>
inline bool StaticList<T>::append(T x)
{
  // 还有位置
  assert(elem[avil].link != -1);

  // 1. 找到最后一个节点的位置
  int p = 0;
  while (elem[p].link != -1) {
    p = elem[p].link;
  }

  // 2. 找到第一个可用空节点的位置
  int q = avil;

  avil = elem[avil].link;

  // 3. 存数据
  elem[q].data = x;
  elem[q].link = -1;
  elem[p].link = q;

  return true;
}

template<class T>
inline bool StaticList<T>::insert(int i, T x)
{
  int p = locate(i);
  if (p == -1) return false;

  int q = avil;
  avil = elem[avil].link;

  elem[q].data = x;
  elem[q].link = elem[p].link;
  elem[p].link = q;

  return true;
}

template<class T>
inline bool StaticList<T>::remove(int i)
{
  int p = locate(i - 1);

  if (p == -1) return false;

  int q = elem[p].link;
  elem[p].link = elem[q].link;

  elem[q].link = avil;
  avil = q;

  return true;
}
