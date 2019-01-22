#ifndef SingleList
#define SingleList

#include "ListNode.h"

using namespace std;

template<typename EleType>
class LinkedList {	// ����ͷ����
public:
	LinkedList();	// ֻ����һ����ͷ
	LinkedList(const EleType *eles, const int n); // ��������ָ��������Ԫ���������
	~LinkedList();
	int Length();					// ��������ĳ���
	int FindKth(int k);				// ����������ָ��λ�õĽڵ��ֵ����1��ʼ��������ͬ��
	int FindPosition(const int val);// ���ҽڵ��������е�λ��
	void Append(const int val);		// ������ĩβ��ӽڵ�
	void Insert(const int val, int k);	// ���ڵ���������ָ��λ�ã�����֮��
	void Delete(const int val);		// ɾ��������ָ���Ľڵ�
	void DeleteKth(int k);			// ɾ�������еĵ�k���ڵ�
	void Print();					// ��ӡ���������еĽڵ�
	void Clear();					// ɾ�������г�ͷ��������Ԫ��

private:
	Node<EleType> *head;
	int length;
};

/*ֻ����һ����ͷ*/
template<typename EleType>
LinkedList<EleType>::LinkedList() {
	head = new Node<EleType>;
	length = 0;
}

/*��һ��Ԫ���������*/
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

/*ɾ������ͷ������Ԫ��*/
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

/*ɾ����������*/
template<typename EleType>
LinkedList<EleType>::~LinkedList() {
	Clear();
	delete head;
}

/*����������*/
template<typename EleType>
int LinkedList<EleType>::Length() {
	return length;
}

/*����������ָ��λ�õĽڵ��ֵ*/
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

/*����ĳһ�ڵ��������е�λ��*/
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

/*�������ĩβ����Ԫ��*/
template<typename EleType>
void LinkedList<EleType>::Append(const int val) {
	Node<EleType> *p = head;
	while (p->next) {
		p = p->next;
	}
	p->next = new Node<EleType>(val);
	length++;
}

/*�������ָ��λ�ã�����֮�󣩲���Ԫ��*/
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

/*ɾ�������е�ĳһ�ڵ�*/
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

/*ɾ��������ָ��λ�õĽڵ�*/
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

/*��ӡ�����е�����Ԫ��*/
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

