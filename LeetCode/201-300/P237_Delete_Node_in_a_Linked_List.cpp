/*
https://leetcode.com/problems/valid-anagram/description/
仅给定将要删除的结点，将其从链表中删除
同类题目 P237

思路
一般来说，如果要删除链表中的某个结点, 是给定 (head, valToDelete)
通过 pre, now, post三个指针我们可以删除 now

但是本题仅给出了要删除的结点的指针，即没有pre
那么我们可以 node->val = node->next->val;
直到 node 是倒数第 2 个结点，然后 node->next = NULL, delete(node->next)
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

class Solution{
public:
	void deleteNode(ListNode * node) {
		while( node != NULL && node->next != NULL ){
			node->val = node->next->val;
			ListNode * now = node;
			node = node->next;
			if( node->next == NULL ){
				now->next = NULL;
				node = NULL;
				delete node;
			}
		}
	}
};

int main(){
	Solution s;
	ListNode * head = new ListNode(4);
	head->next = new ListNode(5);
	head->next->next = new ListNode(1);
	head->next->next->next = new ListNode(9);
	s.deleteNode(head->next);
	return 0;
}
