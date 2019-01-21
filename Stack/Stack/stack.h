#ifndef _stack_h
#define _stack_h

#include <iostream>

using namespace std;    

template<typename EleType>
class Stack{
public:
	Stack(int cap = 5);			// ���캯��
	~Stack();					// ��������
	bool IsFull();				// �ж�ջ��
	bool IsEmpty();				// �ж�ջ��
	void Push(const EleType);	// ��ջ
	EleType Pop();				// ��ջ
	int size();					// ջ�ĵ�ǰ��С
	void Print();				// ��ӡջ�е�����Ԫ��
private:
    int top;					// ջ��ָ��
	int capacity;				// ջ������
    EleType *arr;				// ָ��洢ջ��Ԫ�ص�����
}; 

/* ���캯�� */
template<typename EleType>
Stack<EleType>::Stack(int cap) {
	top = 0;
	capacity = cap;
	arr = new int[capacity + 1];	// �����±��1��ʼ
}

/* �������� */
template<typename EleType>
Stack<EleType>::~Stack() {
	delete[] arr;
}

/* �ж�ջ�� */
template<typename EleType>
bool Stack<EleType>::IsEmpty() {
	return top < 1;
}

/* �ж�ջ�� */
template<typename EleType>
bool Stack<EleType>::IsFull() {
	return top >= capacity;
}

/* ��ջ */
template<typename EleType>
void Stack<EleType>::Push(const EleType element) {
	if (IsFull()) {
		cout << "The stack is full !" << endl;
		return;
	}

	arr[++top] = element;
}

/* ��ջ */
template<typename EleType>
EleType Stack<EleType>::Pop() {
	if (IsEmpty()) {
		cout << "The stack is empty !" << endl;
		return NULL;
	}

	return arr[top--];
}

/* ջ�ĵ�ǰ��С */
template<typename EleType>
int Stack<EleType>::size() {
	return top;
}

/* ��ӡջ������Ԫ�� */
template<typename EleType>
void Stack<EleType>::Print() {
	if (IsEmpty()) {
		cout << "The stack is empty !" << endl;
		return;
	}

	/* ��ջ����ʼ��ӡ */
	for (int i = top; i > 0; i--) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

#endif // _stack_h
