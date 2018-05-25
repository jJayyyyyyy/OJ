/*
 * https://leetcode.com/problems/add-two-numbers/description/
 * 给定两个倒序的链表，每一个结点表示一位数字。求其和，并用相同的链表形式(倒序)返回
*/
/*
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *tail = new ListNode(0);
		head = tail;
		int val = 0, carry = 0;
		while( l1 != NULL && l2 != NULL ){
			val = l1->val + l2->val + carry;
			carry = val / 10;
			val = val % 10;
			tail->next = new ListNode(val);
			tail = tail->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		while( l1 != NULL ){
			val = l1->val + carry;
			carry = val / 10;
			val = val % 10;
			tail->next = new ListNode(val);
			tail = tail->next;
			l1 = l1->next;
		}
		while( l2 != NULL ){
			val = l2->val + carry;
			carry = val / 10;
			val = val % 10;
			tail->next = new ListNode(val);
			tail = tail->next;
			l2 = l2->next;
		}
        if( carry != 0 ){
			tail->next = new ListNode(carry);
		}
		return head->next;
    }
};

/*
int main(){
	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	
	Solution s;
	ListNode *head = s.addTwoNumbers(l1, l2);
	while( head != NULL ){
		cout<<head->val;
		head = head->next;
	}
	return 0;
}
*/