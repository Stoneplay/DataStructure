#ifndef SingleList
#define SingleList

#include "ListNode.h"

using namespace std;

template<typename EleType>
class LinkedList {	// 带表头链表
public:
	LinkedList();	// 只返回一个表头
	LinkedList(const EleType *eles, const int n); // 将数组中指定数量的元素组成链表
	~LinkedList();
	int Length();					// 返回链表的长度
	int FindKth(int k);				// 返回链表中指定位置的节点的值（从1开始计数，下同）
	int FindPosition(const int val);// 查找节点在链表中的位置
	void Append(const int val);		// 在链表末尾添加节点
	void Insert(const int val, int k);	// 将节点插在链表的指定位置（插完之后）
	void Delete(const int val);		// 删除链表中指定的节点
	void DeleteKth(int k);			// 删除链表中的第k个节点
	void Print();					// 打印链表中所有的节点
	void Clear();					// 删除链表中除头结点的所有元素

private:
	Node<EleType> *head;
	int length;
};

/*只返回一个表头*/
template<typename EleType>
LinkedList<EleType>::LinkedList() {
	head = new Node<EleType>;
	length = 0;
}

/*将一串元素组成链表*/
template<typename EleType>
LinkedList<EleType>::LinkedList(const EleType *eles, const int n) {
	if (n < 1) {
		cout << "Length Error!" << endl;
	}

	head = new Node<EleType>;

	Node<EleType> *p = head;
	for (int i = 0; i < n; i++) {
		p->next = new Node<EleType>(eles[i]);
		p = p->next;
	}

	length = n;
}

/*删除除表头的所有元素*/
template<typename EleType>
void LinkedList<EleType>::Clear() {
	Node<EleType> *p = head->next;
	while (p) {
		head->next = p->next;
		delete p;
		p = head->next;
	}

	length = 0;
}

/*删除整个链表*/
template<typename EleType>
LinkedList<EleType>::~LinkedList() {
	Clear();
	delete head;
}

/*返回链表长度*/
template<typename EleType>
int LinkedList<EleType>::Length() {
	return length;
}

/*返回链表中指定位置的节点的值*/
template<typename EleType>
int LinkedList<EleType>::FindKth(int k) {
	if (k > length || k < 1) {
		cout << "The position '" << k << "' isn't in this linked list!" << endl;
		return NULL;
	}

	Node<EleType> *p = head;
	int count = 1;
	while (p->next) {
		if (count == k) {
			break;
		}
		else {
			count++;
			p = p->next;
		}
	}

	return p->next->element;
}

/*查找某一节点在链表中的位置*/
template<typename EleType>
int LinkedList<EleType>::FindPosition(const int val) {
	Node<EleType> *p = head;
	int position = 1;

	while (p->next) {
		if (p->next->element == val) {
			return position;
		}
		else {
			position++;
			p = p->next;
		}
	}

	cout << "The '" << val << "' node isn't in this linked list!" << endl;
	return NULL;
}

/*在链表的末尾插入元素*/
template<typename EleType>
void LinkedList<EleType>::Append(const int val) {
	Node<EleType> *p = head;
	while (p->next) {
		p = p->next;
	}
	p->next = new Node<EleType>(val);
	length++;
}

/*在链表的指定位置（插完之后）插入元素*/
template<typename EleType>
void LinkedList<EleType>::Insert(const int val, int k) {
	if (k > length || k < 1) {
		cout << "The position '" << k << "' isn't in this linked list!" << endl;
		return;
	}

	Node<EleType> *p = head;
	int count = 1;

	while (p->next) {
		if (count == k) {
			Node<EleType> *cell = new Node<EleType>(val);
			cell->next = p->next;
			p->next = cell;
			break;
		}
		else {
			count++;
			p = p->next;
		}
	}

	length++;
}

/*删除链表中的某一节点*/
template<typename EleType>
void LinkedList<EleType>::Delete(const int val) {
	Node<EleType> *p = head;
	while (p->next) {
		if (p->next->element == val) {
			Node<EleType> *tmp = p->next;
			p->next = p->next->next;
			delete tmp;

			length--;
			return;
		}
		else {
			p = p->next;
		}
	}

	cout << "The '" << val << "' node isn't in this linked list!" << endl;
}

/*删除链表中指定位置的节点*/
template<typename EleType>
void LinkedList<EleType>::DeleteKth(int k) {
	if (k > length || k < 1) {
		cout << "The position '" << k << "' isn't in this linked list!" << endl;
		return;
	}

	Node<EleType> *p = head;
	int count = 1;

	while (p->next) {
		if (count == k) {
			Node<EleType> *tmp = p->next;
			p->next = p->next->next;
			delete tmp;
			break;
		}
		else {
			count++;
			p = p->next;
		}
	}

	length--;
}

/*打印链表中的所有元素*/
template<typename EleType>
void LinkedList<EleType>::Print() {
	Node<EleType> *p = head;

	while (p->next) {
		cout << p->next->element << ' ';
		p = p->next;
	}
	cout << endl;
}

#endif // !SingleList

