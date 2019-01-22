#ifndef _queue_h
#define _queue_h

#include <iostream>

using namespace std;

template<typename EleType>
class SeqQueue {	// ˫��˳�����(����ʵ��)
public:
	SeqQueue(const int s = 10);		// ���캯����˳����е�����Ĭ��Ϊ10
	~SeqQueue();					// ��������
	bool IsEmpty();					// �ж϶ӿ�
	bool IsFull();					// �ж϶���
	void EnQueue(const int);		// ���
	void DeQueue();					// ����	
	EleType GetFront();				// ��ȡ����Ԫ��
	EleType GetRear();				// ��ȡ��βԪ��
	void MakeEmpty();				// ���������
	int size();						// ���еĵ�ǰ��С
	void Print();					// ��ӡ�����е�����Ԫ��
private:
	EleType *q;	// ����������ݵ�����
	int front, rear;	// ���׺Ͷ�βָ��
	int MaxSize;		// ��������
};

/* ���캯�� */
template<typename EleType>
SeqQueue<EleType>::SeqQueue(const int s) {
	MaxSize = s;
	q = new EleType[MaxSize + 1];	// �����±��1��ʼ
	front = rear = 0;
}

/* �������� */
template<typename EleType>
SeqQueue<EleType>::~SeqQueue() {
	delete[] q;
}

/* �ж϶ӿ� */
template<typename EleType>
bool SeqQueue<EleType>::IsEmpty() {
	return front == 0;
}

/* �ж϶��� */
template<typename EleType>
bool SeqQueue<EleType>::IsFull() {
	return rear == MaxSize;
}

/* ��� */
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

/* ���� */
template<typename EleType>
void SeqQueue<EleType>::DeQueue() {
	if (IsEmpty()) {
		cout << "The queue is empty ! " << endl;
		return;
	}
	front++;
}

/* ��ȡ����Ԫ�� */
template<typename EleType>
EleType SeqQueue<EleType>::GetFront() {
	if (IsEmpty()) {
		cout << "The queue is empty ! " << endl;
		return NULL;
	}
	return q[front];
}

/* ��ȡ��βԪ�� */
template<typename EleType>
EleType SeqQueue<EleType>::GetRear() {
	if (IsEmpty()) {
		cout << "The queue is empty ! " << endl;
		return NULL;
	}
	return q[rear];
}

/* ��ն��� */
template<typename EleType>
void SeqQueue<EleType>::MakeEmpty() {
	front = rear = 0;
}

/* ������Ԫ�ص����� */
template<typename EleType>
int SeqQueue<EleType>::size() {
	if (front > 0) {
		return rear - front + 1;
	}
	else {
		return 0;
	}
}


/* ��ӡ�����е�����Ԫ�� */
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
