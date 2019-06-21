#ifndef _TrieNode_H
#define _TrieNode_H

#include<iostream>

#define MAX 26

class TrieNode {
public:
	TrieNode* next[MAX];	// 指向各个子节点的指针
	bool isWord;			// 该节点处是否构成单词
	int count;				// 单词前缀出现的次数
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