/*
https://leetcode.com/problems/uncommon-words-from-two-sentences/description/
有两个字符串 A 和 B ，找到其中的 word，这个 word 在 A 或 B 中只出现一次
同类题目 P884
*/


#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;


/*
参考思路1:
https://leetcode.com/problems/uncommon-words-from-two-sentences/solution/
遍历两个字符串，统计只出现一次的 word 即可
而不是像我一样，傻乎乎的先去A里面找只出现一次的wor的，再去B里面找只出现一次的word (而且我的思路是错的 T_T)
*/
class Solution1{
public:
	vector<string> uncommonFromSentences(string A, string B){
		unordered_map<string, int> wordCnt;
		{
			stringstream ss(A);
			string buf;
			while( getline(ss, buf, ' ') ){
				if( wordCnt.find(buf) == wordCnt.end() ){
					wordCnt[buf] = 1;
				}else{
					wordCnt[buf]++;
				}
			}
		}

		{
			stringstream ss(B);
			string buf;
			while( getline(ss, buf, ' ') ){
				if( wordCnt.find(buf) == wordCnt.end() ){
					wordCnt[buf] = 1;
				}else{
					wordCnt[buf]++;
				}
			}
		}

		vector<string> ans;

		for( auto it = wordCnt.begin(); it != wordCnt.end(); it++ ){
			if( it->second == 1 ){
				ans.push_back(it->first);
			}
		}

		return ans;
	}
};



/*
参考思路2(更好更简洁的实现方法)
正确提交之后，查看 Accepted Solutions 里面效率最高的，
先把两个字符串合并，中间加上空格。然后放到 istringstream 里面形成 iss 流
再按照思路1统计只出现一次的 word

注意1: iss和cin都是流，所以有类似操作，iss>>A可以直接按照空格和换行符分隔word，不需要像getline一样显式指明delim
注意2: m 新加元素会自动对其进行初始化(构造)，也就是 m[A] 会自动初始化为 0
注意3: foreach遍历map, for( auto & it : m ){...}, it不是指针(->)，是元素(.)
总结: 大神牛x，C++牛x

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        istringstream iss(A + " " + B);
        unordered_map<string, int> m;
        vector<string> res;
        while (iss >> A) {
            m[A]++;
        }
        for (auto& i : m) {
            if (i.second == 1) {
                res.emplace_back(i.first);
            }
        }
        return res;
    }
};
*/
class Solution2{
public:
	vector<string> uncommonFromSentences(string A, string B){
		istringstream iss(A + " " + B);
		unordered_map<string, int> m;
		string buf;
		while( iss >> buf ){
			m[buf]++;
		}

		vector<string> ans;
		for( auto & it : m ){
			if( it.second == 1 ){
				ans.push_back(it.first);
			}
		}
		return ans;
	}
};

int main(){
	// Solution s;
	// string a = "this apple apple is sweet";
	// string b = "this apple is sour";
	// s.uncommonFromSentences(a, b);

	return 0;
}
