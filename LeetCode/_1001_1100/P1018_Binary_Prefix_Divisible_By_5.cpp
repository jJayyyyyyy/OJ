/*
https://leetcode.com/problems/binary-prefix-divisible-by-5/description/
一个数组, 元素是 0 或 1, 从左向右, 判断组成的二进制数能否被 5 整除
同类题目 P1018

参考思路
https://leetcode.com/problems/binary-prefix-divisible-by-5/discuss/265541/C++-4-lines
*/

#include <iostream>
#include <vector>
using namespace std;

const static auto c = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}();

class Solution{
public:
	vector<bool> prefixesDivBy5(vector<int>& A) {
		vector<bool> ans;
		int residue = 0;
		for( int a : A ){
			residue = ( (residue << 1) + a ) % 5;
			ans.push_back( residue == 0 );
		}
		return ans;
	}
};