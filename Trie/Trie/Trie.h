#ifndef _Trie_H
#define _Trie_H

#include<string>
#include "TrieNode.h"

using namespace std;

class Trie {
public:
	Trie();
	~Trie();
	void insert(string);		// �����µ���
	bool search(string);		// ���ҵ���
	int startsWith(string);		// ����ǰ׺

private:
	TrieNode* root;			// Trie���ĸ��ڵ�(���洢�κ���Ϣ)
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
		if (!p->next[word[i] - 'a']) {		// ��ǰ�ַ�������,�������в���ڵ�
			p->next[word[i] - 'a'] = new TrieNode();
		}
		p = p->next[word[i] - 'a'];
		p->count++;
	}
	p->isWord = true;	// ��ʱpָ�򵥴ʵ����һ���ַ�,�����ַ��Ľ�β��־λ��1
}

bool Trie::search(string word) {
	TrieNode *p = root;
	for (size_t i = 0; i < word.length(); i++) {
		if (p->next[word[i] - 'a']) {
			p = p->next[word[i] - 'a'];		// ��ǰ�ַ�����,������ѯ
		}
		else {
			return false;	// ��ǰ�ַ�������,��ѯ����
		}
	}
	return p->isWord;
}

int Trie::startsWith(string prefix) {
	TrieNode *p = root;
	for (size_t i = 0; i < prefix.length(); i++) {
		if (p->next[prefix[i] - 'a']) {
			p = p->next[prefix[i] - 'a'];	// ��ǰ�ַ�����,������ѯ
		}
		else {
			return 0;	// ��ǰ�ַ�������,��ѯ����
		}
	}
	return p->count;
}

#endif // !_Trie_H

