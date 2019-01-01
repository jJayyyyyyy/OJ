/*
https://leetcode.com/problems/unique-email-addresses/description/
根据 email 的规则, 对 email list 进行筛选, 还原成最简形式, 找出有多少个不重复的 最简 email
同类题目 P929
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	int numUniqueEmails(vector<string> & emails){
		set<string> cntEmail;
		for( string email : emails ){
			string tmpEmail;
			bool plus = false;
			int len = email.size();
			for( int i = 0; i < len; i++ ){
				char ch = email[i];
				if( ch == '+' ){
					plus = true;
				}else if( ch == '@' ){
					tmpEmail += email.substr(i);
					break;
				}else if( plus == false && ch >= 'a' && ch <= 'z' ){
					tmpEmail += ch;
				}
			}
			cntEmail.insert(tmpEmail);
		}
		return cntEmail.size();
	}
};
