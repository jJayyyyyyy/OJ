/*
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 * 进制转换
 * 同类题目 P168, P171
 * 
 * 
 * 关键: 本题的 [Z] 是一个带 进位(carry) 的 [0]
 * n--是精髓
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class Solution {
public:
	string convertToTitle(int n) {
		if( n <= 0 ){
			return "";
		}else{
			string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string ans;
			int r;
			while( n > 0 ){
				n--;	// 精髓
				r = n % 26;
				n /= 26;
				ans.push_back(s[r]);	
			}

			reverse(ans.begin(), ans.end());
			return ans;
		}
	}
};

// int main(){
// 	Solution s;

// 	cout<<s.convertToTitle(28)<<'\n';	// AB
// 	cout<<s.convertToTitle(26)<<'\n';	// Z, 而不是 AZ
// 	cout<<s.convertToTitle(52)<<'\n';	// AZ, 而不是 BZ

// 	return 0;
// }