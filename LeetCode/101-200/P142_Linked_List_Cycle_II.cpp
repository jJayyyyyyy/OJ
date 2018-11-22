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

3. 证明:

A ---> B ---> C ---> D ---> E
              ↑             |
              |             |
              ·-------------·


|-------- k ---------|
              |----- r -----|
|----- s -----|
              |   m  |  r-m |

假设 slow 走了 k 步之后和 fast 相遇(即上图中的 D ), 那么 fast 走了 2k 步
假设 循环链表的长度为 r, fast 在循环链表里面走了 n 圈, 那么 2k - k = k = n·r
假设 head 到循环链表开头的长度为 s, 即 A->C 的距离为 s, 那么 k = nr = s + m
即 s = k - m
即 s = (n-1)r + (r-m)
左边就是 A 到 C 的距离, 右边就是 slow 在循环链表里面还要再走的距离
考虑到 (n-1)r % r = 0
所以右边相当于还要再走 r-m

所以这个等式 s = r - m 的意义就是
fast = head;
while( slow != fast ){
	slow = slow->next;
	fast = fast->next;
}
return slow;

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
