/*
https://leetcode.com/problems/middle-of-the-linked-list/description/
找出链表的中间结点
同类题目 P876

双指针法
*/


#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *left, *right;
	ListNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	ListNode * middleNode(ListNode * head){
		if( head == NULL || head->next == NULL ){
			return head;
		}

		ListNode *slow=head, *fast=head;
		while( fast != NULL && fast->next != NULL ){
			slow = slow->next;
			fast = fast->next->next;
		}

		return slow;
	}
};
