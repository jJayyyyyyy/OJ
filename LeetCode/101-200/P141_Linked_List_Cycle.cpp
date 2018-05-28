/*
 * https://leetcode.com/problems/linked-list-cycle/description/
 * 给定一个链表, 问这个链表是不是循环链表
 * 同类题目 P141
 * 
 * 注意, 结点的值可能相同, 因此判端是否为同一结点, 应该用 if( p == q ) 而非 if( p->val == q->val )
 * 方法1: 使用 set<ListNode *> s, 注意不能是 set<int> s
 * 方法2: 双指针, slow 每次走1步, fast 每次走2步, 如果有循环, 那么两个指针终会相遇, 如果没有循环, 那么 fast 先到终点
 * 同样的, 判断相遇的方法是, if( fast == slow ) 而非 if( fast->val == slow->val )
*/

// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

// struct TreeNode{
// 	int val;
// 	TreeNode *left, *right;
// 	TreeNode(int x) : val(x), left(NULL), right(NULL){}
// };

// struct ListNode {
// 	int val;
// 	ListNode *next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

class Solution1 {
public:
	bool hasCycle(ListNode *head) {
		set<ListNode *> s;
		ListNode * p = head;
		while( p != NULL ){
			if( s.find(p) == s.end() ){
				s.insert(p);
				p = p->next;
			}else{
				return true;
			}
		}
		return false;
	}
};

class Solution2 {
public:
	bool hasCycle(ListNode *head) {
		if( head == NULL || head->next == NULL ){
			return false;
		}

		ListNode * slow = head;
		ListNode * fast = head->next;
		while( fast->next != NULL && fast->next->next != NULL ){
			slow = slow->next;
			fast = fast->next->next;
			if( slow == fast ){
				return true;
			}
		}
		return false;
	}
};
