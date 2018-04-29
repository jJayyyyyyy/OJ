/* https://leetcode.com/problems/roman-to-integer/description/
 * 末尾增加一个'#'作为结束符, 方便统一处理
 * 可以作为前缀的字母: C, X, I
 * C 的后缀只能是 M, D
 * X 的后缀只能是 C, L
 * I 的后缀只能是 X, V
 *
 * */

// #include <iostream>
// #include <string>
// using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		s += '#';
		int len = s.size();
		int cnt = 0;
		for( int i = 0; i < len; i++ )
		{
			if( s[i] == 'M' )
			{
				cnt += 1000;
			}

			else if( s[i] == 'D' )
			{
				cnt += 500;
			}

			else if( s[i] == 'C' )
			{
				if( s[i+1] == 'M' )
				{
					cnt += 900;
					i++;
				}
				else if( s[i+1] == 'D' )
				{
					cnt += 400;
					i++;
				}
				else
				{
					cnt += 100;
				}
			}

			else if( s[i] == 'L' )
			{
				cnt += 50;
			}

			else if( s[i] == 'X' )
			{
				if( s[i+1] == 'C' )
				{
					cnt += 90;
					i++;
				}
				else if( s[i+1] == 'L' )
				{
					cnt += 40;
					i++;
				}
				else
				{
					cnt += 10;
				}
			}

			else if( s[i] == 'V' )
			{
				cnt += 5;
			}

			else if( s[i] == 'I' )
			{
				if( s[i+1] == 'X' )
				{
					cnt += 9;
					i++;
				}
				else if( s[i+1] == 'V' )
				{
					cnt += 4;
					i++;
				}
				else
				{
					cnt += 1;
				}
			}
		}

		return cnt;
	}
};

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;

// 	// case 1 ---> 3
// 	cout<<s.romanToInt("III")<<'\n';

// 	// case 2 ---> 4
// 	cout<<s.romanToInt("IV")<<'\n';

// 	// case 3 ---> 9
// 	cout<<s.romanToInt("IX")<<'\n';

// 	// case 4 ---> 58
// 	cout<<s.romanToInt("LVIII")<<'\n';

// 	// case 5 ---> 1994
// 	cout<<s.romanToInt("MCMXCIV")<<'\n';
// 	return 0;
// }
