/*
 * https://leetcode.com/problems/reverse-linked-list/description/
 * 逆转链表
 * 同类题目 P206
 * 
 * 本题采用【头插法】 逆转链表, 也可以用 【栈】 或者其他解法
*/

// #include <iostream>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if( head == NULL || head->next == NULL ){
			return head;
		}

		ListNode * p = head->next;
		ListNode * q = head;
		ListNode * r;
		while( p != NULL ) {
			r = p->next;
			p->next = q;
			q = p;
			p = r;
		}
		head->next = NULL;
		head = q;
		return head;
	}
};

int main(){
	Solution s;

	ListNode * head = NULL;
	s.reverseList(head);

	head = new ListNode(1);
	s.reverseList(head);

	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	s.reverseList(head);

	return 0;
}