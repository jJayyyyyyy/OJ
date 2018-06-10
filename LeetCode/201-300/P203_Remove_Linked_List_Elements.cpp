/*
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 * 给定 val, 删掉链表中与 val 值相同的结点
 * 同类题目 P203
 * 
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
	ListNode* removeElements(ListNode* head, int val) {
		while( head != NULL && head->val == val ){
			// delete head;
			head = head->next;
		}

		ListNode *pre=head, *now=head;

		while( now != NULL ){
			if( now->val == val ){
				pre->next = now->next;
				// delete now;
				now = now->next;
			}else{
				pre = now;
				now = now->next;
			}
		}

		return head;
	}
};


// int main(){
// 	Solution s;

// 	ListNode * head = NULL;

// 	s.removeElements(head, 6);
// 	cout<<'\n';

// 	head = new ListNode(6);
// 	s.removeElements(head, 6);
// 	cout<<'\n';

// 	head = new ListNode(1);
// 	head->next = new ListNode(2);
// 	head->next->next = new ListNode(6);

// 	s.removeElements(head, 6);
// 	cout<<'\n';

// 	head->next->next = new ListNode(6);
// 	head->next->next->next = new ListNode(3);
// 	head->next->next->next->next = new ListNode(4);
// 	head->next->next->next->next->next = new ListNode(5);
// 	head->next->next->next->next->next->next = new ListNode(6);

// 	s.removeElements(head, 6);
// 	cout<<'\n';

// 	return 0;
// }