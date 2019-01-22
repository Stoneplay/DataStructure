#ifndef ListNode
#define ListNode

#include <iostream>

template<typename EleType>
class Node {
public:
	Node();
	Node(const EleType val, Node *p = NULL);

	EleType element;
	Node *next;
};

template<typename EleType>
Node<EleType>::Node() {
	element = 0;
	next = NULL;
}

template<typename EleType>
Node<EleType>::Node(const EleType val, Node *p) {
	element = val;
	next = p;
}


#endif // !ListNode