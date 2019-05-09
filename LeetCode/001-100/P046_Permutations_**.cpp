/*
https://leetcode.com/problems/permutations/description/
求全排列
同类题目 P078, P090, P046, P031, 20190508华为机考

参考思路:
找出 f(n-1) 和 f(n) 之间的关系

以 nums = [1, 2, 3] 为例
假设 f(n-1) 是 [ [1, 2], [2, 1] ], 也就是 [1, 2] 的全排列
那么 f(n) 就是在 f(n-1) 的基础上, 把 3 插入到每一个位置, 也就是说
[1, 2] 会分裂成
|--- [3, 1, 2]
|--- [1, 3, 2]
|--- [1, 2, 3]

而 [2, 1] 会分裂成
|--- [3, 2, 1]
|--- [2, 3, 1]
|--- [2, 1, 3]

因此可以得到 f(n) = [ [3, 1, 2], [1, 3, 2], [1, 2, 3], [3, 2, 1], [2, 3, 1], [2, 1, 3] ]
*/

#include <iostream>
#include <vector>
using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector< vector<int> > ans, tmpans;
		int len = nums.size();
		if( len > 1 ){
			ans.push_back(vector<int>(1, nums[0]));
			for( int i = 1; i < len; i++ ){
				int num = nums[i];
				for( vector<int> line : ans ){
					int len2 = line.size();
					for( int i = 0; i <= len2; i++ ){
						vector<int> tmpline = line;
						tmpline.insert(tmpline.begin() + i, num);
						tmpans.push_back(tmpline);
					}
				}
				ans = tmpans;
				tmpans.clear();
			}
		}
		return ans;
	}
};


// 使用 STL 的 next_permutation
// 首先对 nums 排序, 然后 do-while 调用 next_permutation()
class Solution2{
public:
	vector<vector<int>> permute(vector<int> & nums) {
		vector<vector<int>> anslist;
		sort(nums.begin(), nums.end());
		do{
			anslist.push_back(nums);
		}while(next_permutation(nums.begin(), nums.end()));

		return anslist;
	}
};

/*
关于下一个全排列 next_permutation()

实现思路分析
https://blog.csdn.net/QQ575787460/article/details/41215475
STL源码分析
https://www.cnblogs.com/eudiwffe/p/6260699.html

以 1 2 4 6 5 3 为例, 它的下一个全排列是 1 2 5 3 4 6

1. 下个全排列与当前序列有尽可能长的公共前缀, 因此从而往前找
2. 如果一个数列是递减的, 那么它没有下一个全排列

所以

[1 2] 4 [ 6 5 3]

从后往前 [6 5 3] 都是逆序的, 直到 [4 6] 才不是 逆序, 所以 4 是要被交换的元素

[1 2] 是公共前缀, 下面找 【4 6 5 3】的下一个全排列

4 要放到合适的位置, 4 > 3, 4 < 5

所以 4 和 5 交换, 得到 【5】 6 【4】 3

这样保证了 【5】 后面的序列【6 4 3】是逆序的

下一步, reverse([6, 4, 3]), 得到 【5 [3 4 6]】

拼接前缀, 得到 [1 2] 【5 3 4 6】

*/
bool next_permutation(int *begin, int *end){
	int *i = begin, *j, *k;
	if( i == end || ++i == end ){
		return 0;
	}
	for( i = end - 1; i != begin; ){
		j = i;
		i--;
		if( *i < *j ){
			k = end - 1;
			while( *i >= *k ){
				k--;
			}
			swap(*i, *k);
			reverse(j, end);
			return true;
		}
	}
	// 已经全部逆序, 没有下一个全排列了
	return false;
}


int main() {
	vector<int> nums(3);
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;

	Solution s;
	s.permute(nums);
	return 0;
}