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

#define EmptyNode 0		// ����0��ʾ�ýڵ�Ϊ�սڵ�

int main() {

	/* ��ν��� */
	TreeNode *root1 = MakeTreeByLevelOrder();
	TraverseByLevelOrder(root1);

	vector<int> pre{ 1, 2, 4, 5, 3, 6, 7 };
	vector<int> in{ 4, 2, 5, 1, 6, 3, 7 };
	vector<int> post{ 4, 5, 2, 6, 7, 3, 1 };

	/* ���������� */
	TreeNode *root2 = MakeTreeByPreInOrder(pre, in);
	TraverseByLevelOrder(root2);

	/* ��������� */
	TreeNode *root3 = MakeTreeByInPostOrder(in, post);
	TraverseByLevelOrder(root3);
	cout << endl;

	/* �ݹ���� */
	TraverseByRecurPreOrder(root2);
	cout << endl;
	TraverseByRecurInOrder(root2);
	cout << endl;
	TraverseByRecurPostOrder(root2);
	cout << endl;

	/* �ǵݹ���� */
	cout << endl;
	TraverseByPreOrder(root2);
	TraverseByInOrder(root2);
	TraverseByPostOrder(root2);

	return 0;
}

/* ������н��� */
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

	TreeNode *root = new TreeNode(pre[PreStart]);		// �������еĵ�һ���ڵ��Ǹ��ڵ�
	int RootIndex = InStart;
	for (; RootIndex <= InEnd; RootIndex++) {
		if (in[RootIndex] == pre[PreStart]) break;		// �����������в��Ҹ��ڵ�
	}

	root->left = PreInOrder(pre, in, PreStart + 1, PreStart + RootIndex - InStart, InStart, RootIndex - 1);		// ������
	root->right = PreInOrder(pre, in, PreStart + RootIndex - InStart + 1, PreEnd, RootIndex + 1, InEnd);		// ������

	return root;
}

/* ������������н��� */
// ǰ��ĵ�һ�����������ĸ�, ���������б����������Ļ���
// ǰ�����������������ֵĵ�һ���ڵ����������ĸ��ڵ�, ���������ֵĵ�һ���ڵ����������ĸ��ڵ�
TreeNode* MakeTreeByPreInOrder(vector<int>& pre, vector<int>& in) {
	if (!pre.size() || !in.size() || pre.size() != in.size()) return NULL;

	return PreInOrder(pre, in, 0, pre.size() - 1, 0, in.size() - 1);
}

TreeNode* InPostOrder(vector<int>& in, vector<int>& post, int InStart, int InEnd, int PostStart, int PostEnd) {
	if (PostStart == PostEnd) return new TreeNode(post[PostEnd]);

	TreeNode *root = new TreeNode(post[PostEnd]);		// �������е����һ���ڵ��Ǹ��ڵ�
	int RootIndex = InStart;
	for (; RootIndex <= InEnd; RootIndex++) {
		if (in[RootIndex] == post[PostEnd]) break;		// �����������в��Ҹ��ڵ�
	}

	root->left = InPostOrder(in, post, InStart, RootIndex - 1, PostStart, PostStart + RootIndex - 1 - InStart);		// ������
	root->right = InPostOrder(in, post, RootIndex + 1, InEnd, PostStart + RootIndex - InStart, PostEnd - 1);	// ������

	return root;
}

/* ����ͺ������н��� */
// ��������һ�����������ĸ�, ���������б����������Ļ���
// �������������������ֵ����һ���ڵ����������ĸ��ڵ�, ���������ֵ����һ���ڵ����������ĸ��ڵ�
TreeNode* MakeTreeByInPostOrder(vector<int>& in, vector<int>& post) {
	if (!in.size() || !post.size() || in.size() != post.size()) return NULL;

	return InPostOrder(in, post, 0, in.size() - 1, 0, post.size() - 1);
}

/* ��α��� */
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

/* ��������ݹ�ʵ�� */
void TraverseByRecurPreOrder(TreeNode* root) {
	if (root) {
		cout << root->val << ' ';
		TraverseByRecurPreOrder(root->left);
		TraverseByRecurPreOrder(root->right);
	}
}

/* ��������ǵݹ�ʵ�� */
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

/* ��������ݹ�ʵ�� */
void TraverseByRecurInOrder(TreeNode* root) {
	if (root) {
		TraverseByRecurInOrder(root->left);
		cout << root->val << ' ';
		TraverseByRecurInOrder(root->right);
	}
}

/* ��������ǵݹ�ʵ�� */
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

/* ��������ݹ�ʵ�� */
void TraverseByRecurPostOrder(TreeNode* root) {
	if (root) {
		TraverseByRecurPostOrder(root->left);
		TraverseByRecurPostOrder(root->right);
		cout << root->val << ' ';
	}
}

/* ��������ǵݹ�ʵ�� */
void TraverseByPostOrder(TreeNode* root) {
	if (!root) return;

	stack<TreeNode*> s;
	TreeNode *last = NULL;

	while (root) {		// ����������׶�
		s.push(root);
		root = root->left;
	}

	while (!s.empty()) {
		root = s.top();
		s.pop();

		if (!root->right || root->right == last) {
			cout << root->val << ' ';	// �ڵ㱻���ʵ�ǰ�����Ҷ���Ϊ�ջ��Ҷ��ӱ����ʹ�
			last = root;
		}
		else {		// �����Ҷ�������һ�η��ʵ��������,�򱣴浱ǰ�ڵ�,�ȷ����Ҷ���
			s.push(root);
			root = root->right;
			while (root) {
				s.push(root);
				root = root->left;	// ���������������
			}
		}
	}
	cout << endl;
}