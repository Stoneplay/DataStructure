#include "UnionFind.h"

int main() {
	/* ππ‘Ï∫Ø ˝≤‚ ‘ */
	UFSet uf(5);

	/* PrintSet≤‚ ‘ */
	uf.PrintSet(5);
	uf.PrintSet(4);

	/* IsConnected≤‚ ‘ */
	cout << "\n1 and 3 are in the same set ?" << endl;
	cout << uf.IsConnected(1, 3) << endl;

	/* Union≤‚ ‘ */
	cout << "\nUnion 1 and 3 : " << endl;
	uf.Union(1, 3);
	cout << "1 and 3 are in the same set ?" << endl;
	cout << uf.IsConnected(1, 3) << endl;

	/* Find≤‚ ‘ */
	uf.Union(1, 4);
	cout << "\nFind 4 : " << endl;
	cout << uf.Find(4) << endl;
	cout << "The set for 4 : " << endl;
	uf.PrintSet(4);

	/* ElementsSize≤‚ ‘ */
	cout << "\n The element_size of the union_find_set : " << endl;
	cout << uf.ElementsSize() << endl;

	/* SetsSize≤‚ ‘ */
	cout << "\n The set_size of the union_find_set : " << endl;
	cout << uf.SetsSize() << endl;

	return 0;
}