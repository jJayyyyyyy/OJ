/*
https://leetcode.com/problems/degree-of-an-array/description/
题目有点绕。我们根据样例来解析

Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.


一个数组 nums
其中出现次数最高的数字是 x (x 可能有多种取值，比如样例中的 x 可以取 1 或者 2)
x 的出现次数为 n (样例中 n = 2, 即 1 和 2 都出现了 2 次)
则 nums 的 degree 为 n


对于某个 x, 如 x1 = 1, 现在我们要找到这么一个最短的连续的子数组 subnums1, 它包含了所有的 x1, 记 len1 = subnums1.size()
则 subnums1 = [1, 2, 2, 3, 1], len1 = 5

对于 x2 = 2, subnums2 = [2, 2], len2 = 2

我们的目标就是要找到最短的 len = subnums.size()

同类题目 P697

参考思路
https://leetcode.com/problems/degree-of-an-array/solution/

遍历 nums, 对于其中的每一个元素 e，先统计其出现次数，并记录其第一次出现的下标 left[e] 和最后一次出现的下标 right[e], 这样，len = right[e] - left[e] + 1
第一次遍历之后，我们可以遍历 cntDegree 得到 maxDegree = max(cntDegree[i])
再遍历 cntDegree, 对于 degree = cntDegree[x] = maxDegree 的 x, 计算 len = right[x] - left[x] + 1, 求出最小的 len 即可
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int findShortestSubArray(vector<int> & nums) {
		unordered_map<int, int> left, right, cntDegree;
		int len = nums.size();
		for( int i = 0; i < len; i++ ){
			int x = nums[i];
			if( cntDegree.find(x) == cntDegree.end() ){
				cntDegree[x] = 0;
			}else{
				cntDegree[x]++;
			}
			
			if( left.find(x) == left.end() ){
				left[x] = i;
			}
			right[x] = i;
		}

		int maxDegree = 0;
		for( auto it = cntDegree.begin(); it != cntDegree.end(); it++ ){
			int degree = it->second;
			if( degree > maxDegree ){
				maxDegree = degree;
			}
		}

		int anslen = len;
		for( auto it = cntDegree.begin(); it != cntDegree.end(); it++ ){
			int x = it->first;
			int degree = it->second;
			if( degree == maxDegree ){
				int tmplen = right[x] - left[x] + 1;
				if( tmplen < anslen ){
					anslen = tmplen;
				}
			}
		}
		return anslen;
	}
};
