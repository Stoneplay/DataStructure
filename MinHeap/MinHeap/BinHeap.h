#ifndef BinHeap		// �����
#define BinHeap

#include<iostream>

using namespace std;

template<typename EleType>
class MinHeap {	
public:	
	MinHeap(const int cap = 10);			// �ѵ�Ĭ������Ϊ10
	MinHeap(const EleType*, const int);		// ��һ���������鹹��һ����С��
	~MinHeap();						// ��������
	EleType Minimun();				// ���Ҷ��е���Сֵ
	void Insert(const EleType);		// ����в���Ԫ��
	void Delete(const EleType);		// �Ӷ���ɾ��Ԫ��
	void Modify(const EleType, const EleType);	// ������Ԫ��src�޸�Ϊdst
	void Print();					// ��ӡ���е�����Ԫ��
private:
	EleType *heap;			// �洢����Ԫ�ص�����
	int size;				// ���е�ǰԪ�صĸ���
	int length;				// �ѵ����������������ĳ���
	void SiftUp(int);		// �Ե����ϵ�ά����С������,����Ԫ��ʱʹ��
	void SiftDown(int);		// �Զ����µ�ά����С������,ɾ��Ԫ��ʱʹ��
};

// ��ʹ���±��1��ʼ�����飬�����һ����ȫ���������У�
// leftchild(i) = 2 * i;
// rightchild(i) = 2 * i + 1;
// parent(i) = i / 2;(ʵ��������ȡ��)

/* Ĭ�Ϲ��캯�� */
template<typename EleType>
MinHeap<EleType>::MinHeap(const int cap) {
	length = cap;
	heap = new EleType[length + 1];		// �����±��1��ʼ
	size = 0;
}

/* �������� */
template<typename EleType>
MinHeap<EleType>::~MinHeap() {
	delete[] heap;
}

// ά����С������ʱ����������ά����������ά�����������𼶸��ǵķ�ʽ���ٶȱȽ��������ڵ��ֵҪ��

/* �Ե����ϵ�ά����С������ */
template<typename EleType>
void MinHeap<EleType>::SiftUp(int current) {
	if (current <= 1) return;		// ��ǰ�ڵ�û�и��ڵ�,�������

	EleType value = heap[current];	// ���ø��ǵķ�ʽ�ı�ڵ��ֵ�����ȱ��浱ǰ�ڵ��ֵ
	int parent = current / 2;		// ���ڵ��±�
	while (current > 1) {
		if (value >= heap[parent]) {
			break;					// �ӽڵ���ڸ��ڵ㣬�������	
		}
		else {
			heap[current] = heap[parent];	// �ӽڵ�С�ڸ��ڵ�,���ڵ��³�
			current = parent;				// �±����
			parent = current / 2;
		}
	}
	heap[current] = value;		// ��Ԥ�ȱ���Ľڵ�ֵ���뵽����
}

/* �Զ����µ�ά����С������ */
template<typename EleType>
void MinHeap<EleType>::SiftDown(int current) {
	int child = current * 2;		// ��ǰ�ڵ������
	if (child > size) return;		// ��ǰ�ڵ����ӽڵ�,����ά��

	EleType value = heap[current];	// ���浱ǰ�ڵ��ֵ
	while (child <= size) {
		if (child < size && heap[child] > heap[child + 1]) {
			child++;				// �ҵ���С�Ķ��ӽڵ�
		}
		if (value <= heap[child]) {	// ���ڵ�С�������ӽڵ㣬�������
			break;
		}
		else {
			heap[current] = heap[child];	// ���ڵ�����ӽڵ�,�ӽڵ��ϸ�
			current = child;	// �±����
			child = current * 2;
		}
	}
	heap[current] = value;		// ��Ԥ�ȱ���Ľڵ�ֵ���뵽����
}

/* ����в���Ԫ�� */
template<typename EleType>
void MinHeap<EleType>::Insert(const EleType value) {
	if (size == length) {
		cout << "The heap is full!" << endl;
		return;
	}

	heap[++size] = value;		// ����ֵ����ѵ�ĩβ,������size��ֵ
	SiftUp(size);				// �Ե�����ά����С������
}

/* �Ӷ���ɾ���ڵ� */
template<typename EleType>
void MinHeap<EleType>::Delete(const EleType value) {
	if (!size) {
		cout << "The heap is empty!" << endl;
		return;
	}

	int i = 1;
	while (i <=size && heap[i] != value) {	// Ѱ�Ҵ�ɾ���ڵ�
		i++;
	}
	if (i > size) {
		cout << "The '" << value << "' isn't in the heap!" << endl;
		return;
	}
	else {
		heap[i] = heap[size];	// ʹ�ö������һ���ڵ�����ɾ���ڵ�
		size--;					// ��SiftDown������,size�ǵ������յ�,��Ҫ�ڵ�����֮ǰ����size��ֵ
		SiftDown(i);			// �Զ����µ�ά����С������
	}
}

/* �޸Ķ���Ԫ�ص�ֵ */
template<typename EleType>
void MinHeap<EleType>::Modify(const EleType src, const EleType dst) {
	if (!size) {
		cout << "The heap is empty !" << endl;
		return;
	}
	
	int i = 1;
	while (heap[i] != src) {	// Ѱ�Ҵ��޸ĵĽڵ�
		i++;				
	}
	if (i > size) {	// δ�ҵ����޸Ľڵ�
		cout << "The '" << src << "' isn't in the heap !" << endl;
		return;
	}
	else {			// �ҵ����޸ĵĽڵ�
		heap[i] = dst;
		if (src > dst) {	// �ڵ��ֵ��С��������Ҫ�ϸ�
			SiftUp(i);
		}
		else {				// �ڵ��ֵ��󣬿�����Ҫ�³�
			SiftDown(i);
		}
	}
}

/* ���캯�� */
template<typename EleType>
MinHeap<EleType>::MinHeap(const EleType* p, const int len) {
	length = len * 2;	// Ĭ��Ԥ��һ���Ŀ��пռ�
	heap = new EleType[length + 1];

	/* �����һ�����ڵ㿪ʼ�����¶��ϵؽ�����С�ѣ����Ӷ�ΪO(n) */
	size = len;
	for (int i = 0; i < len; i++) {
		heap[i + 1] = p[i];				// �Ȱ�������˳��洢����
	}
	int LastParent = size / 2;		// �������һ�����ڵ���±�
	for (int i = LastParent; i >= 1; i--) {
		SiftDown(i);
	}
						
	/* ���뷨����,���Ӷ�ΪO(nlogn) */
	//size = 0;			// size��Insert�е���
	//for (int i = 0; i < len; i++) {
	//	Insert(p[i]);
	//}
}

/* ���Ҷѵ���С�ڵ� */
template<typename EleType>
EleType MinHeap<EleType>::Minimun() {
	if (!size) {
		cout << "The heap is empty!" << endl;
		return NULL;
	}
	else {
		return heap[1];		// �ѵ������±��1��ʼ
	}
}

/* ��ӡ�������нڵ��ֵ */
template<typename EleType>
void MinHeap<EleType>::Print() {
	if (!size) {
		cout << "The heap is empty!" << endl;
		return;
	}

	for (int i = 1; i <= size; i++) {
		cout << heap[i] << ' ';
	}
	cout << endl;
}

#endif