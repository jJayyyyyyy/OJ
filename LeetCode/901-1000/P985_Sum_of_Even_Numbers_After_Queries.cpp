/*
https://leetcode.com/problems/sum-of-even-numbers-after-queries/description/
每一条 query 包含两个值: val 和 index
每一次 A[index] += val, 然后统计 A 的偶数值之和, 并记录
同类题目 P985
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> sumEvenAfterQueries(vector<int> & A, vector<vector <int> > & queries) {
		int len = queries.size();
		vector<int> ans(len);
		int sum = 0;
		for( int num : A )
		{
			if( num % 2 == 0 )
			{
				sum += num;
			}
		}
		for( int i = 0; i < len; i++ )
		{
			int val = queries[i][0];
			int index = queries[i][1];
			int pre = A[index];
			int now = pre + val;
			A[index] = now;

			if( pre % 2 == 0 )
			{
				sum -= pre;
			}
			
			if( now % 2 == 0 )
			{
				sum += now;
			}
			ans[i] = sum;
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<int> A(4);
	A[0] = 1;
	A[1] = 2;
	A[2] = 3;
	A[3] = 4;

	vector< vector< int > > queries(4, vector<int>(2));
	queries[0][0] = 1;
	queries[0][1] = 0;
	queries[1][0] = -3;
	queries[1][1] = 1;
	queries[2][0] = -4;
	queries[2][1] = 0;
	queries[3][0] = 2;
	queries[3][1] = 3;
	s.sumEvenAfterQueries(A, queries);
	
	return 0;
}
