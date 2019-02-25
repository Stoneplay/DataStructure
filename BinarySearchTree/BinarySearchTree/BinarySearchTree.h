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
	BinSearchTree();							// 构造函数
	BinSearchTree(EleType);						// 重载构造函数
	~BinSearchTree();							// 析构函数
	bool Empty();								// 判断树是否空
	int Size();									// 获取树中的节点总数
	BinTreeNode<EleType>* Search(EleType);		// 查找某节点
	BinTreeNode<EleType>* Maximun();			// 获取最大节点
	BinTreeNode<EleType>* Minimun();			// 获取最小节点
	BinTreeNode<EleType>* Parent(EleType);		// 获取父节点
	void Insert(EleType);						// 插入节点
	void Delete(EleType);						// 删除节点
	void PrintByPreOrder();						// 前序遍历打印树中的所有节点
	void PrintByInOrder();						// 中序遍历打印树中的所有节点
	void PrintByPostOrder();					// 后序遍历打印树中的所有节点
	void PrintByLevelOrder();					// 层次遍历打印树中的所有节点

private:
	BinTreeNode<EleType> *root;	// 树根
	int size;					// 树中的节点总数
};

/* 重载构造函数 */
template<typename EleType>
BinSearchTree<EleType>::BinSearchTree(EleType value) {
	root = new BinTreeNode<EleType>(value);
	size = 1;
}

/* 重载构造函数 */
template<typename EleType>
BinSearchTree<EleType>::BinSearchTree() {
	root = nullptr;
	size = 0;
}

/* 析构函数 */
template<typename EleType>
BinSearchTree<EleType>::~BinSearchTree() {
	if (!Empty()) {
		queue<BinTreeNode<EleType>*> q;

		// 层次遍历删除
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

/* 判断树是否空 */
template<typename EleType>
bool BinSearchTree<EleType>::Empty() {
	return root == nullptr;
}

/* 获取树中的节点总数 */
template<typename EleType>
int BinSearchTree<EleType>::Size() {
	return size;
}

/* 查找某节点 */
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

/* 获取最大节点 */
template<typename EleType>
BinTreeNode<EleType>* BinSearchTree<EleType>::Maximun() {
	if (Empty()) return nullptr;

	BinTreeNode<EleType> *t = root;
	while (t->rchild) {
		t = t->rchild;		// 最大节点在树的最右侧
	}
	return t;
}

/* 获取最小节点 */
template<typename EleType>
BinTreeNode<EleType>* BinSearchTree<EleType>::Minimun() {
	if (Empty()) return nullptr;

	BinTreeNode<EleType> *t = root;
	while (t->lchild) {
		t = t->lchild;		// 最小节点在树的最左侧
	}
	return t;
}

/* 获取父节点 */
template<typename EleType>
BinTreeNode<EleType>* BinSearchTree<EleType>::Parent(EleType value) {
	if (Empty() || root->data == value) return nullptr;

	stack<BinTreeNode<EleType>*> s;
	BinTreeNode<EleType> *t = root;
	while (t || !s.empty()) {	// 中序遍历查找
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

/* 插入节点 */
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
				else {		// 最左端为新节点的插入位置
					t->lchild = new BinTreeNode<EleType>(value);
					break;
				}
			}
			else if (t->data < value) {
				if (t->rchild) {
					t = t->rchild;
				}
				else {		// 最右端为新节点的插入位置
					t->rchild = new BinTreeNode<EleType>(value);
					break;
				}
			}
			else {			// 节点已存在
				break;
			}
		}
	}
	size++;
}

/* 删除节点 */
template<typename EleType>
void BinSearchTree<EleType>::Delete(EleType value) {
	if (Empty()) return;

	// 要进行删除操作必须知道待删除节点的父节点
	BinTreeNode<EleType> *parent = Parent(value);
	if (parent == nullptr && value != root->data) {
		return;		// 待删除节点不在树中
	}

	BinTreeNode<EleType> *cur = root;		// 待删除节点
	if (parent) {		// 删除的是树中节点 
		if (parent->lchild && parent->lchild->data == value) {
			cur = parent->lchild;
		}
		else {
			cur = parent->rchild;
		}
	}

	if (!cur->lchild || !cur->rchild) {		// 待删除节点至多只有一个孩子节点,则直接用该孩子节点替换待删除节点
		if (cur->lchild) {		// 只有左儿子
			if (parent) {		
				if (cur == parent->lchild) {
					parent->lchild = cur->lchild;
				}
				else {
					parent->rchild = cur->lchild;
				}
			}
			delete cur;		// 根节点可直接删除
		}
		else {		// 只有右儿子或者没有孩子
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
	else {	// 待删除节点的两个孩子均存在,则用左子树的最大节点(至多只有左儿子)或者用右子树的最小节点(至多只有右儿子)替换待删除节点
		BinTreeNode<EleType> *alter = cur->rchild;
		while (alter->lchild) {
			alter = alter->lchild;		// 寻找待删除节点右子树的最小节点
		}
		cur->data = alter->data;

		BinTreeNode<EleType> *alter_parent = cur->rchild;
		while (alter_parent->lchild->data != alter->data) {
			alter_parent = alter_parent->lchild;	// 寻找此时的待删除节点的父节点
		}
		alter_parent->lchild = alter->rchild;	// 此时的待删除节点一定是其父节点的左儿子,且其至多只有右儿子
		delete alter;
	}
	size--;
}

/* 前序遍历打印 */
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

/* 中序遍历打印 */
template<typename EleType>
void BinSearchTree<EleType>::PrintByInOrder() {
	if (root == nullptr) return;

	stack<BinTreeNode<EleType>*> s;
	BinTreeNode<EleType> *t = root;
	while (t || !s.empty()) {
		while (t) {
			s.push(t);
			t = t->lchild;	// 找到树中的最左节点
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

/* 后序遍历打印 */
template<typename EleType>
void BinSearchTree<EleType>::PrintByPostOrder() {
	if (root == nullptr) return;

	stack<BinTreeNode<EleType>*> s;
	BinTreeNode<EleType> *cur = root;		// 当前访问节点
	BinTreeNode<EleType> *last = nullptr;	// 上次访问的节点
	while (cur) {
		s.push(cur);
		cur = cur->lchild;
	}

	while (!s.empty()) {
		cur = s.top();
		s.pop();

		/* 节点被访问的前提是右儿子为空或右儿子被访问过 */
		if (!cur->rchild || cur->rchild == last) {	
			cout << cur->data << ' ';
			last = cur;
		}
		else {	// 存在右儿子且上一次访问的是左儿子,则保存当前节点,先访问右儿子
			s.push(cur);
			cur = cur->rchild;
			while (cur) {
				s.push(cur);
				cur = cur->lchild;	// 到右子树的最左端
			}
		}
	}
	cout << endl;
}

/* 层次遍历打印 */
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

