/*
https://leetcode.com/problems/3sum/description/
三个数的和为0，找出所有不重复的组合

参考思路
https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C++-solution-around-50ms-O(N*N)-with-explanation-and-comments

同类题目: P001, P018, P015, P454
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector< vector<int> > threeSum(vector<int> &numlist) {
		vector< vector<int> > ans;
		sort(numlist.begin(), numlist.end());
		int size = numlist.size();
		for( int i = 0; i < size; i++ ){
			int target = -numlist[i];
			int ileft = i + 1;
			int iright = size - 1;
			while( ileft < iright ){
				int valleft = numlist[ileft];
				int valright = numlist[iright];
				int sum = valleft + valright;
				if( sum < target ){
					ileft++;
				}
				else if( sum > target ){
					iright--;
				}
				else{
					vector<int> line(3);
					line[0] = -target;
					line[1] = valleft;
					line[2] = valright;
					ans.push_back(line);

					while( ileft < iright && numlist[ileft] == valleft ){
						ileft++;
					}

					while( ileft < iright && numlist[iright] == valright ){
						iright--;
					}
				}
			}
			while( i + 1 < size && numlist[i + 1] == -target ){
				i++;
			}
		}
		return ans;
	}
};