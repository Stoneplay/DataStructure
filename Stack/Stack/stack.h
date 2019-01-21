#ifndef _stack_h
#define _stack_h

#include <iostream>

using namespace std;    

template<typename EleType>
class Stack{
public:
	Stack(int cap = 5);			// 构造函数
	~Stack();					// 析构函数
	bool IsFull();				// 判断栈满
	bool IsEmpty();				// 判断栈空
	void Push(const EleType);	// 入栈
	EleType Pop();				// 出栈
	int size();					// 栈的当前大小
	void Print();				// 打印栈中的所有元素
private:
    int top;					// 栈顶指针
	int capacity;				// 栈的容量
    EleType *arr;				// 指向存储栈中元素的数组
}; 

/* 构造函数 */
template<typename EleType>
Stack<EleType>::Stack(int cap) {
	top = 0;
	capacity = cap;
	arr = new int[capacity + 1];	// 数组下标从1开始
}

/* 析构函数 */
template<typename EleType>
Stack<EleType>::~Stack() {
	delete[] arr;
}

/* 判断栈空 */
template<typename EleType>
bool Stack<EleType>::IsEmpty() {
	return top < 1;
}

/* 判断栈满 */
template<typename EleType>
bool Stack<EleType>::IsFull() {
	return top >= capacity;
}

/* 入栈 */
template<typename EleType>
void Stack<EleType>::Push(const EleType element) {
	if (IsFull()) {
		cout << "The stack is full !" << endl;
		return;
	}

	arr[++top] = element;
}

/* 出栈 */
template<typename EleType>
EleType Stack<EleType>::Pop() {
	if (IsEmpty()) {
		cout << "The stack is empty !" << endl;
		return NULL;
	}

	return arr[top--];
}

/* 栈的当前大小 */
template<typename EleType>
int Stack<EleType>::size() {
	return top;
}

/* 打印栈中所有元素 */
template<typename EleType>
void Stack<EleType>::Print() {
	if (IsEmpty()) {
		cout << "The stack is empty !" << endl;
		return;
	}

	/* 从栈顶开始打印 */
	for (int i = top; i > 0; i--) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

#endif // _stack_h
