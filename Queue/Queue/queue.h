#ifndef _queue_h
#define _queue_h

#include <iostream>

using namespace std;

template<typename EleType>
class SeqQueue {	// 双向顺序队列(数组实现)
public:
	SeqQueue(const int s = 10);		// 构造函数，顺序队列的容量默认为10
	~SeqQueue();					// 析构函数
	bool IsEmpty();					// 判断队空
	bool IsFull();					// 判断队满
	void EnQueue(const int);		// 入队
	void DeQueue();					// 出队	
	EleType GetFront();				// 获取队首元素
	EleType GetRear();				// 获取队尾元素
	void MakeEmpty();				// 将队列清空
	int size();						// 队列的当前大小
	void Print();					// 打印队列中的所有元素
private:
	EleType *q;	// 保存队中数据的数组
	int front, rear;	// 队首和队尾指针
	int MaxSize;		// 队列容量
};

/* 构造函数 */
template<typename EleType>
SeqQueue<EleType>::SeqQueue(const int s) {
	MaxSize = s;
	q = new EleType[MaxSize + 1];	// 数组下标从1开始
	front = rear = 0;
}

/* 析构函数 */
template<typename EleType>
SeqQueue<EleType>::~SeqQueue() {
	delete[] q;
}

/* 判断队空 */
template<typename EleType>
bool SeqQueue<EleType>::IsEmpty() {
	return front == 0;
}

/* 判断队满 */
template<typename EleType>
bool SeqQueue<EleType>::IsFull() {
	return rear == MaxSize;
}

/* 入队 */
template<typename EleType>
void SeqQueue<EleType>::EnQueue(const int value) {
	if (IsFull()) {
		cout << "The queue is full ! " << endl;
		return;
	}

	if (!front) {
		front++;
	}
	q[++rear] = value;
}

/* 出队 */
template<typename EleType>
void SeqQueue<EleType>::DeQueue() {
	if (IsEmpty()) {
		cout << "The queue is empty ! " << endl;
		return;
	}
	front++;
}

/* 获取队首元素 */
template<typename EleType>
EleType SeqQueue<EleType>::GetFront() {
	if (IsEmpty()) {
		cout << "The queue is empty ! " << endl;
		return NULL;
	}
	return q[front];
}

/* 获取队尾元素 */
template<typename EleType>
EleType SeqQueue<EleType>::GetRear() {
	if (IsEmpty()) {
		cout << "The queue is empty ! " << endl;
		return NULL;
	}
	return q[rear];
}

/* 清空队列 */
template<typename EleType>
void SeqQueue<EleType>::MakeEmpty() {
	front = rear = 0;
}

/* 队列中元素的数量 */
template<typename EleType>
int SeqQueue<EleType>::size() {
	if (front > 0) {
		return rear - front + 1;
	}
	else {
		return 0;
	}
}


/* 打印队列中的所有元素 */
template<typename EleType>
void SeqQueue<EleType>::Print() {
	if (!front) {
		cout << "The queue is empty ! " << endl;
		return;
	}

	for (int i = front; i <= rear; i++) {
		cout << q[i] << ' ';
	}
	cout << endl;
}

#endif
