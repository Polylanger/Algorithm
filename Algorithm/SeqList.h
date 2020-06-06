//#pragma once
//#include <iostream>
//#include <stdlib.h>
//#include "LinearList.h"
//
//using namespace std;
//
//const int defaultSize = 100;
////
////template <class T>
////class SeqList : public LinearList<T>
//template <class T>
//class SeqList
//{
//protected:
//	T* data;
//	int maxSize;
//	int last;
//	void reSize(int newSize);
//public:
//	SeqList(int sz = defaultSize);
//	SeqList(SeqList<T>& list);
//	~SeqList() {
//		delete[] data;
//	}
//	// ȡ˳�������
//	int size() const {
//		return maxSize;
//	}
//	// ˳����Ԫ�ص�����
//	int length() const {
//		return last + 1;
//	}
//
//	int search(T& item) const;
//
//	int locate(int i) const;
//
//	T* getData(int i) const {
//		return (i >= 1 && i <= length()) ? &data[i - 1] : NULL;
//	}
//	void setData(int i, T& item) {
//		if (i > 0 && i <= last + 1)
//			data[i - 1] = item;
//	}
//	bool insert(int i, T& item);
//	bool remove(int i, T& x);
//	bool isEmpty() const {
//		return last == -1;
//	}
//	bool isFull() const {
//		return last >= maxSize - 1;
//	}
//	//void sort();
//	//void input();
//	void output();
//
//};
