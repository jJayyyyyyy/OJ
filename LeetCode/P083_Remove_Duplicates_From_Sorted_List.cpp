/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 * 去掉值为有序表中重复的元素
 * 本题的输入是链表, P026的输入是数组
*/

// #include <iostream>
// using namespace std;

// struct ListNode{
// 	int val;
// 	ListNode *next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };


class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if( head == NULL ){
			return NULL;
		}else{
			ListNode *p1 = head;
			ListNode *p2 = head;
			while( p2 != NULL ){
				if( p1->val != p2->val ){
					p1->next = p2;
					p1 = p1->next;
				}
				p2 = p2->next;
			}
			p1->next = NULL;
			return head;
		}
	}
};

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;
// 	ListNode *head = new ListNode(1);
// 	head->next = new ListNode(1);
// 	head->next->next = new ListNode(2);
// 	head->next->next->next = new ListNode(3);
// 	head->next->next->next->next = new ListNode(3);
// 	ListNode *p = s.deleteDuplicates(head);

// 	while( p != NULL ){
// 		cout<<p->val<<' ';
// 		p = p->next;
// 	}

// 	cout<<'\n';
// 	return 0;
// }
