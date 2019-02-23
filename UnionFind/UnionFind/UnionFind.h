#ifndef UnionFind
#define UnionFind

#include<iostream>

using namespace std;

const int DefaultSize = 10;

/* 树形结构实现并查集(不相交集合森林) */
// 每个集合视为一棵树,所有的树组成森林
// 集合中的各个自己互不相交
// 森林中的所有节点用数组存储,下标为元素,值为父节点
// 每棵树的根节点对应的值为负数,且该负数的绝对值表示集合的大小(集合的秩)
class UFSet {
public:
	UFSet(int sz = DefaultSize);	// 构造函数
	~UFSet();						// 析构函数
	int Find(int);					// 查找某个元素所属的集合
	void Union(int, int);			// 合并两个集合
	bool IsConnected(int, int);		// 判断两元素是否属于同一个集合
	int ElementsSize();				// 获取所有元素的数量
	int SetsSize();					// 获取所有集合的数量
	void PrintSet(int);				// 打印某一节点所在集合的所有元素
private:
	int *parent;	// parent[i]表示节点i的父节点,根节点的父节点为自身
	int *rank;		// 节点的秩,rank[i]表示以i为根节点的树的高度;对于非根节点,rank[i]表示结点i高度的上界
	int size;		// 森林的大小(所有的节点数)
};

/* 构造函数 */
UFSet::UFSet(int sz) {
	size = sz;
	parent = new int[size];
	rank = new int[size];
	for (int i = 0; i < size; i++) {
		parent[i] = i;		// 每个元素自成一个集合
		rank[i] = 1;		// 每个集合只有一个元素,故树高为1
	}
}

/* 析构函数 */
UFSet::~UFSet() {
	delete[] parent;
	delete[] rank;
}

/* 将两个集合合并 */
// 为防止树退化成链状,采用路径压缩,即令查找路径上的每个节点都直接指向根节点
// 带路径压缩的Find函数的递归写法
int UFSet::Find(int element) {
	if (element < 0 || element >= size) {
		cout << "The element '" << element << "' isn't in the union_find_set !" << endl;
		return NULL;
	}

	if (parent[element] != element) {
		parent[element] = Find(parent[element]);	// 递归返回时更新每个元素的父节点
	}
	return parent[element];
}

// 非递归写法
//int UFSet::Find(int element) {
//	int son = element;
//	while (parent[element] != element) {
//		element = parent[element];	// 查找根节点
//	}
//	
//	// 第一个while循环后element为根节点
//	while (son != element) {
//		int tmp = parent[son];
//		parent[son] = element;		// 将当前节点连接到根节点
//		son = tmp;
//	}
//
//	return element;
//}

/* 将小集合合并到大集合中 */
void UFSet::Union(int a, int b) {
	int roota = Find(a);
	int rootb = Find(b);

	if (roota == rootb) {		// 两个元素同属一个集合,无需合并
		return;
	}

	if (rank[roota] > rank[rootb]) {	// 将秩小的集合合并到秩大的集合
		parent[rootb] = roota;
	}
	else if(rank[roota] < rank[rootb]) {
		parent[roota] = rootb;			
	}
	else {	// 集合的秩相等时,可任意合并,但要维护合并后的集合的秩
		parent[rootb] = roota;
		rank[roota]++;
	}
}

/* 判断两元素是否属于同一个集合 */
bool UFSet::IsConnected(int a, int b) {
	return Find(a) == Find(b);
}

/* 所有元素的数量(森林中的节点数) */
int UFSet::ElementsSize() {
	return size;
}

/* 所有集合的数量(森林中树的数量) */
int UFSet::SetsSize() {
	int sets = 0;
	
	for (int i = 0; i < size; i++) {
		if (parent[i] == i) {
			sets++;
		}
	}
	return sets;
}

/* 打印以某一节点为根节点的集合 */
void UFSet::PrintSet(int element) {
	if (element < 0 || element >= size) {
		cout << "The element '" << element << "' isn't in the union_find_set !" << endl;
		return;
	}

	int root = Find(element);
	cout << root << " : ";	// 打印的第一个元素跟根节点
	for (int i = 0; i < size; i++) {
		if (parent[i] == root) {
			cout << i << ' ';
		}
	}
	cout << endl;
}

#endif
