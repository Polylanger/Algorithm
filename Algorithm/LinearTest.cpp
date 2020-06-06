
#include <iostream>

#include "ArrayList.h"
#include "LinkedList.h"
#include "DoubleCircleList.h"

using namespace std;

void unionOnSeq(ArrayList<int>& l1, ArrayList<int>& l2) {
	int n = l1.length(), m = l2.length();

	for (int i = 1; i <= m; i++) {
		int value = *l2.getData(i);
		int result = l1.search(value);

		if (result == 0) {
			l1.insert(n++, value);
		}
	}

	cout << "Union Result: " << endl;
	l1.output();
	l2.output();
}

void intersectionOnSeq(ArrayList<int>& l1, ArrayList<int>& l2) {
	int n = l1.length(), m = l2.length(), i = 1;
	// 判断是否加“等号”，取一组最简单的用例（(1), ()）代入
	// l1中只有一个元素时，需要进入循环体
	while (i <= n) {
		if (l2.search(*l1.getData(i)) == 0) {
			l1.remove(i);
			n--;
		}
		else {
			i++;
		}
	}

	cout << "Intersection Result: " << endl;
	l1.output();
	l2.output();
}


void runArrayList() {
	cout << "================== START SEQ-LIST TEST ==================" << endl;
	ArrayList<int>* seq1 = new ArrayList<int>();
	ArrayList<int>* seq2 = new ArrayList<int>();

	for (int i = 1; i < 10; i++) {
		int v1 = i * 2;
		seq1->insert(0, v1);

		int v2 = i * i;
		seq2->insert(0, v2);
	}

	seq1->output();
	seq2->output();

	unionOnSeq(*seq1, *seq2);

	intersectionOnSeq(*seq1, *seq2);

	cout << "==================   END SEQ-LIST TEST ==================" << endl << endl;
}

void runLinkedList() {
	cout << "================== START LINKED-LIST TEST ==================" << endl;
	LinkedList<int>* list = new LinkedList<int>();
	for (int i = 0; i < 5; i++)
	{
		list->insert(0, i);
	}
	list->remove(3);
	cout << list->search(4)->data << endl;;

	list->output();
	cout << "==================   END LINKED-LIST TEST ==================" << endl << endl;
}

void runDoubleCircleList() {
	cout << "================== START DOUBLE-LINKED-LIST TEST ==================" << endl;
	DoubleCircleList<int>* list = new DoubleCircleList<int>();
	for (int i = 0; i < 5; i++)
	{
		list->insert(0, i);
	}
	list->remove(3);
	cout << list->search(4)->data << endl;;

	list->output();
	cout << "==================   END LINKED-LIST TEST ==================" << endl << endl;
}

int runLinearTest() {

	//runArrayList();

	runLinkedList();

	runDoubleCircleList();

	return 0;
}
