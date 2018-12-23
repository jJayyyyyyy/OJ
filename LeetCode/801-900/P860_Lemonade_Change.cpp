/*
https://leetcode.com/problems/lemonade-change/description/
找零钱
同类题目 P860
*/

#include <iostream>
#include <vector>
using namespace std;

const static auto c = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution{
public:
	bool lemonadeChange(vector<int> & bills) {
		int five = 0, ten = 0, twenty = 0;

		for( int bill : bills ){
			if( bill == 5 ){
				five++;
			}else if( bill == 10 ){
				if( five == 0 ){
					return false;
				}else{
					five--;
					ten++;
				}
			}else{
				if( five > 0 && ten > 0 ){
					five--;
					ten--;
				}else if( five >= 3 && ten == 0 ){
					five -= 3;
				}else{
					return false;
				}
			}
		}
		return true;
	}
};

int main(){
	vector<int> v;
	v.push_back(5);
	v.push_back(5);
	v.push_back(10);
	v.push_back(10);
	v.push_back(20);
	Solution s;
	s.lemonadeChange(v);

	return 0;
}
