/*
https://leetcode.com/problems/largest-time-for-given-digits/description/
给定一个长度为 4 的数字数组, 求出它能表示的最大时间

同类题目 P949

穷举
https://leetcode.com/problems/largest-time-for-given-digits/solution/
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution{
public:
	string largestTimeFromDigits(vector<int> & a) {
		int maxmins = -1;
		for( int i = 0; i < 4; i++ ){
			for( int j = 0; j < 4; j++ ){
				if( j != i ){
					for( int k = 0; k < 4; k++ ){
						if( k != i && k != j ){
							int l = 6 - i - j - k;
							int hours = 10 * a[i] + a[j];
							int mins = 10 * a[k] + a[l];
							if( hours < 24 && mins < 60 ){
								maxmins = max(maxmins, hours * 60 + mins);
							}
						}
					}
				}
			}
		}
		if( maxmins < 0 ){
			return "";
		}
		else{
			int hours = maxmins / 60;
			int mins = maxmins % 60;
			string strhour, strmin;
			stringstream sshour, ssmin;
			sshour << setfill('0') << setw(2) << hours;
			ssmin << setfill('0') << setw(2) << mins;
			sshour >> strhour;
			ssmin >>strmin;
			string ans = strhour + ":" + strmin;
			return ans;
		}
	}
};

int main(){
	vector<int> a{0,0,0,0};
	Solution s;
	cout << s.largestTimeFromDigits(a) << '\n';
	return 0;
}