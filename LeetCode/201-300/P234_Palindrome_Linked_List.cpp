/*
https://leetcode.com/problems/palindrome-linked-list/description/
判断一个链表是否为回文序列
同类题目 P234
 
思考题: Could you do it in O(n) time and O(1) space?
参考: https://leetcode.com/problems/palindrome-linked-list/discuss/64500/11-lines-12-with-restore-O(n)-time-O(1)-space
思路:
1. Reverse the first half while finding the middle.
2. Compare the reversed first half with the second half.

*/

#include <iostream>
using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// O(n) time
// O(n) space
class Solution1{
public:
	bool isPalindrome(ListNode * head){
		vector<int> v;
		while( head != NULL ){
			v.push_back(head->val);
			head = head->next;
		}

		int len = v.size();
		for( int i = 0; i < len / 2; i++ ){
			if( v[i] != v[len-1-i] ){
				return false;
			}
		}

		return true;
	}
};

// O(n) time
// O(1) space
// 先将前半段逆转，再将前半段与后半段进行对比
class Solution2{
public:
	bool isPalindrome(ListNode * head){
		if( head == NULL || head->next == NULL ){
			return true;
		}

		int len = 0;
		ListNode * p = head;
		ListNode * q = head;
		ListNode * head2;

		// O(n)
		while( p != NULL ){
			len++;
			p = p->next;
			if( len % 2 == 0 ){
				q = q->next;
			}
		}
		if( len % 2 == 1 ){
			head2 = q->next;
		}else{
			head2 = q;
		}

		// O(n/2), 头插法, 将前 len/2 个数逆转
		ListNode * t = head->next;
		head->next = q;
		for( int i = 1; i < len / 2; i++ ){
			p = t->next;
			t->next = head;
			head = t;
			t = p;
		}

		// O(n/2) 前半段与后半段逐个对比
		for( int i = 0; i < len / 2; i++ ){
			if( head->val != head2->val ){
				return false;
			}
			head = head->next;
			head2 = head2->next;
		}

		return true;
	}
};