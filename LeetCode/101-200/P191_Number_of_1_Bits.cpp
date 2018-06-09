/*
 * https://leetcode.com/problems/number-of-1-bits/description/
 * 给定一个32位无符号数, 对其进行二进制意义上的 1 的个数
 * 同类题目 P190, P191
 * 
*/

// #include <iostream>
// #include <vector>
// #define uint32_t unsigned int
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int cnt = 0;
		for ( int i = 0; i < 32; i++ ) {
			if ( n & 0x00000001 ) {
				cnt++;
			}
			n = n >> 1;
		}
		return cnt;
	}
};


int main(){
	Solution s;
	cout<<s.hammingWeight(11)<<'\n';
	cout<<s.hammingWeight(128)<<'\n';

	return 0;
}
