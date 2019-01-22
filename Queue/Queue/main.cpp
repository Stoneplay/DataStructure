#include "queue.h"

int main() {
	/* ¹¹Ôìº¯Êı²âÊÔ */
	SeqQueue<int> q;

	/* EnQueue²âÊÔ */
	for (int i = 0; i < 10; i++) {
		q.EnQueue(i);
	}
	cout << "The queue after entering the queue : ";
	q.Print();
	cout << endl;

	/* DeQueue²âÊÔ */
	for (int i = 0; i < 3; i++) {
		q.DeQueue();
	}
	cout << "The queue after quiting the queue : ";
	q.Print();
	cout << endl;

	/* GetFront²âÊÔ */
	int front = q.GetFront();
	cout << "The front of the queue : " << front << '\n' << endl;

	/* GetRear²âÊÔ */
	int rear = q.GetRear();
	cout << "The rear of the queue : " << rear << '\n' << endl;

	/* size²âÊÔ */
	cout << "The current size of the queue : " << q.size() << '\n' << endl;

	/* MakeEmpty²âÊÔ */
	q.MakeEmpty();
	cout << "The size of the queue after making empty : " << q.size() << endl;
	q.Print();
	
	return 0;
}