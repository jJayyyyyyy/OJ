/*
 * https://leetcode.com/problems/merge-two-sorted-lists/submissions/1
 * 指针形式的归并排序
 *
 * Example
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 *
 * 注意1: 指针可能为空
 * 注意2: 凡是指针, 一定记得初始化
*/

// #include <iostream>
// using namespace std;


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if( l1 == NULL && l2 == NULL ){
			return NULL;
		}else if( l1 == NULL ){
			return l2;
		}else if( l2 == NULL ){
			return l1;
		}else{
			// l1 != NULL && l2 != NULL
			ListNode *head = NULL;
			ListNode *p = NULL;

			if( l1->val < l2->val ){
				head = l1;
				l1 = l1->next;
			}else{
				head = l2;
				l2 = l2->next;
			}

			p = head;
			while( l1 && l2 ){
				if( l1->val < l2->val ){
					p->next = l1;
					l1 = l1->next;
				}else{
					p->next = l2;
					l2 = l2->next;
				}
				p = p->next;
			}

			while( l1 ){
				p->next = l1;
				l1 = l1->next;
				p = p->next;
			}

			while( l2 ){
				p->next = l2;
				l2 = l2->next;
				p = p->next;
			}

			return head;
		}
	}
};

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	/* case1 */
// 	ListNode *l1 = NULL, *l2 = NULL;


// 	/* case2
// 	ListNode *l1 = new ListNode(1);
// 	l1->next = new ListNode(2);
// 	l1->next->next = new ListNode(4);

// 	ListNode *l2 = new ListNode(1);
// 	l2->next = new ListNode(3);
// 	l2->next->next = new ListNode(4);
// 	/**/

// 	Solution s;
// 	ListNode *head = s.mergeTwoLists(l1, l2);

// 	while(head){
// 		cout<<head->val<<' ';
// 		head = head->next;
// 	}

// 	return 0;
// }
