/*
 * https://leetcode.com/problems/implement-strstr/description/
 * 字符串匹配
 *
*/

// #include <iostream>
// #include <string>
// using namespace std;

// 这里用了最暴力的办法，逐个对比，每次回退, 缺点是慢
// 还有很大的优化空间, 比如用KMP
class Solution {
public:
	int strStr(string haystack, string needle) {
		int len1=haystack.size(), len2=needle.size();

		if( len2 == 0 ){
			return 0;
		}else if( len1 >= len2 ){
			for( int i = 0; i < len1; i++ ){
				bool isMatch = true;
				int k = i;
				for( int j = 0; j < len2; ){
					if( haystack[k] != needle[j] ){
						isMatch = false;
						break;
					}
					k++;
					j++;
					if( k == len1 ){
						if( j != len2 ){
							isMatch = false;
						}
						break;
					}
				}
				if( isMatch ){
					return i;
				}
			}
			return -1;
		}else{
			return -1;
		}
	}
	
	// TODO: KMP
	int strStrKMP(string haystack, string, needle){
		return 0;
	}
};


// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	Solution s;
// 	cout<<s.strStr("hello", "")<<'\n';
// 	cout<<s.strStr("hello", "ll")<<'\n';
// 	cout<<s.strStr("aaaaa", "bba")<<'\n';
// 	cout<<s.strStr("hello", "llaaaaaaaaa")<<'\n';
// 	cout<<s.strStr("hello", "hell")<<'\n';
// 	cout<<s.strStr("hello", "lloo")<<'\n';
// 	return 0;
// }

