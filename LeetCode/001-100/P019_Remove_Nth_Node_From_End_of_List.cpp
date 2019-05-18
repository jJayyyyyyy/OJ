/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
去掉链表的倒数第 n 个结点

*/

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if( n == 0 || head == NULL ){
			return head;
		}

		ListNode *pre, *now, *post = head;
		while( n > 0 ){
			post = post->next;
			n--;
		}
		if( post == NULL ){
			return head->next;
		}

		pre = head;
		post = post->next;
		while( post != NULL ){
			post = post->next;
			pre = pre->next;
		}
		now = pre->next;
		pre->next = now->next;
		delete now;
		return head;
	}
};