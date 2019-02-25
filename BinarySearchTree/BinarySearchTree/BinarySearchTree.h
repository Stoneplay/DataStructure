#ifndef BinarySearchTree
#define BinarySearchTree

#include<iostream>
#include<stack>
#include<queue>
#include "TreeNode.h"

using namespace std;

template<typename EleType>
class BinSearchTree {
public:
	BinSearchTree();							// ���캯��
	BinSearchTree(EleType);						// ���ع��캯��
	~BinSearchTree();							// ��������
	bool Empty();								// �ж����Ƿ��
	int Size();									// ��ȡ���еĽڵ�����
	BinTreeNode<EleType>* Search(EleType);		// ����ĳ�ڵ�
	BinTreeNode<EleType>* Maximun();			// ��ȡ���ڵ�
	BinTreeNode<EleType>* Minimun();			// ��ȡ��С�ڵ�
	BinTreeNode<EleType>* Parent(EleType);		// ��ȡ���ڵ�
	void Insert(EleType);						// ����ڵ�
	void Delete(EleType);						// ɾ���ڵ�
	void PrintByPreOrder();						// ǰ�������ӡ���е����нڵ�
	void PrintByInOrder();						// ���������ӡ���е����нڵ�
	void PrintByPostOrder();					// ���������ӡ���е����нڵ�
	void PrintByLevelOrder();					// ��α�����ӡ���е����нڵ�

private:
	BinTreeNode<EleType> *root;	// ����
	int size;					// ���еĽڵ�����
};

/* ���ع��캯�� */
template<typename EleType>
BinSearchTree<EleType>::BinSearchTree(EleType value) {
	root = new BinTreeNode<EleType>(value);
	size = 1;
}

/* ���ع��캯�� */
template<typename EleType>
BinSearchTree<EleType>::BinSearchTree() {
	root = nullptr;
	size = 0;
}

/* �������� */
template<typename EleType>
BinSearchTree<EleType>::~BinSearchTree() {
	if (!Empty()) {
		queue<BinTreeNode<EleType>*> q;

		// ��α���ɾ��
		q.push(root);
		while (!q.empty()) {
			BinTreeNode<EleType> *t = q.front();
			q.pop();
			if (t->lchild) {
				q.push(t->lchild);
			}
			if (t->rchild) {
				q.push(t->rchild);
			}
			delete t;
		}
	}
}

/* �ж����Ƿ�� */
template<typename EleType>
bool BinSearchTree<EleType>::Empty() {
	return root == nullptr;
}

/* ��ȡ���еĽڵ����� */
template<typename EleType>
int BinSearchTree<EleType>::Size() {
	return size;
}

/* ����ĳ�ڵ� */
template<typename EleType>
BinTreeNode<EleType>* BinSearchTree<EleType>::Search(EleType value) {
	if (Empty()) return nullptr;

	BinTreeNode<EleType> *t = root;
	while (t) {
		if (t->data == value) {
			return t;
		}
		else if (t->data > value) {
			t = t->lchild;
		}
		else {
			t = t->rchild;
		}
	}

	return nullptr;
}

/* ��ȡ���ڵ� */
template<typename EleType>
BinTreeNode<EleType>* BinSearchTree<EleType>::Maximun() {
	if (Empty()) return nullptr;

	BinTreeNode<EleType> *t = root;
	while (t->rchild) {
		t = t->rchild;		// ���ڵ����������Ҳ�
	}
	return t;
}

/* ��ȡ��С�ڵ� */
template<typename EleType>
BinTreeNode<EleType>* BinSearchTree<EleType>::Minimun() {
	if (Empty()) return nullptr;

	BinTreeNode<EleType> *t = root;
	while (t->lchild) {
		t = t->lchild;		// ��С�ڵ������������
	}
	return t;
}

/* ��ȡ���ڵ� */
template<typename EleType>
BinTreeNode<EleType>* BinSearchTree<EleType>::Parent(EleType value) {
	if (Empty() || root->data == value) return nullptr;

	stack<BinTreeNode<EleType>*> s;
	BinTreeNode<EleType> *t = root;
	while (t || !s.empty()) {	// �����������
		if (t) {
			s.push(t);
			t = t->lchild;
		}
		else {
			t = s.top();
			s.pop();
			if ((t->lchild && t->lchild->data == value) || (t->rchild && t->rchild->data == value)) {
				return t;
			}
			t = t->rchild;
		}
	}
	return nullptr;
}

/* ����ڵ� */
template<typename EleType>
void BinSearchTree<EleType>::Insert(EleType value) {
	if (Empty()) {
		root = new BinTreeNode<EleType>(value);
	}
	else {
		BinTreeNode<EleType> *t = root;

		while (true) {
			if (t->data > value) {
				if (t->lchild) {
					t = t->lchild;
				}
				else {		// �����Ϊ�½ڵ�Ĳ���λ��
					t->lchild = new BinTreeNode<EleType>(value);
					break;
				}
			}
			else if (t->data < value) {
				if (t->rchild) {
					t = t->rchild;
				}
				else {		// ���Ҷ�Ϊ�½ڵ�Ĳ���λ��
					t->rchild = new BinTreeNode<EleType>(value);
					break;
				}
			}
			else {			// �ڵ��Ѵ���
				break;
			}
		}
	}
	size++;
}

