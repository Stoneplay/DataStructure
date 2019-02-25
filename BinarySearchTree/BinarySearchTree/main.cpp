#include "BinarySearchTree.h"

int main() {
	BinSearchTree<int> bt;
	int num;

	/* Insert≤‚ ‘ */
	cout << "The BinTree : ";
	while (cin >> num) {
		bt.Insert(num);
		if (cin.get() == '\n') {
			break;
		}
	}

	/* Size≤‚ ‘ */
	cout << "\nThe size of the BinTree : " << bt.Size() << endl;

	/* PrintByPreOrder≤‚ ‘ */
	cout << "Print by pre-order : ";
	bt.PrintByPreOrder();

	/* PrintByInOrder≤‚ ‘ */
	cout << "Print by in-order : ";
	bt.PrintByInOrder();

	/* PrintByPostOrder≤‚ ‘ */
	cout << "Print by post order : ";
	bt.PrintByPostOrder();

	/* PrintByLevelOrder≤‚ ‘ */
	cout << "Print by level-order : ";
	bt.PrintByLevelOrder();

	/* Maximun≤‚ ‘ */
	BinTreeNode<int> *max = bt.Maximun();
	cout << "The maximun node of the BinTree : " << max->data << endl;

	/* Mniximun≤‚ ‘ */
	BinTreeNode<int> *min = bt.Minimun();
	cout << "The minimun node of the BinTree : " << min->data << endl;

	/* Search≤‚ ‘ */
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

	/* parent≤‚ ‘ */
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

	/* Delete≤‚ ‘ */
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