#include "queue.h"

int main() {
	/* ���캯������ */
	SeqQueue<int> q;

	/* EnQueue���� */
	for (int i = 0; i < 10; i++) {
		q.EnQueue(i);
	}
	cout << "The queue after entering the queue : ";
	q.Print();
	cout << endl;

	/* DeQueue���� */
	for (int i = 0; i < 3; i++) {
		q.DeQueue();
	}
	cout << "The queue after quiting the queue : ";
	q.Print();
	cout << endl;

	/* GetFront���� */
	int front = q.GetFront();
	cout << "The front of the queue : " << front << '\n' << endl;

	/* GetRear���� */
	int rear = q.GetRear();
	cout << "The rear of the queue : " << rear << '\n' << endl;

	/* size���� */
	cout << "The current size of the queue : " << q.size() << '\n' << endl;

	/* MakeEmpty���� */
	q.MakeEmpty();
	cout << "The size of the queue after making empty : " << q.size() << endl;
	q.Print();
	
	return 0;
}