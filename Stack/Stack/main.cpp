#include "stack.h"

using namespace std;

int main()
{
    /* ¹¹Ôìº¯Êı²âÊÔ */
	Stack<int> s;
	cout << "The size of the stack : " << s.size() << '\n' << endl;

	/* Push²âÊÔ */
    for (int i = 1; i <= 5; i++)
        s.Push(i);
	cout << "The element int the stack after pushing : ";
    s.Print();
	s.Push(10);
	cout << endl;

	/* size²âÊÔ */
	cout << "The size of the stack : ";
	int l = s.size();
	cout << l << '\n' << endl;

	/* Pop²âÊÔ */
	cout << "The element by popping : ";
	for (int i = 0; i < l; i++) {
		cout << s.Pop() << ' ';
	}
	cout << endl;
	cout << "The element int the stack after popping : ";
	s.Print();
	cout << endl;

    return 0;
}
