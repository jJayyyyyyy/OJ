/*
https://leetcode-cn.com/classic/problems/two-sum/description/
在遍历的过程中, 查找另一个数是否出现过

*/

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

const static auto spd = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	ListNode * addTwoNumbers(ListNode * l1, ListNode * l2) {
		if( l1 == NULL && l2 == NULL )
		{
			return NULL;
		}
		else if( l1 == NULL )
		{
			return l2;
		}
		else if( l2 == NULL )
		{
			return l1;
		}
		else
		{
			ListNode *p1 = l1, *p2 = l2, *pre = l1;
			int carry = 0;
			while( p1 != NULL && p2 != NULL )
			{
				int sum = p1->val + p2->val + carry;
				if( sum >= 10 )
				{
					sum -= 10;
					carry = 1;
				}
				else
				{
					carry = 0;
				}
				p1->val = sum;
				pre = p1;
				p1 = p1->next;
				p2 = p2->next;
			}
			if( p1 == NULL )
			{
				p1 = pre;
				p1->next = p2;
				p1 = p2;
			}
			while( p1 != NULL )
			{
				int sum = p1->val + carry;
				if( sum >= 10 )
				{
					sum -= 10;
					carry = 1;
				}
				else
				{
					carry = 0;
				}
				p1->val = sum;
				pre = p1;
				p1 = p1->next;
			}
			if( carry == 1 )
			{
				p1 = pre;
				pre->next = new ListNode(1);
			}
			return l1;
		}
	}
};
