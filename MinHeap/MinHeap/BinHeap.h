#ifndef BinHeap		// 二叉堆
#define BinHeap

#include<iostream>

using namespace std;

template<typename EleType>
class MinHeap {	
public:	
	MinHeap(const int cap = 10);			// 堆的默认容量为10
	MinHeap(const EleType*, const int);		// 以一个无序数组构造一个最小堆
	~MinHeap();						// 析构函数
	EleType Minimun();				// 查找堆中的最小值
	void Insert(const EleType);		// 向堆中插入元素
	void Delete(const EleType);		// 从堆中删除元素
	void Modify(const EleType, const EleType);	// 将堆中元素src修改为dst
	void Print();					// 打印堆中的所有元素
private:
	EleType *heap;			// 存储堆中元素的数组
	int size;				// 堆中当前元素的个数
	int length;				// 堆的最大容量，即数组的长度
	void SiftUp(int);		// 自底向上地维护最小堆性质,插入元素时使用
	void SiftDown(int);		// 自顶向下的维护最小堆性质,删除元素时使用
};

// 堆使用下标从1开始的数组，则对于一棵完全二叉树，有：
// leftchild(i) = 2 * i;
// rightchild(i) = 2 * i + 1;
// parent(i) = i / 2;(实际是向下取整)

/* 默认构造函数 */
template<typename EleType>
MinHeap<EleType>::MinHeap(const int cap) {
	length = cap;
	heap = new EleType[length + 1];		// 数组下标从1开始
	size = 0;
}

/* 析构函数 */
template<typename EleType>
MinHeap<EleType>::~MinHeap() {
	delete[] heap;
}

// 维护最小堆性质时，无论向上维护还是向下维护，均采样逐级覆盖的方式，速度比交换两个节点的值要快

/* 自底向上地维护最小堆性质 */
template<typename EleType>
void MinHeap<EleType>::SiftUp(int current) {
	if (current <= 1) return;		// 当前节点没有父节点,无需调整

	EleType value = heap[current];	// 采用覆盖的方式改变节点的值，需先保存当前节点的值
	int parent = current / 2;		// 父节点下标
	while (current > 1) {
		if (value >= heap[parent]) {
			break;					// 子节点大于父节点，无需调整	
		}
		else {
			heap[current] = heap[parent];	// 子节点小于父节点,父节点下沉
			current = parent;				// 下标更新
			parent = current / 2;
		}
	}
	heap[current] = value;		// 将预先保存的节点值插入到堆中
}

/* 自顶向下地维护最小堆性质 */
template<typename EleType>
void MinHeap<EleType>::SiftDown(int current) {
	int child = current * 2;		// 当前节点的左孩子
	if (child > size) return;		// 当前节点无子节点,无需维护

	EleType value = heap[current];	// 保存当前节点的值
	while (child <= size) {
		if (child < size && heap[child] > heap[child + 1]) {
			child++;				// 找到较小的儿子节点
		}
		if (value <= heap[child]) {	// 父节点小于两个子节点，无需调整
			break;
		}
		else {
			heap[current] = heap[child];	// 父节点大于子节点,子节点上浮
			current = child;	// 下标更新
			child = current * 2;
		}
	}
	heap[current] = value;		// 将预先保存的节点值插入到堆中
}

/* 向堆中插入元素 */
template<typename EleType>
void MinHeap<EleType>::Insert(const EleType value) {
	if (size == length) {
		cout << "The heap is full!" << endl;
		return;
	}

	heap[++size] = value;		// 将新值插入堆的末尾,并更新size的值
	SiftUp(size);				// 自底向上维护最小堆性质
}

/* 从堆中删除节点 */
template<typename EleType>
void MinHeap<EleType>::Delete(const EleType value) {
	if (!size) {
		cout << "The heap is empty!" << endl;
		return;
	}

	int i = 1;
	while (i <=size && heap[i] != value) {	// 寻找待删除节点
		i++;
	}
	if (i > size) {
		cout << "The '" << value << "' isn't in the heap!" << endl;
		return;
	}
	else {
		heap[i] = heap[size];	// 使用堆中最后一个节点代替待删除节点
		size--;					// 在SiftDown函数中,size是调整的终点,故要在调整堆之前更新size的值
		SiftDown(i);			// 自顶向下地维护最小堆性质
	}
}

/* 修改堆中元素的值 */
template<typename EleType>
void MinHeap<EleType>::Modify(const EleType src, const EleType dst) {
	if (!size) {
		cout << "The heap is empty !" << endl;
		return;
	}
	
	int i = 1;
	while (heap[i] != src) {	// 寻找待修改的节点
		i++;				
	}
	if (i > size) {	// 未找到待修改节点
		cout << "The '" << src << "' isn't in the heap !" << endl;
		return;
	}
	else {			// 找到待修改的节点
		heap[i] = dst;
		if (src > dst) {	// 节点的值变小，可能需要上浮
			SiftUp(i);
		}
		else {				// 节点的值变大，可能需要下沉
			SiftDown(i);
		}
	}
}

/* 构造函数 */
template<typename EleType>
MinHeap<EleType>::MinHeap(const EleType* p, const int len) {
	length = len * 2;	// 默认预留一倍的空闲空间
	heap = new EleType[length + 1];

	/* 从最后一个父节点开始，自下而上地建立最小堆，复杂度为O(n) */
	size = len;
	for (int i = 0; i < len; i++) {
		heap[i + 1] = p[i];				// 先按照输入顺序存储数据
	}
	int LastParent = size / 2;		// 堆中最后一个父节点地下标
	for (int i = LastParent; i >= 1; i--) {
		SiftDown(i);
	}
						
	/* 插入法建堆,复杂度为O(nlogn) */
	//size = 0;			// size在Insert中调整
	//for (int i = 0; i < len; i++) {
	//	Insert(p[i]);
	//}
}

/* 查找堆的最小节点 */
template<typename EleType>
EleType MinHeap<EleType>::Minimun() {
	if (!size) {
		cout << "The heap is empty!" << endl;
		return NULL;
	}
	else {
		return heap[1];		// 堆的数组下标从1开始
	}
}

/* 打印堆中所有节点的值 */
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