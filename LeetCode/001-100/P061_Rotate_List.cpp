/*
 * https://leetcode.com/problems/rotate-list/description/
 * 对一个链表进行循环右移
 * 同类题目 P189, P61
 * 
 * 注意各种边界输入
*/

// #include <iostream>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

// struct ListNode {
// 	int val;
// 	ListNode *next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
	ListNode * rotateRight(ListNode * head, int k) {
		if( head == NULL || head->next == NULL ){
			return head;
		}

		int len = 0;
		ListNode *p = head;
		while( p != NULL ){
			len++;
			p = p->next;
		}

		if( k % len == 0 ){
			return head;
		}

		p = head;
		int cntNow = len - k % len;
		int cntPre = cntNow - 1;
		ListNode *now = head;
		
		for( int i = 0; i < cntPre; i++ ){
			p = p->next;
		}
		now = p->next;

		p->next = NULL;
		p = now;
		while( p->next != NULL ){
			p = p->next;
		}

		p->next = head;
		return now;
	}
};

/* test cases
 * [1], 1
 * [1], 0
 * [1, 2], 2
 * [1], 99
**/
