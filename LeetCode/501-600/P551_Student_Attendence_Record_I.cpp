/*
https://leetcode.com/problems/student-attendance-record-i/description/
没搞明白题目的逻辑
同类题目 P551

参考:
https://leetcode.com/problems/student-attendance-record-i/discuss/101556/C++-very-simple-solution

*/

#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	bool checkRecord(string s) {
		int a=0, l=0;
		for(int i=0;i<s.size();i++) {
			if(s[i]=='A'){
				a++;
			}
			
			if(s[i]=='L'){
				l++;
			}else{
				l=0;
			}
			
			if( a >= 2 || l > 2 ){
				return false;
			}
		}
		return true;
	}
};
