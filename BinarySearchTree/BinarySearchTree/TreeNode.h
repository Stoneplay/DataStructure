#ifndef TreeNode
#define TreeNode

template<typename EleType>
class BinTreeNode {
public:
	EleType data;
	BinTreeNode<EleType> *lchild;
	BinTreeNode<EleType> *rchild;

	BinTreeNode();
	BinTreeNode(EleType value, BinTreeNode<EleType> *l = nullptr, BinTreeNode<EleType> *r = nullptr);
};

template<typename EleType>
BinTreeNode<EleType>::BinTreeNode() {
	data = 0;
	lchild = nullptr;
	rchild = nullptr;
}

template<typename EleType>
BinTreeNode<EleType>::BinTreeNode(EleType value, BinTreeNode<EleType> *l, BinTreeNode<EleType> *r) {
	data = value;
	lchild = l;
	rchild = r;
}


#endif // !TreeNode

