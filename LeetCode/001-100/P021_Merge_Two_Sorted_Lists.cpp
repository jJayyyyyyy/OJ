/*
https://leetcode.com/problems/merge-two-sorted-lists/
指针形式的归并排序
同类题目
P021, P023

注意1: 指针可能为空
注意2: 凡是指针, 一定记得初始化

参考思路
https://leetcode.com/problems/merge-two-sorted-lists/discuss/9714/14-line-clean-C++-Solution
先设置一个 dummyhead, 把 l1 或 l2 为空的情况合并成一种
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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode dummyhead(INT_MIN);
		ListNode * tail = & dummyhead;

		while( l1 != NULL && l2 != NULL ) {
			if( l1->val < l2->val ){
				tail->next = l1;
				l1 = l1->next;
			} else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}

		if( l1 != NULL ){
			tail->next = l1;
		}
		else{
			tail->next = l2;
		}
		tail->next = l1 ? l1 : l2;
		return dummyhead.next;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	/* case1 */
	ListNode *l1 = NULL, *l2 = NULL;


	/* case2
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);

	ListNode *l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);
	/**/

	Solution s;
	ListNode *head = s.mergeTwoLists(l1, l2);

	while(head){
		cout<<head->val<<' ';
		head = head->next;
	}

	return 0;
}
