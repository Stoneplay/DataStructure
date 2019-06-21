#ifndef _Trie_H
#define _Trie_H

#include<string>
#include "TrieNode.h"

using namespace std;

class Trie {
public:
	Trie();
	~Trie();
	void insert(string);		// 插入新单词
	bool search(string);		// 查找单词
	int startsWith(string);		// 查找前缀

private:
	TrieNode* root;			// Trie树的根节点(不存储任何信息)
};

Trie::Trie() {
	root = new TrieNode();
}

Trie::~Trie() {
	delete root;
}

void Trie::insert(string word) {
	TrieNode *p = root;
	for (size_t i = 0; i < word.length(); i++) {
		if (!p->next[word[i] - 'a']) {		// 当前字符不存在,则在树中插入节点
			p->next[word[i] - 'a'] = new TrieNode();
		}
		p = p->next[word[i] - 'a'];
		p->count++;
	}
	p->isWord = true;	// 此时p指向单词的最后一个字符,将该字符的结尾标志位置1
}

bool Trie::search(string word) {
	TrieNode *p = root;
	for (size_t i = 0; i < word.length(); i++) {
		if (p->next[word[i] - 'a']) {
			p = p->next[word[i] - 'a'];		// 当前字符存在,继续查询
		}
		else {
			return false;	// 当前字符不存在,查询结束
		}
	}
	return p->isWord;
}

int Trie::startsWith(string prefix) {
	TrieNode *p = root;
	for (size_t i = 0; i < prefix.length(); i++) {
		if (p->next[prefix[i] - 'a']) {
			p = p->next[prefix[i] - 'a'];	// 当前字符存在,继续查询
		}
		else {
			return 0;	// 当前字符不存在,查询结束
		}
	}
	return p->count;
}

#endif // !_Trie_H

