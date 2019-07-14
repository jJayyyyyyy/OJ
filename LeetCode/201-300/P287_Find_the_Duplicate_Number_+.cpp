/*
https://leetcode.com/problems/find-the-duplicate-number/description/
找到重复的数字
同类题目 P287, P142

参考思路
https://leetcode.com/problems/find-the-duplicate-number/solution/

把问题转化为双指针找循环链表入口的问题, 即
https://github.com/jJayyyyyyy/OJ/blob/5ba5fc9534445121e44c1569e7a8fe99b6ab997f/LeetCode/101-200/P142_Linked_List_Cycle_II.cpp

栗子
假设 nums[] = {1, 4, 6, 5, 6, 2, 3}, 即
index: 0 1 2 3 4 5 6
value: 1 4 6 5 6 2 3

从 index = 0 开始, 以 value = nums[index] 作为下标, nextval = nums[value], 可以得到这样的序列

1 --- 4 --- 6 --- 3 --- 5 --- 2 --- 6
				  |_________________|

也即

1 --- 4 --- 6 --- 3 --- 5 --- 2
			|_________________|

这样, 问题便转换成了 LeetCode_P142_Linked_List_Cycle_II,
https://github.com/jJayyyyyyy/OJ/blob/master/LeetCode/101-200/P142_Linked_List_Cycle_II.cpp

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findDuplicate(vector<int> & nums) {
		// len = n + 1
		// 1 <= nums[i] <= n
		int head = nums[0];
		int slow = nums[head];
		int fast = nums[ nums[head] ];
		while( slow != fast )
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		// fast == slow
		fast = head;
		while( slow != fast )
		{
			slow = nums[slow];
			fast = nums[fast];
		}

		return slow;
	}
};

int main()
{
	Solution s;
	vector<int> v(5);
	v[0] = 1;
	v[1] = 3;
	v[2] = 4;
	v[3] = 2;
	v[4] = 2;
	s.findDuplicate(v);


	return 0;
}