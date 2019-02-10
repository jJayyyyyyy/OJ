/*
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
给定一个二维数组 matrix
每一列都是升序, 每一行都是升序
找出 matrix 中第 k 大的元素

同类题目
P230, P378

思路1
把 matrix 降维成一维数组 arr, 从小到大排序, 输出 arr[k - 1]

思路2
把 matrix 依次输入最小堆 minheap, 然后输出 minheap 的第 k 个元素
*/

#include <iostream>
#include <queue>
#include <functional>
using namespace std;

// io加速
static const auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} ();

class Solution
{
public:
	int kthSmallest(vector< vector<int> > & matrix, int k)
	{
		int ttl_row = matrix.size();
		int ttl_col = matrix[0].size();
		int ttl_size = ttl_row * ttl_col;
		vector<int> arr( ttl_size );
		int cnt = 0;
		for( int i = 0; i < ttl_row; i++ )
		{
			for( int j = 0; j < ttl_col; j++ )
			{
				arr[cnt++] = matrix[i][j];
			}
		}

		sort(arr.begin(), arr.end());

		return arr[k - 1];
	}
};

class Solution2
{
public:
	int kthSmallest(vector< vector<int> > & matrix, int k)
	{
		int ttl_row = matrix.size();
		int ttl_col = matrix[0].size();
		int ans = matrix[0][0];
		if( k == 1 )
		{
			return ans;
		}
		priority_queue<int, vector<int>, greater<int> > pq;
		for( int i = 0; i < ttl_row; i++ )
		{
			for( int j = 0; j < ttl_col; j++ )
			{
				pq.push(matrix[i][j]);
			}
		}

		for( int i = 0; i < k; i++ )
		{
			ans = pq.top();
			pq.pop();
		}

		return ans;
	}
};

int main()
{
	vector< vector<int> > matrix(3, vector<int>(3));
	matrix[0][0] = 1;
	matrix[0][1] = 5;
	matrix[0][2] = 9;
	matrix[1][0] = 10;
	matrix[1][1] = 11;
	matrix[1][2] = 13;
	matrix[2][0] = 12;
	matrix[2][1] = 13;
	matrix[2][2] = 15;

	Solution s;
	s.kthSmallest(matrix, 8);
	return 0;
}