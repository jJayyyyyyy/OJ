/*
输入一个数组, 代表一棵完全二叉树
根据定义, 判断这棵树是否构成 最大堆/最小堆
最后, 后序遍历输出这棵树
*/

#include <iostream>
#include <vector>
#define MAXSIZE 1004
using namespace std;

int arr[MAXSIZE] = {0};
vector<int> ansList;

bool isMinHeap(int root, int len)
{
	bool res = true;
	for( int i = root; i <= len; i++ )
	{
		int parent = i;
		int left = i * 2;
		int right = left + 1;
		if( left <= len )
		{
			if( arr[parent] > arr[left] )
			{
				res = false;
				break;
			}
		}

		if( right <= len )
		{
			if( arr[parent] > arr[right] )
			{
				res = false;
				break;
			}
		}
	}
	return res;
}

bool isMaxHeap(int root, int len)
{
	bool res = true;
	for( int i = root; i <= len; i++ )
	{
		int parent = i;
		int left = i * 2;
		int right = left + 1;
		if( left <= len )
		{
			if( arr[parent] < arr[left] )
			{
				res = false;
				break;
			}
		}

		if( right <= len )
		{
			if( arr[parent] < arr[right] )
			{
				res = false;
				break;
			}
		}
	}
	return res;
}

void postTrav(int root, int len)
{
	if( root <= len )
	{
		int val = arr[root];
		int left = root * 2;
		int right = left + 1;
		postTrav(left, len);
		postTrav(right, len);
		ansList.push_back(val);
	}
}

void printAns()
{
	bool isFirst = true;
	int len = ansList.size();
	for( int i = 0; i < len; i++ )
	{
		if( isFirst == true )
		{
			isFirst = false;
			cout << ansList[i];
		}
		else
		{
			cout << ' ' << ansList[i];
		}
	}
	cout << '\n';
	ansList.clear();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	int root = 1;
	for( int i = 0; i < m; i++ )
	{
		for( int j = 0; j < n; j++ )
		{
			cin >> arr[j + 1];
		}

		if( isMinHeap(root, n) == true )
		{
			cout << "Min Heap\n";
		}
		else if( isMaxHeap(root, n) == true )
		{
			cout << "Max Heap\n";
		}
		else
		{
			cout << "Not Heap\n";
		}

		postTrav(root, n);
		printAns();
	}

	return 0;
}
