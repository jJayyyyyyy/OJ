/*
 * https://leetcode.com/problems/plus-one/description/
 * 模拟加法
 * 同类题目 P066, P067
 * 注意，输入可能是一个很长的整数序列
 * 所以先【数组--->整数】，然后【整数--->数组】的做法是不合适的
*/

// #include <iostream>
// #include <vector>
// using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();
		int carry = 1;
		for( int i = len - 1; i >= 0; i-- ){
			digits[i] += carry;
			if( digits[i] == 10 ){
				carry = 1;
				digits[i] = 0;
			}else{
				carry = 0;
			}
		}
		if( carry == 1 ){
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};

/* test cases
 * 123
 * 999
 * 989
 * */
// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	Solution s;
// 	vector<int> digits;
// 	digits.push_back(9);
// 	digits.push_back(8);
// 	digits.push_back(9);
// 	digits = s.plusOne(digits);

// 	for( auto i : digits ){
// 		cout<<i<<' ';
// 	}

// 	cout<<'\n';
// 	return 0;
// }