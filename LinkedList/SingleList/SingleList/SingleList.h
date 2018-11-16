#ifndef _SingleList_h
#define _SingleList_h

#include <iostream>

using namespace std;

class ListNode {
public:
	int value;
	ListNode *next;	
	ListNode(int val = -1): value(val), next(NULL) {}	//节点的值默认为-1
};

ListNode *CreateHead();							//生成一个链表的表头
int Length(ListNode *head);						//测量链表的长度
bool Insert(ListNode *head, int val);			//在链表末尾添加节点
bool Insert(ListNode *head, int val, int k);	//将节点插在链表的第k个位置
ListNode *FindKth(ListNode *head, int k);		//查找链表中的第k个节点
int Position(ListNode *head, int val);			//查找节点在链表中的位置
bool Delete(ListNode *head, int val);			//删除链表中指定的节点
bool DeleteKth(ListNode *head, int k);			//删除链表中的第k个节点
void PrintList(ListNode *head);					//打印链表中所有节点的信息

#endif // !_SingleList_h

