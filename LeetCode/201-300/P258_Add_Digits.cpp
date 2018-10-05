/*
https://leetcode.com/problems/add-digits/description/
把一个整数 num 的每一位进行累加，得到 sum
再使 num = sum
重复上述过程，直到 num 只有一位数字
同类题目 P258

*/

#include <iostream>
#include <string>
using namespace std;

// io加速
// static const auto io_speed_up = []() {
// 	std::ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	return 0;
// } ();

class Solution{
public:
	int addDigits(int num){
		
		string strnum = to_string(num);
		while( strnum.size() != 1 ){
			int sum = 0;
			for( char ch : strnum ){
				sum += ch - '0';
			}
			strnum = to_string(sum);
		}
		return strnum[0] - '0';
	}
};


// https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
class Solution2 {
public:
    int addDigits(int num) {
        if(num == 0){
        	return 0;
        }else if(num%9==0){
        	return 9;
        }else{
        	return num%9;
        }
    }
};