#include "SingleList.h"

int main() {
	/*ππ‘Ï∫Ø ˝≤‚ ‘*/
	int eles[5] = {1, 2, 3, 4, 5};
	LinkedList<int> l1;
	LinkedList<int> l2(eles, 4);

	/*Append≤‚ ‘*/
	l1.Append(0);
	l1.Append(-1);
	l1.Append(-2);

	/*Print≤‚ ‘*/
	l1.Print();
	l2.Print();
	cout << endl;

	/*Length≤‚ ‘*/
	cout << l1.Length() << '\n' << l2.Length() << '\n' << endl;

	/*FindKth≤‚ ‘*/
	cout << l1.FindKth(2) << '\n' << l2.FindKth(5) << '\n' << endl; // ???

	/*FindPositon≤‚ ‘*/
	cout << l1.FindPosition(1) << '\n' << l2.FindPosition(3) << '\n' << endl;

	/*Insert≤‚ ‘*/
	l1.Insert(-3, 1);
	l2.Insert(2, 2);
	l1.Print();
	cout << l1.Length() << endl;
	l2.Print();
	cout << l2.Length() << endl;
	cout << endl;

	/*Delete≤‚ ‘*/
	l1.Delete(-2);
	l2.Delete(1);
	l1.Print();
	cout << l1.Length() << endl;
	l2.Print();
	cout << l2.Length() << endl;
	cout << endl;

	/*DeleteKth≤‚ ‘*/
	l1.DeleteKth(2);
	l2.DeleteKth(1);
	l1.Print();
	cout << l1.Length() << endl;
	l2.Print();
	cout << l2.Length() << endl;
	cout << endl;

	return 0;
}