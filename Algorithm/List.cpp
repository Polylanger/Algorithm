//#include "List.h"
//
//// ����Ԫ�ز��뵽��i���ڵ�֮�����i=0���ʾ���뵽��1���ڵ�֮ǰ
//template<class T>
//bool List<T>::insert(int i, T& item)
//{
//	// ��������������������ԭ�Ӳ�����
//	// 1. �ڵ�1��Ԫ��ǰ����һ���ڵ�
//	//	  ��ʱ�����ֿ��ܣ�
//	//	  a. ����Ϊ��
//	//	  b. i=0
//	if (i == 0 || first == NULL) {
//		LinkNode* node = new LinkNode(item);
//		assert(node != NULL);
//
//		node->link = first;
//		first = node;
//	}
//	// 2. �ڵ�i��Ԫ�غ����һ���ڵ�
//	//    ���α������нڵ㣬����������i���ڵ�ʱ���ں�������½ڵ�
//	//    ��ʱ��Ҫ�ж����������Ƿ񹻳�
//	else {
//		LinkNode* current = first;
//		for (int j = 1; j < i; j++) {
//			if (current == NULL) break;
//			current = current->link;
//		}
//		assert(current != NULL);
//
//		LinkNode* node = new LinkNode(item);
//		assert(node != NULL);
//
//		node->link = current->link;
//		current->link = node;
//	}
//	return true;
//}
//
//template<class T>
//bool List<T>::remove(int i, T& item)
//{	
//	LinkNode* del, * current;
//	assert(i > 0);
//
//	if (i == 1) {
//		del = first;
//		first = first->link;
//	}
//
//	current = first;
//	for (int j = 1; j < i - 1; j++) {
//		if (current == NULL) break;
//		else current = current->link;
//	}
//	assert(current != NULL);
//
//	current = current->link;
//	del->link = current;
//
//	delete del;
//	item = del->data;
//
//	return false;
//}
