/*
https://leetcode.com/problems/subdomain-visit-count/description/
统计域名访问次数
同类题目 P811

参考思路
使用 unordered_map
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

const static auto c = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

class Solution {
public:
	int str2int(string s)
	{
		stringstream ss(s);
		int ans;
		ss >> ans;
		return ans;
	}

	vector<string> subdomainVisits(vector<string> & cpdomains) {
		unordered_map<string, int> domain_cnt;
		for( string item : cpdomains )
		{
			int space = item.find(' ');
			int cnt = str2int(item.substr(0, space));
			string domain = item.substr(space + 1);
			domain_cnt[domain] += cnt;
			int dot = domain.find('.');
			while( dot != string::npos )
			{
				domain = domain.substr(dot + 1);
				dot = domain.find('.');
				domain_cnt[domain] += cnt;
			}
		}
		vector<string> ans;
		for( auto item : domain_cnt )
		{
			string record = to_string(item.second) + " " + item.first;
			ans.push_back(record);
		}
		return ans;
	}
};

int main()
{
	Solution s;
	vector<string> cpdomains;
	// cpdomains.push_back("9001 discuss.leetcode.com");
	cpdomains.push_back("900 google.mail.com");
	cpdomains.push_back("50 yahoo.com");
	cpdomains.push_back("1 intel.mail.com");
	cpdomains.push_back("5 wiki.org");
	s.subdomainVisits(cpdomains);
	return 0;
}
