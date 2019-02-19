/*
https://leetcode.com/problems/house-robber/description/
动态规划(本题应该属于Medium, 只是因为有大牛给出了非常nice的Solution，所以正确率很高，被归入Easy)
同类题目 P198

参考解法1: https://leetcode.com/problems/house-robber/discuss/55693/C-1ms-O(1)space-very-simple-solution
参考解法2: https://leetcode.com/problems/house-robber/discuss/55736/C++My-solutionDP

先说解法2
f[i] 表示，到 i 为止，可以获得的最大收益
也就是说，假设nums[0] = 9, nums[1] = 1;
那么 f[1] = 9, 而不是 1

i 之前的全部状态，全部保存在 f[i] 身上了

至于更新 f[i] 的问题, 就是
f[i] = max(f[i-2] + nums[i], f[i - 1])


再回到解法1
相当于解法2的简化版，用 a(even), b(odd) 来代替 f[i] 了
a 表示到 i 为止, 可以获得的最大收益, i % 2 == 0
b 表示到 i 为止, 可以获得的最大收益, i % 2 == 1



dp的问题得多练练，说不定什么时候就遇到了
*/

#include <iostream>
#include <vector>
using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class Solution{
public:
	int rob(vector<int> & nums){
		int a = 0;
		int b = 0;
		for( int i = 0; i < nums.size(); i++ ){
			if( i % 2 == 0 ){
				a = max(a + nums[i], b);
			}else{
				b = max(a, b + nums[i]);
			}
		}
		return max(a, b);
	}
};

class Solution2{
public:
	int rob(vector<int> & nums)
	{
		int len = nums.size();
		if( len == 0 )
		{
			return 0;
		}
		else if( len == 1 )
		{
			return nums[0];
		}
		else if( len == 2 )
		{
			return max( nums[0], nums[1] );
		}
		else
		{
			vector<int> f(len, 0);
			f[0] = nums[0];
			f[1] = max( nums[0], nums[1] );
			for( int i = 2; i < len; i++ )
			{
				f[i] = max( f[i - 2] + nums[i], f[i - 1] );
			}
			return f[len - 1];
		}
	}
};
