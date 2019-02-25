#include "BinarySearchTree.h"

int main() {
	BinSearchTree<int> bt;		// ²âÊÔÓÃÀı£º5 2 8 1 4 6 9 3 7
	int num;

	/* Insert²âÊÔ */
	cout << "The BinTree : ";
	while (cin >> num) {
		bt.Insert(num);
		if (cin.get() == '\n') {
			break;
		}
	}

	/* Size²âÊÔ */
	cout << "\nThe size of the BinTree : " << bt.Size() << endl;

	/* PrintByPreOrder²âÊÔ */
	cout << "Print by pre-order : ";
	bt.PrintByPreOrder();

	/* PrintByInOrder²âÊÔ */
	cout << "Print by in-order : ";
	bt.PrintByInOrder();

	/* PrintByPostOrder²âÊÔ */
	cout << "Print by post order : ";
	bt.PrintByPostOrder();

	/* PrintByLevelOrder²âÊÔ */
	cout << "Print by level-order : ";
	bt.PrintByLevelOrder();

	/* Maximun²âÊÔ */
	BinTreeNode<int> *max = bt.Maximun();
	cout << "The maximun node of the BinTree : " << max->data << endl;

	/* Mniximun²âÊÔ */
	BinTreeNode<int> *min = bt.Minimun();
	cout << "The minimun node of the BinTree : " << min->data << endl;

	/* Search²âÊÔ */
	BinTreeNode<int> *node = bt.Search(3);
	cout << "The search of the '3' : ";
	if (node) {
		cout << node->data << endl;
	}
	else {
		cout << "NULL" << endl;
	}

	BinTreeNode<int> *node0 = bt.Search(10);
	cout << "The search of the '10' : ";
	if (node0) {
		cout << node0->data << endl;
	}
	else {
		cout << "NULL" << endl;
	}

	/* parent²âÊÔ */
	BinTreeNode<int> *node1 = bt.Parent(3);
	cout << "The parent of the '3' : ";
	if (node1) {
		cout << node1->data << endl;
	}
	else {
		cout << "NULL" << endl;
	}

	BinTreeNode<int> *node2 = bt.Parent(5);
	cout << "The parent of the '5' : ";
	if (node2) {
		cout << node2->data << endl;
	}
	else {
		cout << "NULL" << endl;
	}

	/* Delete²âÊÔ */
	cout << "\nThe BinTree after deleting the '3' : " << endl;
	bt.Delete(3);
	cout << "The size of the BinTree : " << bt.Size() << endl;
	cout << "Print by level-order : ";
	bt.PrintByLevelOrder();

	cout << "\nThe BinTree after deleting the '7' : " << endl;
	bt.Delete(7);
	cout << "The size of the BinTree : " << bt.Size() << endl;
	cout << "Print by level-order : ";
	bt.PrintByLevelOrder();

	cout << "\nThe BinTree after deleting the '5' : " << endl;
	bt.Delete(5);
	cout << "The size of the BinTree : " << bt.Size() << endl;
	cout << "Print by level-order : ";
	bt.PrintByLevelOrder();

	return 0;
}