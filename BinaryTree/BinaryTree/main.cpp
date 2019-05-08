#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* MakeTreeByLevelOrder();
TreeNode* MakeTreeByPreInOrder(vector<int>&, vector<int>&);
TreeNode* MakeTreeByInPostOrder(vector<int>&, vector<int>&);
void TraverseByRecurPreOrder(TreeNode*);
void TraverseByPreOrder(TreeNode*);
void TraverseByRecurInOrder(TreeNode*);
void TraverseByInOrder(TreeNode*);
void TraverseByRecurPostOrder(TreeNode*);
void TraverseByPostOrder(TreeNode*);
void TraverseByLevelOrder(TreeNode*);

#define EmptyNode 0		// 输入0表示该节点为空节点

int main() {

	/* 层次建树 */
	TreeNode *root1 = MakeTreeByLevelOrder();
	TraverseByLevelOrder(root1);

	vector<int> pre{ 1, 2, 4, 5, 3, 6, 7 };
	vector<int> in{ 4, 2, 5, 1, 6, 3, 7 };
	vector<int> post{ 4, 5, 2, 6, 7, 3, 1 };

	/* 先序中序建树 */
	TreeNode *root2 = MakeTreeByPreInOrder(pre, in);
	TraverseByLevelOrder(root2);

	/* 中序后序建树 */
	TreeNode *root3 = MakeTreeByInPostOrder(in, post);
	TraverseByLevelOrder(root3);
	cout << endl;

	/* 递归遍历 */
	TraverseByRecurPreOrder(root2);
	cout << endl;
	TraverseByRecurInOrder(root2);
	cout << endl;
	TraverseByRecurPostOrder(root2);
	cout << endl;

	/* 非递归遍历 */
	cout << endl;
	TraverseByPreOrder(root2);
	TraverseByInOrder(root2);
	TraverseByPostOrder(root2);

	return 0;
}

/* 层次序列建树 */
TreeNode* MakeTreeByLevelOrder() {
	int value;
	TreeNode *root = NULL;
	queue<TreeNode*> q;

	cin >> value;
	if (value) {
		root = new TreeNode(value);
		q.push(root);

		while (!q.empty()) {
			TreeNode *t = q.front();
			q.pop();

			cin >> value;
			if (value) {
				t->left = new TreeNode(value);
				q.push(t->left);
			}

			cin >> value;
			if (value) {
				t->right = new TreeNode(value);
				q.push(t->right);
			}
		}
	}
	return root;
}

TreeNode* PreInOrder(vector<int>& pre, vector<int>& in, int PreStart, int PreEnd, int InStart, int InEnd) {
	if (PreStart == PreEnd) return new TreeNode(pre[PreStart]);

	TreeNode *root = new TreeNode(pre[PreStart]);		// 先序序列的第一个节点是根节点
	int RootIndex = InStart;
	for (; RootIndex <= InEnd; RootIndex++) {
		if (in[RootIndex] == pre[PreStart]) break;		// 在中序序列中查找根节点
	}

	root->left = PreInOrder(pre, in, PreStart + 1, PreStart + RootIndex - InStart, InStart, RootIndex - 1);		// 左子树
	root->right = PreInOrder(pre, in, PreStart + RootIndex - InStart + 1, PreEnd, RootIndex + 1, InEnd);		// 右子树

	return root;
}

/* 先序和中序序列建树 */
// 前序的第一个是整个树的根, 中序用来判别左右子树的划分
// 前序序列中左子树部分的第一个节点是左子树的根节点, 右子树部分的第一个节点是右子树的根节点
TreeNode* MakeTreeByPreInOrder(vector<int>& pre, vector<int>& in) {
	if (!pre.size() || !in.size() || pre.size() != in.size()) return NULL;

	return PreInOrder(pre, in, 0, pre.size() - 1, 0, in.size() - 1);
}

