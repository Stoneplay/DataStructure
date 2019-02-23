#ifndef UnionFind
#define UnionFind

#include<iostream>

using namespace std;

const int DefaultSize = 10;

/* ���νṹʵ�ֲ��鼯(���ཻ����ɭ��) */
// ÿ��������Ϊһ����,���е������ɭ��
// �����еĸ����Լ������ཻ
// ɭ���е����нڵ�������洢,�±�ΪԪ��,ֵΪ���ڵ�
// ÿ�����ĸ��ڵ��Ӧ��ֵΪ����,�Ҹø����ľ���ֵ��ʾ���ϵĴ�С(���ϵ���)
class UFSet {
public:
	UFSet(int sz = DefaultSize);	// ���캯��
	~UFSet();						// ��������
	int Find(int);					// ����ĳ��Ԫ�������ļ���
	void Union(int, int);			// �ϲ���������
	bool IsConnected(int, int);		// �ж���Ԫ���Ƿ�����ͬһ������
	int ElementsSize();				// ��ȡ����Ԫ�ص�����
	int SetsSize();					// ��ȡ���м��ϵ�����
	void PrintSet(int);				// ��ӡĳһ�ڵ����ڼ��ϵ�����Ԫ��
private:
	int *parent;	// parent[i]��ʾ�ڵ�i�ĸ��ڵ�,���ڵ�ĸ��ڵ�Ϊ����
	int *rank;		// �ڵ����,rank[i]��ʾ��iΪ���ڵ�����ĸ߶�;���ڷǸ��ڵ�,rank[i]��ʾ���i�߶ȵ��Ͻ�
	int size;		// ɭ�ֵĴ�С(���еĽڵ���)
};

/* ���캯�� */
UFSet::UFSet(int sz) {
	size = sz;
	parent = new int[size];
	rank = new int[size];
	for (int i = 0; i < size; i++) {
		parent[i] = i;		// ÿ��Ԫ���Գ�һ������
		rank[i] = 1;		// ÿ������ֻ��һ��Ԫ��,������Ϊ1
	}
}

/* �������� */
UFSet::~UFSet() {
	delete[] parent;
	delete[] rank;
}

/* ���������Ϻϲ� */
// Ϊ��ֹ���˻�����״,����·��ѹ��,�������·���ϵ�ÿ���ڵ㶼ֱ��ָ����ڵ�
// ��·��ѹ����Find�����ĵݹ�д��
int UFSet::Find(int element) {
	if (element < 0 || element >= size) {
		cout << "The element '" << element << "' isn't in the union_find_set !" << endl;
		return NULL;
	}

	if (parent[element] != element) {
		parent[element] = Find(parent[element]);	// �ݹ鷵��ʱ����ÿ��Ԫ�صĸ��ڵ�
	}
	return parent[element];
}

// �ǵݹ�д��
//int UFSet::Find(int element) {
//	int son = element;
//	while (parent[element] != element) {
//		element = parent[element];	// ���Ҹ��ڵ�
//	}
//	
//	// ��һ��whileѭ����elementΪ���ڵ�
//	while (son != element) {
//		int tmp = parent[son];
//		parent[son] = element;		// ����ǰ�ڵ����ӵ����ڵ�
//		son = tmp;
//	}
//
//	return element;
//}

/* ��С���Ϻϲ����󼯺��� */
void UFSet::Union(int a, int b) {
	int roota = Find(a);
	int rootb = Find(b);

	if (roota == rootb) {		// ����Ԫ��ͬ��һ������,����ϲ�
		return;
	}

	if (rank[roota] > rank[rootb]) {	// ����С�ļ��Ϻϲ����ȴ�ļ���
		parent[rootb] = roota;
	}
	else if(rank[roota] < rank[rootb]) {
		parent[roota] = rootb;			
	}
	else {	// ���ϵ������ʱ,������ϲ�,��Ҫά���ϲ���ļ��ϵ���
		parent[rootb] = roota;
		rank[roota]++;
	}
}

/* �ж���Ԫ���Ƿ�����ͬһ������ */
bool UFSet::IsConnected(int a, int b) {
	return Find(a) == Find(b);
}

/* ����Ԫ�ص�����(ɭ���еĽڵ���) */
int UFSet::ElementsSize() {
	return size;
}

/* ���м��ϵ�����(ɭ������������) */
int UFSet::SetsSize() {
	int sets = 0;
	
	for (int i = 0; i < size; i++) {
		if (parent[i] == i) {
			sets++;
		}
	}
	return sets;
}

/* ��ӡ��ĳһ�ڵ�Ϊ���ڵ�ļ��� */
void UFSet::PrintSet(int element) {
	if (element < 0 || element >= size) {
		cout << "The element '" << element << "' isn't in the union_find_set !" << endl;
		return;
	}

	int root = Find(element);
	cout << root << " : ";	// ��ӡ�ĵ�һ��Ԫ�ظ����ڵ�
	for (int i = 0; i < size; i++) {
		if (parent[i] == root) {
			cout << i << ' ';
		}
	}
	cout << endl;
}

#endif
