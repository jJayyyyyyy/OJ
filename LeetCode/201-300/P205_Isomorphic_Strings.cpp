/*
 * https://leetcode.com/problems/isomorphic-strings/description/
 * 同型字符串
 * 同类题目 P205
 * 
 * 相当于 f(s) = t, g(t) = s
 * t 是 s 的单值函数, s 是 t 的单值函数
 * 几个反例
 * 1. a->a
 *    b->a  error, 因为 t 中的 a 已经与 s 中的 a 绑定了, 不再接受新的绑定
 *
 * 2. a->b
      a->c  error, 因为 s 中的 a 已经与 t 中的 b 绑定了
      
 *
*/

// #include <iostream>
// using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int m1[160] = {0};
		int m2[160] = {0};
		int len = s.size();

		if( len == 0 ){
			return true;
		}

		for( int i = 0; i < len; i++ ){
			char ch1 = s[i];
			char ch2 = t[i];
			if( m1[ch1] == 0 && m2[ch2] == 0 ){
				m1[ch1] = ch2;
				m2[ch2] = ch1;
			}else if( m1[ch1] != 0 && m2[ch2] == 0 ){
				return false;
			}else if( m1[ch1] == 0 && m2[ch2] != 0 ){
				return false;
			}else{
				if( m1[ch1] != ch2 ){
					return false;
				}
			}
		}
		return true;
	}
};
