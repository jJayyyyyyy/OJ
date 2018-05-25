/*
 * https://leetcode.com/problems/length-of-last-word/description/
 * 可用Python描述题意如下
 * s = input().rstrip(' ')
 * s = s.split(' ')
 * res = len(s)
 * print(res)
 *
 * 初步想法是从前往后逐个数, 遇到空格重新计数
 * 但是这样比较费时, 因为前面的计数都是没用的, 更快的做法是, 从后向前数, 参考 sln_2
 *
*/

// #include <iostream>
// #include <string>
// using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int cnt = 0;
		char ch;
		bool hasSpace = false;
		for ( int i = 0; i < s.size(); i++ ) {
			ch = s[i];
			if( ch == ' ' ){
				hasSpace = true;
			}else{
				if( hasSpace ){
					cnt = 0;
					hasSpace = false;
				}
				cnt++;
			}
		}
		return cnt;
	}
	
	int sln_2(string s){
		int i = s.size() - 1;
		for ( ; i >= 0 ; i-- ){
			if( s[i] != ' ' ){
				break;
			}
		}

		int cnt = 0;
		char ch;
		for( ; i >= 0; i-- ){
			if( s[i] != ' ' ){
				cnt++;
			}else{
				break;
			}
		}
		return cnt;
	}
};

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;



// 	cout<<s.lengthOfLastWord("hello world")<<'\n';	// 5
// 	cout<<s.lengthOfLastWord("asd aa")<<'\n';	// 2
// 	cout<<s.lengthOfLastWord("")<<'\n';	// 0
// 	cout<<s.lengthOfLastWord(" ")<<'\n';	// 0
// 	cout<<s.lengthOfLastWord("a ")<<'\n';	// 1
// 	cout<<s.lengthOfLastWord("a   ")<<'\n';	// 1

// 	return 0;
// }