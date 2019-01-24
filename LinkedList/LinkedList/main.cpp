#include "SingleList.h"

int main() {
	/* ππ‘Ï∫Ø ˝≤‚ ‘ */
	int eles[5] = {1, 2, 3, 4, 5};
	LinkedList<int> l1;
	LinkedList<int> l2(eles, 4);

	/* Append≤‚ ‘ */
	l1.Append(0);
	l1.Append(-1);
	l1.Append(-2);

	/* Print≤‚ ‘ */
	cout << "The L1 list after appending : ";
	l1.Print();
	cout << "The L2 list : ";
	l2.Print();
	cout << endl;

	/* Length≤‚ ‘ */
	cout << "The length of L1 list : " << l1.Length() << endl;
	cout << "The length of L2 list : " << l2.Length() << '\n' << endl;

	/* FindKth≤‚ ‘ */
	cout << "THe 2th node of L1 list : " << l1.FindKth(2) << endl;
	cout << "The 5th node of L2 list : " << l2.FindKth(5) << '\n' << endl; // ???

	/* FindPositon≤‚ ‘ */
	cout << "The position of '1' in L1 list : " << l1.FindPosition(1) << endl;
	cout << "The position of '3' in L2 list : " << l2.FindPosition(3) << '\n' << endl;

	/* Insert≤‚ ‘ */
	l1.Insert(-3, 1);
	l2.Insert(2, 2);
	cout << "The L1 list after inserting : ";
	l1.Print();
	cout << "The L2 list after inserting : ";
	l2.Print();
	cout << endl;

	/* Delete≤‚ ‘ */
	l1.Delete(-2);
	l2.Delete(1);
	cout << "The L1 list after deleting the node '-2' : ";
	l1.Print();
	cout << "The L2 list after deleting the node '1' : ";
	l2.Print();
	cout << endl;

	/* DeleteKth≤‚ ‘ */
	l1.DeleteKth(2);
	l2.DeleteKth(1);
	cout << "The L1 list after deleting the 2th node : ";
	l1.Print();
	cout << "The L2 list after deleting the 1th node : ";
	l2.Print();
	cout << endl;

	return 0;
}