TreeNode* InPostOrder(vector<int>& in, vector<int>& post, int InStart, int InEnd, int PostStart, int PostEnd) {
	if (PostStart == PostEnd) return new TreeNode(post[PostEnd]);

	TreeNode *root = new TreeNode(post[PostEnd]);		// 后序序列的最后一个节点是根节点
	int RootIndex = InStart;
	for (; RootIndex <= InEnd; RootIndex++) {
		if (in[RootIndex] == post[PostEnd]) break;		// 在中序序列中查找根节点
	}

	root->left = InPostOrder(in, post, InStart, RootIndex - 1, PostStart, PostStart + RootIndex - 1 - InStart);		// 左子树
	root->right = InPostOrder(in, post, RootIndex + 1, InEnd, PostStart + RootIndex - InStart, PostEnd - 1);	// 右子树

	return root;
}

/* 中序和后序序列建树 */
// 后序的最后一个是整个树的根, 中序用来判别左右子树的划分
// 后序序列中左子树部分的最后一个节点是左子树的根节点, 右子树部分的最后一个节点是右子树的根节点
TreeNode* MakeTreeByInPostOrder(vector<int>& in, vector<int>& post) {
	if (!in.size() || !post.size() || in.size() != post.size()) return NULL;

	return InPostOrder(in, post, 0, in.size() - 1, 0, post.size() - 1);
}

/* 层次遍历 */
void TraverseByLevelOrder(TreeNode* root) {
	if (!root) return;

	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode *t = q.front();
		q.pop();
		cout << t->val << ' ';

		if (t->left) q.push(t->left);
		if (t->right) q.push(t->right);
	}
	cout << endl;
}

/* 先序遍历递归实现 */
void TraverseByRecurPreOrder(TreeNode* root) {
	if (root) {
		cout << root->val << ' ';
		TraverseByRecurPreOrder(root->left);
		TraverseByRecurPreOrder(root->right);
	}
}

/* 先序遍历非递归实现 */
void TraverseByPreOrder(TreeNode* root) {
	if (!root) return;

	stack<TreeNode*> s;
	while (root) {
		cout << root->val << ' ';
		s.push(root);
		root = root->left;
	}

	while (!s.empty()) {
		root = s.top();
		s.pop();

		root = root->right;
		while (root) {
			cout << root->val << ' ';
			s.push(root);
			root = root->left;
		}
	}

	//stack<TreeNode*> s;
	//s.push(root);
	//while (!s.empty()) {
	//	root = s.top();
	//	s.pop();
	//	cout << root->val << ' ';

	//	if (root->right) s.push(root->right);
	//	if (root->left) s.push(root->left);
	//}

	cout << endl;
}

/* 中序遍历递归实现 */
void TraverseByRecurInOrder(TreeNode* root) {
	if (root) {
		TraverseByRecurInOrder(root->left);
		cout << root->val << ' ';
		TraverseByRecurInOrder(root->right);
	}
}

/* 中序遍历非递归实现 */
void TraverseByInOrder(TreeNode* root) {
	if (!root) return;

	stack<TreeNode*> s;
	while (root) {
		s.push(root);
		root = root->left;
	}

	while (!s.empty()) {
		root = s.top();
		s.pop();
		cout << root->val << ' ';

		root = root->right;
		while (root) {
			s.push(root);
			root = root->left;
		}
	}
	cout << endl;
}

/* 后序遍历递归实现 */
void TraverseByRecurPostOrder(TreeNode* root) {
	if (root) {
		TraverseByRecurPostOrder(root->left);
		TraverseByRecurPostOrder(root->right);
		cout << root->val << ' ';
	}
}

/* 后序遍历非递归实现 */
void TraverseByPostOrder(TreeNode* root) {
	if (!root) return;

	stack<TreeNode*> s;
	TreeNode *last = NULL;

	while (root) {		// 到左子树最底端
		s.push(root);
		root = root->left;
	}

	while (!s.empty()) {
		root = s.top();
		s.pop();

		if (!root->right || root->right == last) {
			cout << root->val << ' ';	// 节点被访问的前提是右儿子为空或右儿子被访问过
			last = root;
		}
		else {		// 存在右儿子且上一次访问的是左儿子,则保存当前节点,先访问右儿子
			s.push(root);
			root = root->right;
			while (root) {
				s.push(root);
				root = root->left;	// 到右子树的最左端
			}
		}
	}
	cout << endl;
}