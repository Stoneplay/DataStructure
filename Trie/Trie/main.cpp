#include "Trie.h"

int main() {
	Trie t;

	t.insert("apple");
	t.insert("banana");

	cout << "pear : " << t.search("pear") << endl;
	cout << "apple : " << t.search("apple") << endl;
	cout << "app : " << t.startsWith("app") << endl;
	cout << "ban : " << t.startsWith("ban") << endl;
	cout << "pea : " << t.startsWith("pea") << endl;

	return 0;
}