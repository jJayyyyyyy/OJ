/*
 * https://leetcode.com/problems/implement-strstr/description/
 * 字符串匹配
 *
*/

// #include <iostream>
// #include <string>
// using namespace std;

// 这里用了最暴力的办法，逐个对比，每次回退, 缺点是慢
// 优化1, 外层for循环, 不必 [0, len1), 而是 [0, len1 - len2 + 1) 即可, 可以省去大量无效的比较
// 因为如果超过了右侧区间, 剩下的haystack长度就不够needle了
// 优化2, KMP
class Solution {
public:
	int strStr(string haystack, string needle) {
		int len1=haystack.size(), len2=needle.size();

		if( len2 == 0 ){
			return 0;
		}else if( len1 >= len2 ){
			for( int i = 0; i < len1; i++ ){
				bool isMatch = true;
				for( int j = 0; j < len2; j++ ){
					if( haystack[i + j] != needle[j] ){
						isMatch = false;
						break;
					}
					if( i + j == len1 ){
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
	
	// 优化1
	int strStr1(string haystack, string needle){
		int len1 = haystack.size(), len2 = needle.size();
		if( len2 == 0 ){
			return 0;
		}else if( len1 < len2 ){
			return -1;
		}else{
			for( int i = 0; i < len1 + 1 - len2; i++ ){
				int j = 0;
				for( j = 0; j < len2; j++ ){
					if( haystack[i + j] != needle[j] ){
						break;
					}
				}
				if( j == len2 ){
					return i;
				}
			}
			return -1;
		}
	}
	
	// TODO: KMP
	int strStrKMP(string haystack, string needle){
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

