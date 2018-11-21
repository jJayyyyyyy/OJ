/*
https://leetcode.com/problems/linked-list-cycle-ii/description/
给定一个链表, 其中某一部分可能是循环链表, 如
A ---> B ---> C ---> D ---> E ---> C
求出循环链表的起点 ( 即上面例子的 C )
同类题目 P141, P142

参考思路
https://leetcode.com/problems/linked-list-cycle-ii/discuss/44793/O(n)-solution-by-using-two-pointers-without-change-anything
解释
1. 首先利用双指针法, 判断是否存在循环链表

2. 如果是循环链表, 那么令 fast = head, 然后 slow 和 fast 同步前进, 直到相遇, 相遇的地方就是循环链表的起点

*/

#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
	ListNode * detectCycle(ListNode * head) {
		if( head == NULL || head->next == NULL ){
			return NULL;
		}

		ListNode * slow = head;
		ListNode * fast = head;
		bool isCycle = false;

		while( slow != NULL && fast != NULL ){
			slow = slow->next;
			if( fast->next == NULL ){
				return NULL;
			}
			fast = fast->next->next;
			if( slow == fast ){
				isCycle = true;
				break;
			}
		}

		if( isCycle == false ){
			return NULL;
		}
		fast = head;
		while( slow != fast ){
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};
