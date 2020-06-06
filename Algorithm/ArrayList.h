#pragma once

#include "Common.h"


template <typename T> class ArrayList
{
private:
  T* data;
  int maxSize;
  int last;
public:
  ArrayList(int size = defaultSize);

  int size() const {
    return maxSize;
  }

  int length() const {
    return last + 1;
  }

  T* getData(int i) const {
    return 1 <= i && i <= last + 1 ? &data[i - 1] : NULL;
  };

  int search(T& item) const;

  bool insert(int i, T& x);

  bool output() const;

  bool remove(int i);
};

template<typename T>
inline ArrayList<T>::ArrayList(int size)
{
  maxSize = size;
  data = new T[maxSize];
  last = -1;
}

template<typename T>
inline int ArrayList<T>::search(T& item) const 
{
  for (int i = 0; i < last + 1; i++) 
  {
    if (data[i] == item) return i + 1;
  }
  return 0;
}

template<typename T>
inline bool ArrayList<T>::insert(int i, T& x)
{
  // 元素x插入到第i个元素后面，i=0意思是插入到第一个元素前面

  assert(i >= 0 && i <= last + 1);
  assert(last < maxSize - 1);

  for (int j = last; j >= i; j--)
  {
    data[j + 1] = data[j];
  }

  data[i] = x;
  last++;

  return true;
}

template<typename T>
inline bool ArrayList<T>::output() const
{
  cout << "Length: " << last + 1 << endl;
  for (int i = 0; i < last + 1; i++)
  {
    cout << "# " << i + 1 << ": " << data[i] << endl;
  }
  return true;
}

template<typename T>
inline bool ArrayList<T>::remove(int i)
{
  assert(last > -1);
  assert(1 <= i && i <= last + 1);

  for (int j = i - 1; j < last; j++) {
    data[j] = data[j + 1];
  }

  last--;

  return true;
}
