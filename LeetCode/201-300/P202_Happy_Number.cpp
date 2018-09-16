/*
https://leetcode.com/problems/happy-number/description/
对num的各位数字求平方和sum, 新的sum赋值给num, 不断地重复这个过程, 如果最终能得到1, 那么num是一个 happy number
同类题目 P202

思路
关键点是使用一个 set 存储已经出现过的结果, 若新的 sum 已经存在于 set, 说明此路不同(无线循环)

*/

#include <iostream>
#include <cmath>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class Solution{
public:
	bool isHappy(int n){
		if( n == 1 ){
			return true;
		}
		
		string num = to_string(n);
		unordered_set<int> s;
		s.insert(n);
		while(true){
			int sum = 0;
			for( char digit : num ){
				sum += pow(digit-'0', 2);
			}
			if( sum == 1 ){
				return true;
			}else{
				if( s.find(sum) != s.end() ){
					break;
				}else{
					s.insert(sum);
					num = to_string(sum);
				}
			}
		}
		return false;
	}
};

int main(){
	Solution s;
	
	cout<<s.isHappy(19)<<'\n';
	return 0;
}
