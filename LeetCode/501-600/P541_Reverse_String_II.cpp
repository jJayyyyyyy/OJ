/*
https://leetcode.com/problems/reverse-string-ii/description/
分段逆转字符串
同类题目 P541

TODO:
reverse() 的实现, 源码

Where are the headers of the C++ standard library
https://stackoverflow.com/questions/11457670/where-are-the-headers-of-the-c-standard-library
/usr/include/c++/4.8.4/bits

linux下C include搜索的路径
https://blog.csdn.net/farmwang/article/details/72781817

*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution{
public:
	string reverseStr(string s, int k) {
		int len = (int) s.size();
		string::iterator it = s.begin();
		int k2 = k * 2;
		int loop = len / k2;
		int remain = len % k2;
		for( int i = 0; i < loop; i++ ){
			reverse( it, it + k );
			it += k2;
		}
		
		if( remain < k ){
			reverse(it, it + remain);
		}else if( remain < k2 ){
			reverse(it, it + k);
		}
		return s;
	}
};

/*
abcdefg, k=2, [ba] cd [fe] g
 
abcdefgh, k=3, [cba] def [hg]

abcdefghi, k=3, [cba] def [ihg]
*/

int main(){
	Solution s;
	
	cout<<s.reverseStr("abcdefg", 2)<<'\n';
	cout<<s.reverseStr("abcdefgh", 3)<<'\n';
	cout<<s.reverseStr("abcdefghi", 3)<<'\n';

	return 0;
}

