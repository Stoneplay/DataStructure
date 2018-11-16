#include "SingleList.h"
//�������еĽڵ����ʱ�����漰���������ڵ��ǰһ���ڵ㣬��ʹ�ñ�ͷ��Ϊ����

/*����һ������ı�ͷ*/
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

/*��������ĳ���*/
int Length(ListNode *head) {
	if (!head) {
		cout << "The list is empty!" << endl;
		return NULL;
	}

	ListNode *tmp = head->next;	//���Ʊ�ͷ
	int count = 0;
	while (tmp) {
		count++;
		tmp = tmp->next;
	}
	return count;
}

/*������ĩβ��ӽڵ�*/
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

/*���ڵ��������ĵ�k��λ��*/
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
	}	//����ͷ�������ҵ���k-1���ڵ�
	ListNode *NewNode = new ListNode(val);
	NewNode->next = tmp->next;
	tmp->next = NewNode;
	return true;
}

/*���������еĵ�k���ڵ�*/
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

/*���ҽڵ��������е�λ��*/
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
	return 0;	//��������δ�ҵ������ҽڵ�
}

/*ɾ��������ָ���Ľڵ�*/
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
	if (l->value == val) {	//��ɾ���ڵ�����������һ���ڵ�
		delete l;
		return true;
	}
	return false;	//��������δ�ҵ���ɾ���ڵ�
}

/*ɾ�������еĵ�k���ڵ�*/
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
		ListNode *tmp = l->next;	//��ʱ��l->nextΪ��ɾ���ڵ�
		l->next = tmp->next;
		delete tmp;
	}
	else {
		delete l;
	}

	return true;
}

/*��ӡ���������нڵ����Ϣ*/
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

/*ɾ�����������������������*/