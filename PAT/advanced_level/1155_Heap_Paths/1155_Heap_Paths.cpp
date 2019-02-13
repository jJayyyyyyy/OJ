#include <iostream>
#include <vector>
#define MAXSIZE 1004
using namespace std;

vector<int> path;
int a[MAXSIZE];
int len;

void printPath()
{
	int path_len = path.size();
	cout << path[0];
	for( int i = 1; i < path_len; i++ )
	{
		cout << ' ' << path[i];
	}
	cout << '\n';
}

void dfs(int ix)
{
	int left = ix * 2, right = ix * 2 + 1;

	if( ix <= len )
	{
		path.push_back(a[ix]);
		dfs(right);
		dfs(left);

		// 判断是否到达叶结点, 如果到达叶结点, 则进行输出
		// left > len && right > len 等价于 left > len
		// 与柳神的解法稍有不同, 柳神的解法是在叶结点的父结点开始遍历
		// 我的解法是到了叶结点才开始DRL遍历
		// 减少了判断次数
		// 同时, 和普通的前序中序后续等遍历保持形式一致
		if( left > len )
		{
			printPath();
		}
		path.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> len;
	for( int i = 1; i <= len; i++ )
	{
		cin >> a[i];
	}
	dfs(1);
	bool is_min_heap = true, is_max_heap = true;
	for( int i = 2; i <= len; i++ )
	{
		int parent = i / 2;
		int child = i;
		if( a[parent] > a[child] )
		{
			is_min_heap = false;
		}
		if( a[parent] < a[child] )
		{
			is_max_heap = false;
		}
	}

	if( is_min_heap == true )
	{
		cout << "Min Heap\n";
	}
	else if( is_max_heap == true )
	{
		cout << "Max Heap\n";
	}
	else
	{
		cout << "Not Heap\n";
	}

	return 0;
}
