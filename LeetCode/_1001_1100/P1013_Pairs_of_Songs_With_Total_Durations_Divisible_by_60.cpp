/*
https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/discuss/260885/C++-6-lines-O(n)-target-sum
给定一个数组time_list, 一个 pair 定义为 (time_list[i] + time_list[j]) % 60 == 0, 其中 i < j, 统计有多少组这样的 pair
同类题目 P1013, P001

拿到题目的基本思路就是二重循环找出所有的pair, 不过提交代码过后发现超时了
瞥一眼 discussion, 发现原来是要用 P001_Two_Sum 的思路, 也就是用 hash 的方法, 保存已经出现过的 pair, 防止重复计算, O(n^2) 次取模 vs O(n) 次取模
本题还多了一层知识, 即取模运算的分配率

参考思路
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/discuss/256738/JavaC++Python-Two-Sum-with-K-60
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/discuss/256722/C++-5-lines-two-sum


*/

#include <iostream>
#include <vector>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution{
public:
	int numPairsDivisibleBy60(vector<int> & time_list) {
		// (a + b) % p == (a % p + b % p) % p
		// (a - b) % p == (a % p - b % p) % p
		// 所以, 若 (a + b) % 60 == 0 , 则 (a % 60 + b % 60) % 60 == 0
		// a % 60 + b % 60 = 60n
		// 我们把所有的数都映射到 [0, 59]
		// 找到 0 <= i, j <= 59, 其中 i = a % 60, j = b % 60, i + j = 60 或 0
		// j = (60 - i) % 60
		// 
		int cnt = 0;
		int table[60] = {0};
		for( int duration : time_list ){
			int i = duration % 60;
			int j = (60 - i) % 60;
			cnt += table[j];
			table[i]++;
		}
		return cnt;
	}
};


// 超时
class SolutionTimeLimitExceeded{
public:
	int numPairsDivisibleBy60(vector<int> & time_list) {
		int size = time_list.size();
		sort(time_list.begin(), time_list.end());
		int cnt = 0;
		for( int i = 0; i < size; i++ ){
			int p1 = time_list[i];
			for( int j = i + 1; j < size; j++ ){
				int p2 = time_list[j];
				if( (p1 + p2) % 60 == 0 ){
					cnt++;
				}
			}
		}
		return cnt;
	}
};
