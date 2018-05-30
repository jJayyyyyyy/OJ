/*
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 * 给定两个单链表, 找出其交汇点
 * 同类题目 P160
 * 
 * 
 * 思路: 先遍历链表得到 lenA, lenB, 假设 lenA > lenB
 * 然后, 先让 listA 走过 (lenA - lenB) 个结点, 这样, 两条链表剩下的长度就一样了
 * 最后, 逐个对比剩下的结点, 如果地址相同就是交汇点
 * 注意1: 值可能相同, 故应用地址相同来确定交汇点
 * 注意2: 单链表的定义, 只有一个后继结点, 也就是不用考虑【先交汇】---【再分开】---【再交汇】的情况
*/

// #include <iostream>
// using namespace std;

// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

// struct ListNode {
// 	int val;
// 	ListNode * next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if( headA == NULL || headB == NULL ){
			return NULL;
		}else{
			int lenA=0, lenB=0;
			ListNode *pa=headA, *pb=headB;
			while( pa != NULL ){
				pa = pa->next;
				lenA++;
			}
			while( pb != NULL ){
				pb = pb->next;
				lenB++;
			}
			int lenC, lenD;
			pa = headA;
			pb = headB;
			if( lenA > lenB ){
				lenC = lenA - lenB;
				lenD = lenB;
				for( int i = 0; i < lenC; i++ ){
					pa = pa->next;
				}
			}else{
				lenC = lenB - lenA;
				lenD = lenA;
				for( int i = 0; i < lenC; i++ ){
					pb = pb->next;
				}
			}
			for( int i = 0; i < lenD; i++ ){
				if( pa == pb ){
					return pa;
				}
				pa = pa->next;
				pb = pb->next;
			}
			return NULL;
		}
	}
};
