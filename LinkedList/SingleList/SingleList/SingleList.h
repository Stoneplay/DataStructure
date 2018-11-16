#ifndef _SingleList_h
#define _SingleList_h

#include <iostream>

using namespace std;

class ListNode {
public:
	int value;
	ListNode *next;	
	ListNode(int val = -1): value(val), next(NULL) {}	//�ڵ��ֵĬ��Ϊ-1
};

ListNode *CreateHead();							//����һ������ı�ͷ
int Length(ListNode *head);						//��������ĳ���
bool Insert(ListNode *head, int val);			//������ĩβ��ӽڵ�
bool Insert(ListNode *head, int val, int k);	//���ڵ��������ĵ�k��λ��
ListNode *FindKth(ListNode *head, int k);		//���������еĵ�k���ڵ�
int Position(ListNode *head, int val);			//���ҽڵ��������е�λ��
bool Delete(ListNode *head, int val);			//ɾ��������ָ���Ľڵ�
bool DeleteKth(ListNode *head, int k);			//ɾ�������еĵ�k���ڵ�
void PrintList(ListNode *head);					//��ӡ���������нڵ����Ϣ

#endif // !_SingleList_h

