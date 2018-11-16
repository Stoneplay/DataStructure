#include "SingleList.h"

using namespace std;

int main() {
	int val;

	/*CreateHead≤‚ ‘*/
	ListNode *l = CreateHead();
	cout << "Please input the data of linklist : ";

	/*Insert≤‚ ‘*/
	while (cin >> val) {
		if (Insert(l, val)) {
			if (cin.get() == '\n') {
				break;
			}
			else continue;
		}
		else {
			cout << "Insertion fail!\n" << endl;
			break;
		}

	}

	/*PrintList≤‚ ‘*/
	cout << "\nCreateHead() and Insert() and PrintList() and Length() test:\n";
	cout << "The list : ";
	PrintList(l);

	/*Length≤‚ ‘*/
	cout << "The length of the list : ";
	int len = Length(l);
	cout << len << '\n' << endl;

	/*Insert(kth)≤‚ ‘*/
	cout << "Insert(kth) test:\n";
	int insertk = 3;
	int insertval = 10;
	if (Insert(l, insertval, insertk)) {
		cout << "The list after inserting '" << insertval <<"' in the " << insertk <<"th position : ";
		PrintList(l);
		cout << endl;
	}
	else {
		cout << "The " << insertk << "th position isn't in the list!\n" << endl;
	}

	/*FindKth≤‚ ‘*/
	cout << "FindKth() test:\n";
	int findk = 3;
	ListNode *kth = FindKth(l, findk);
	if (kth) {
		cout << "The " << findk << "th node of the list : ";
		cout << kth->value << '\n' << endl;
	}
	else {
		cout << "The "<< findk << "th positon isn't in the list!\n" << endl;
	}

	/*Position≤‚ ‘*/
	cout << "Position() test:\n";
	int valpos = 1;
	int pos = Position(l, valpos);
	if (pos) {
		cout << "The '" << valpos << "' is the " << pos << "th node of the list!\n" << endl;
	}
	else {
		cout << "The '" << valpos << "' isn't in the list!\n" << endl;
	}

	/*Delete≤‚ ‘*/
	cout << "Delete() test:\n";
	int deleteval = 10;
	if (Delete(l, deleteval)) {
		cout << "The list after deleting the '" << deleteval << "' : ";
		PrintList(l);
		cout << endl;
	}
	else {
		cout << "The '" << deleteval <<"' isn't in the list!\n" << endl;
	}


	/*DeleteKth≤‚ ‘*/
	cout << "DeleteKth() test:\n";
	int deletepos = 2;
	if (DeleteKth(l, deletepos)) {
		cout << "The list after inserting the " << deletepos << "th node : ";
		PrintList(l);
		cout << endl;
	}
	else {
		cout << "The " << deletepos << "th position isn't in the list!\n" << endl;
	}

	return 0;
}