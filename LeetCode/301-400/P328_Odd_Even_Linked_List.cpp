/*
https://leetcode.com/problems/odd-even-linked-list/description/
将链表的奇数号结点串在一起得到L1, 偶数号结点串在一起得到L2, 然后接在
同类题目 P328

参考思路:
https://leetcode.com/problems/odd-even-linked-list/solution/
*/

#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if( head == NULL || head->next == NULL ){
			return head;
		}

		ListNode * odd = head;
		ListNode * even = head->next;
		ListNode * evenHead = even;

		while( even != NULL && even->next != NULL ){
			odd->next = even->next;
			odd = odd->next;
			even->next = odd->next;
			even = even->next;
		}

		odd->next = evenHead;
		return head;
	}
};
