/*
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 * 进制转换
 * 同类题目 P168, P171
 * 
 * 
 * 关键: pow
*/

// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <algorithm>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class Solution{
public:
	int titleToNumber(string s){
		reverse(s.begin(), s.end());
		int ans = 0;
		int len = s.size();
		int digit;
		for( int i = 0; i < len; i++ ){
			digit = s[i] - 'A' + 1;
			ans += digit * pow(26, i);
		}
		
		return ans;
	}
};

// int main(){
// 	Solution s;
// 	cout<<s.titleToNumber("A")<<'\n';	// 1
// 	cout<<s.titleToNumber("B")<<'\n';	// 2
// 	cout<<s.titleToNumber("Z")<<'\n';	// 26
// 	cout<<s.titleToNumber("AA")<<'\n';	// 27
// 	cout<<s.titleToNumber("AB")<<'\n';	// 28
// 	cout<<s.titleToNumber("ZY")<<'\n';	// 701
// 	return 0;
// }