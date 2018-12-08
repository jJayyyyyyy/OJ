/*
https://leetcode.com/problems/leaf-similar-trees/description/
给一个正整数 N ，在二进制表示的 N 中，求相邻的两个 1 的最大间距
同类题目 P868
*/

#include <iostream>
using namespace std;

class Solution{
public:
	int binaryGap(int N) {
		int ans = 0, tmp = 0, cur = 1, left = 0, right = 0;
		bool firstOne = false;
		for( int i = 0; i < 32; i++ ){
			if( (N & cur) != 0 ){
				if( firstOne == false ){
					firstOne = true;
					left = right = i;
				}else{
					left = i;
					tmp = left - right;
					ans = max(ans, tmp);
					right = left;
				}
			}
			cur <<= 1;
		}

		return ans;
	}
};


int main(){
	Solution s;
	// 2
	cout<<s.binaryGap(22)<<'\n';
	// 2
	cout<<s.binaryGap(5)<<'\n';
	// 1
	cout<<s.binaryGap(6)<<'\n';
	// 0
	cout<<s.binaryGap(8)<<'\n';
	return 0;
}
