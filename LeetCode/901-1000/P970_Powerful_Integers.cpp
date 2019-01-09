/*
https://leetcode.com/contest/weekly-contest-118/problems/powerful-integers/
输入 x, y, 还有一个上界 bound
对于 i, j = 0, 1, 2, ...
计算 sum = x^i + y^j
求所有可能的 sum, 其中 sum <= bound

注意:
1 <= x <= 100
1 <= y <= 100
0 <= bound <= 10^6

同类题目 P970

由于给定了边界, 我们可以简单计算一下最多可能的循环次数
2^20 = 1048576 > 10^6
所以二重循环的最大次数是内层 20 次, 外层 20 次
不过, 如果 x=100, y=100, 那么 100^20 + 100^20 会溢出 int
所以我们需要在循环直接插入一些 flag, 进行 early stop
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution{
public:
	vector<int> powerfulIntegers(int x, int y, int bound) {
		unordered_set<int> s;

		int sum = 0;
		bool changed = false;
		for( int i = 0; i <= 20; i++ ){
			changed = false;
			for( int j = 0; j <= 20; j++ ){
				sum = pow(x, i) + pow(y, j);
				if( sum <= bound ){
					s.insert(sum);
					changed = true;
				}else{
					break;
				}
			}
			if( changed == false ){
				break;
			}
		}

		vector<int> ans;
		for( int num : s ){
			ans.push_back(num);
		}
		return ans;
	}
};
