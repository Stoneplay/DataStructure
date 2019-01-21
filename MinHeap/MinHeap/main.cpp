#include "BinHeap.h"

int main() {
	MinHeap<int> h;
	
	/* Ä¬ÈÏ¹¹Ôìº¯Êı²âÊÔ */
	h.Print();
	cout << endl;

	/* Insert²âÊÔ */
	h.Insert(2);
	h.Insert(1);
	h.Insert(-1);
	h.Insert(-2);
	h.Insert(0);
	cout << "The element of the heap : ";
	h.Print();
	cout << endl;

	/* Minimun²âÊÔ */
	int min = h.Minimun();
	cout << "The minimun of the heap : " << min << '\n' << endl;

	/* Delete²âÊÔ */
	h.Delete(-1);
	cout << "The element of the heap after deleting : ";
	h.Print();
	cout << endl;

	/* Modify²âÊÔ */
	h.Modify(0, 5);
	cout << "The heap after increasing modification : ";
	h.Print();
	h.Modify(5, -3);
	cout << "The heap after decreasing modification : ";
	h.Print();
	cout << endl;

	/* ¹¹Ôìº¯Êı²âÊÔ */
	int p[5] = { 5, 2, 1, 4, 3 };
	MinHeap<int> m(p, 5);
	cout << "The heap build by unsorted array : ";
	m.Print();
	cout << endl;

	return 0;
}