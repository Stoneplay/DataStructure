#ifndef _TrieNode_H
#define _TrieNode_H

#include<iostream>

#define MAX 26

class TrieNode {
public:
	TrieNode* next[MAX];	// ָ������ӽڵ��ָ��
	bool isWord;			// �ýڵ㴦�Ƿ񹹳ɵ���
	int count;				// ����ǰ׺���ֵĴ���
	TrieNode();
	~TrieNode();
};

TrieNode::TrieNode() {
	memset(next, NULL, sizeof(next));
	isWord = false;
	count = 0;
}

TrieNode::~TrieNode() {
	for (size_t i = 0; i < MAX; i++) {
		delete next[i];
	}
}

#endif // !_TrieNode_H