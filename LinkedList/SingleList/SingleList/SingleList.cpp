#include "SingleList.h"
//对链表中的节点操作时，若涉及到待操作节点的前一个节点，则使用表头较为方便

/*生成一个链表的表头*/
ListNode *CreateHead() {
	ListNode *head = new ListNode;
	if (head) {
		return head;
	}
	else {
		cout << "Memory allocation fail!" << endl;
		return NULL;
	}
}

/*测量链表的长度*/
int Length(ListNode *head) {
	if (!head) {
		cout << "The list is empty!" << endl;
		return NULL;
	}

	ListNode *tmp = head->next;	//不计表头
	int count = 0;
	while (tmp) {
		count++;
		tmp = tmp->next;
	}
	return count;
}

/*在链表末尾添加节点*/
bool Insert(ListNode *head, int val) {
	if (!head) {
		cout << "The Linklist is NULL!";
		return false;
	}

	ListNode *tmp = head;
	while (tmp->next) {
		tmp = tmp->next;
	}
	ListNode *NewNode = new ListNode(val);
	tmp->next = NewNode;
	return true;
}

/*将节点插在链表的第k个位置*/
bool Insert(ListNode *head, int val, int k) {
	if (!head) {
		cout << "The linked list is empty!" << endl;
		return false;
	}
	if (k - 1 > Length(head) || k < 1) {
		return false;
	}

	ListNode *tmp = head;
	while (k-- != 1) {	
		tmp = tmp->next;
	}	//带表头操作，找到第k-1个节点
	ListNode *NewNode = new ListNode(val);
	NewNode->next = tmp->next;
	tmp->next = NewNode;
	return true;
}

/*查找链表中的第k个节点*/
ListNode *FindKth(ListNode *head, int k) {
	if (!head) {
		cout << "The linked list is empty!" << endl;
		return NULL;
	}
	if (k > Length(head) || k < 1) {
		return NULL;
	}

	ListNode *tmp = head->next;
	while (k-- != 1) {
		tmp = tmp->next;
	}

	ListNode *node = new ListNode;
	node = tmp;
	return node;
}

/*查找节点在链表中的位置*/
int Position(ListNode *head, int val) {
	if (!head) {
		cout << "The list is empty!" << endl;
		return 0;
	}

	int count = 1;
	ListNode *l = head->next;
	while (l) {
		count++;
		if (l->value == val) {
			return count - 1;
		}
		l = l->next;
	}
	return 0;	//在链表中未找到待查找节点
}

/*删除链表中指定的节点*/
bool Delete(ListNode *head, int val) {
	if (!head) {
		cout << "The list is empty!" << endl;
		return false;
	}

	ListNode *l = head;
	while (l->next) {
		if (l->next->value == val) {
			ListNode *tmp = l->next;
			l->next = tmp->next;
			delete tmp;
			return true;
		}
		l = l->next;
	}
	if (l->value == val) {	//待删除节点是链表的最后一个节点
		delete l;
		return true;
	}
	return false;	//在链表中未找到待删除节点
}

/*删除链表中的第k个节点*/
bool DeleteKth(ListNode *head, int k) {
	if (!head) {
		cout << "The linked list is empty!" << endl;
		return false;
	}
	if (k > Length(head) || k < 1) {
		return false;
	}

	ListNode *l = head;
	while (k-- != 1) {
		l = l->next;
	}
	if (l->next) {
		ListNode *tmp = l->next;	//此时，l->next为待删除节点
		l->next = tmp->next;
		delete tmp;
	}
	else {
		delete l;
	}

	return true;
}

/*打印链表中所有节点的信息*/
void PrintList(ListNode *head) {
	if (!head) {
		cout << "The list is empty!" << endl;
		return;
	}

	ListNode *l = head->next;
	while (l) {
		cout << l->value << " ";
		l = l->next;
	}
	cout << endl;
}

/*删除整个链表由析构函数完成*/