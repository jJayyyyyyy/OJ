/*
https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
分段逆转字符串
同类题目 P557

TODO:
reverse() 的实现, 源码
stringstream 类的源码


Where are the headers of the C++ standard library
https://stackoverflow.com/questions/11457670/where-are-the-headers-of-the-c-standard-library
/usr/include/c++/4.8.4/bits

linux下C include搜索的路径
https://blog.csdn.net/farmwang/article/details/72781817

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution{
public:
	string reverseWords(string s) {
		stringstream ss(s);
		string part;
		string ans = "";
		while( getline(ss, part, ' ') ){
			reverse(part.begin(), part.end());
			ans += part + ' ';
		}
		ans.pop_back();
		return ans;
	}
};