/* ɾ���ڵ� */
template<typename EleType>
void BinSearchTree<EleType>::Delete(EleType value) {
	if (Empty()) return;

	// Ҫ����ɾ����������֪����ɾ���ڵ�ĸ��ڵ�
	BinTreeNode<EleType> *parent = Parent(value);
	if (parent == nullptr && value != root->data) {
		return;		// ��ɾ���ڵ㲻������
	}

	BinTreeNode<EleType> *cur = root;		// ��ɾ���ڵ�
	if (parent) {		// ɾ���������нڵ� 
		if (parent->lchild && parent->lchild->data == value) {
			cur = parent->lchild;
		}
		else {
			cur = parent->rchild;
		}
	}

	if (!cur->lchild || !cur->rchild) {		// ��ɾ���ڵ�����ֻ��һ�����ӽڵ�,��ֱ���øú��ӽڵ��滻��ɾ���ڵ�
		if (cur->lchild) {		// ֻ�������
			if (parent) {		
				if (cur == parent->lchild) {
					parent->lchild = cur->lchild;
				}
				else {
					parent->rchild = cur->lchild;
				}
			}
			delete cur;		// ���ڵ��ֱ��ɾ��
		}
		else {		// ֻ���Ҷ��ӻ���û�к���
			if (parent) {
				if (cur == parent->lchild) {
					parent->lchild = cur->rchild;
				}
				else {
					parent->rchild = cur->rchild;
				}
			}
			delete cur;
		}
	}
	else {	// ��ɾ���ڵ���������Ӿ�����,���������������ڵ�(����ֻ�������)����������������С�ڵ�(����ֻ���Ҷ���)�滻��ɾ���ڵ�
		BinTreeNode<EleType> *alter = cur->rchild;
		while (alter->lchild) {
			alter = alter->lchild;		// Ѱ�Ҵ�ɾ���ڵ�����������С�ڵ�
		}
		cur->data = alter->data;

		BinTreeNode<EleType> *alter_parent = cur->rchild;
		while (alter_parent->lchild->data != alter->data) {
			alter_parent = alter_parent->lchild;	// Ѱ�Ҵ�ʱ�Ĵ�ɾ���ڵ�ĸ��ڵ�
		}
		alter_parent->lchild = alter->rchild;	// ��ʱ�Ĵ�ɾ���ڵ�һ�����丸�ڵ�������,��������ֻ���Ҷ���
		delete alter;
	}
	size--;
}

/* ǰ�������ӡ */
template<typename EleType>
void BinSearchTree<EleType>::PrintByPreOrder() {
	if (root == nullptr) return;

	stack<BinTreeNode<EleType>*> s;
	BinTreeNode<EleType> *t = root;
	
	while (t || !s.empty()) {
		while (t) {
			cout << t->data << ' ';
			s.push(t);
			t = t->lchild;
		}

		if (!s.empty()) {
			t = s.top();
			s.pop();
			t = t->rchild;
		}
	}
	cout << endl;
}

/* ���������ӡ */
template<typename EleType>
void BinSearchTree<EleType>::PrintByInOrder() {
	if (root == nullptr) return;

	stack<BinTreeNode<EleType>*> s;
	BinTreeNode<EleType> *t = root;
	while (t || !s.empty()) {
		while (t) {
			s.push(t);
			t = t->lchild;	// �ҵ����е�����ڵ�
		}

		if (!s.empty()) {
			t = s.top();	
			s.pop();
			cout << t->data << ' ';
			t = t->rchild;
		}
	}
	cout << endl;
}

/* ���������ӡ */
template<typename EleType>
void BinSearchTree<EleType>::PrintByPostOrder() {
	if (root == nullptr) return;

	stack<BinTreeNode<EleType>*> s;
	BinTreeNode<EleType> *cur = root;		// ��ǰ���ʽڵ�
	BinTreeNode<EleType> *last = nullptr;	// �ϴη��ʵĽڵ�
	while (cur) {
		s.push(cur);
		cur = cur->lchild;
	}

	while (!s.empty()) {
		cur = s.top();
		s.pop();

		/* �ڵ㱻���ʵ�ǰ�����Ҷ���Ϊ�ջ��Ҷ��ӱ����ʹ� */
		if (!cur->rchild || cur->rchild == last) {	
			cout << cur->data << ' ';
			last = cur;
		}
		else {	// �����Ҷ�������һ�η��ʵ��������,�򱣴浱ǰ�ڵ�,�ȷ����Ҷ���
			s.push(cur);
			cur = cur->rchild;
			while (cur) {
				s.push(cur);
				cur = cur->lchild;	// ���������������
			}
		}
	}
	cout << endl;
}

/* ��α�����ӡ */
template<typename EleType>
void BinSearchTree<EleType>::PrintByLevelOrder() {
	if (root == nullptr) return;

	queue<BinTreeNode<EleType>*> q;
	q.push(root);
	while (!q.empty()) {
		BinTreeNode<EleType> *t = q.front();
		cout << t->data << ' ';
		q.pop();

		if (t->lchild) {
			q.push(t->lchild);
		}
		if (t->rchild) {
			q.push(t->rchild);
		}
	}
	cout << endl;
}

#endif // !BinarySearchTree

