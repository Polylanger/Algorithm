//#include "SeqList.h"
//
//template<class T>
//void SeqList<T>::reSize(int newSize)
//{
//	if (newSize <= maxSize) {
//		cerr << "Invalid SeqList size" << endl;
//		return;
//	}
//
//	T* newArray = new T[newSize];
//	if (newArray == NULL) {
//		cerr << "Storage allocate error! " << endl;
//		exit(1);
//	}
//
//	for (int i = 0; i <= last; i++) {
//		newArray[i] = data[i];
//	}
//
//	delete[] data;
//
//	data = newArray;
//	maxSize = newSize;
//}
//
//template<class T>
//SeqList<T>::SeqList(int size)
//{
//	if (size > 0) {
//		maxSize = size;
//		last = -1;
//		data = new T[maxSize];
//		if (data == NULL) {
//			cerr << "Storage allocate error! " << endl;
//			exit(1);
//		}
//	}
//}
//
//template<class T>
//SeqList<T>::SeqList(SeqList<T>& list)
//{
//	maxSize = list.size();
//	last = list.length() - 1;
//	data = new T[maxSize];
//	if (data == NULL) {
//		cerr << "Storage allocate error! " << endl;
//		exit(1);
//	}
//	for (int i = 0; i <= last; i++) {
//		data[i] = list.getData(i);
//	}
//}
//
//template<class T>
//int SeqList<T>::search(T& item) const
//{
//	for (int i = 0; i <= last; i++) {
//		if (data[i] == item) return i + 1;
//	}
//	return 0;
//}
//
//template<class T>
//int SeqList<T>::locate(int i) const
//{
//	return i > 0 && i <= last ? i : 0;
//}
//
//template<class T>
//bool SeqList<T>::insert(int i, T& item)
//{
//	if (last == maxSize - 1) return false;
//	if (i < 0 || i > last + 1) return false;
//
//	for (int j = last + 1; j > i; j--)
//		data[j] = data[j - 1];
//	data[i] = item;
//	last++;
//
//	return true;
//}
//
//template<class T>
//bool SeqList<T>::remove(int i, T& x)
//{
//	if (last == -1) return false;
//	if (i < 1 || i > last + 1) return false;
//
//	x = data[i - 1];
//	for (int j = i - 1; j < last; j++) {
//		data[j] = data[j + 1];
//	}
//	last--;
//
//	return true;
//}
//
////template<class T>
////void SeqList<T>::sort()
////{
////}
////
////template<class T>
////void SeqList<T>::input()
////{
////}
//
//template<class T>
//void SeqList<T>::output()
//{
//	cout << "last: " << last << endl;
//	for (int i = 0; i < last; i++) {
//		cout << "#" << i + 1 << " : " << data[i] << endl;
//	}
//}
