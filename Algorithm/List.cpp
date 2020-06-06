//#include "List.h"
//
//// 将新元素插入到第i个节点之后，如果i=0则表示插入到第1个节点之前
//template<class T>
//bool List<T>::insert(int i, T& item)
//{
//	// 整个插入操作抽象成两个原子操作：
//	// 1. 在第1个元素前插入一个节点
//	//	  此时有两种可能：
//	//	  a. 链表为空
//	//	  b. i=0
//	if (i == 0 || first == NULL) {
//		LinkNode* node = new LinkNode(item);
//		assert(node != NULL);
//
//		node->link = first;
//		first = node;
//	}
//	// 2. 在第i个元素后插入一个节点
//	//    依次遍历所有节点，当遍历到第i个节点时，在后面插入新节点
//	//    此时需要判定，链表长度是否够长
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
