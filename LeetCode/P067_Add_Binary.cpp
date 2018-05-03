/*
 * https://leetcode.com/problems/add-binary/description/
 * 模拟二进制加法
 * 同类题目 P066, P067
 * 注意，输入可能是一个很长的整数序列
 * carry 进位标记
 * 
 * 字符串构造器, 前面补0
 * string s = string( len, '0' );
 * http://www.cplusplus.com/reference/string/string/string/
 * 
 * 子串
 * string s1 = s.substr(pos);
 * http://www.cplusplus.com/reference/string/string/substr/
*/

// #include <iostream>
// #include <string>
// using namespace std;


// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution {
public:
	string addBinary(string a, string b) {
		if( a == "0" && b == "0" ){
			return "0";
		}else{
			int len1 = a.size();
			int len2 = b.size();
			int len3;

			// 补0
			if( len1 > len2 ){
				len3 = len1 + 1;
				a = '0' + a;
				b = string( len3 - len2, '0' ) + b;
			}else{
				len3 = len2 + 1;
				a = string( len3 - len1, '0' ) + a;
				b = '0' + b;
			}

			int carry = 0;
			string ans = string(len3, '0');
			for( int i = len3 - 1; i >= 0; i-- ){
				if( carry == 1 ){
					if( a[i] == '1' && b[i] == '1' ){
						ans[i] = '1';
					}else if( a[i] == '1' && b[i] == '0' ){
						ans[i] = '0';
					}else if( a[i] == '0' && b[i] == '1' ){
						ans[i] = '0';
					}else if( a[i] == '0' && b[i] == '0' ){
						ans[i] = '1';
						carry = 0;
					}
				}else{
					if( a[i] == '1' && b[i] == '1' ){
						ans[i] = '0';
						carry = 1;
					}else if( a[i] == '1' && b[i] == '0' ){
						ans[i] = '1';
					}else if( a[i] == '0' && b[i] == '1' ){
						ans[i] = '1';
					}else if( a[i] == '0' && b[i] == '0' ){
						ans[i] = '0';
					}
				}
			}
			int pos;
			for( pos = 0; pos < len3; pos++ ){
				if( ans[pos] != '0' ){
					break;
				}
			}

			return ans.substr(pos);
		}
	}
};


// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;

// 	cout<<s.addBinary("11", "1")<<'\n';	// 100
// 	cout<<s.addBinary("1010", "1011")<<'\n';	// 10101
// 	cout<<s.addBinary("11", "001")<<'\n';	// 100
// 	cout<<s.addBinary("0", "0")<<'\n';	// 0
// 	cout<<s.addBinary("0", "1")<<'\n';	// 1

// 	return 0;
// }