#include <iostream>
#include <vector>
#define MAXSIZE 1004
using namespace std;

vector<int> path;
int tree[MAXSIZE];
int len;

void print_path()
{
	int size = path.size();
	cout << path[0];
	for( int i = 1; i < size; i++ )
	{
		cout << ' ' << path[i];
	}
	cout << '\n';
}

void dfs(int root)
{
	if( root <= len )
	{
		int left = root * 2;
		int right = left + 1;
		path.push_back(tree[root]);
		dfs(right);
		dfs(left);

		// 判断是否到达叶结点, 如果到达叶结点, 则进行输出
		// left > len && right > len 等价于 left > len
		// 与柳神的解法稍有不同, 柳神的解法是在叶结点的父结点开始遍历
		// 我的解法是到了叶结点才开始DRL遍历
		// 减少了判断次数
		// 同时, 和普通的前序中序后续等遍历保持形式一致
		if( left > len && right > len )
		{
			print_path();
		}
		path.pop_back();
	}
}

bool is_min_heap()
{
	for( int child = 2; child <= len; child++ )
	{
		int parent = child / 2;
		if( tree[child] < tree[parent] )
		{
			return false;
		}
	}
	return true;
}

bool is_max_heap()
{
	for( int child = 2; child <= len; child++ )
	{
		int parent = child / 2;
		if( tree[child] > tree[parent] )
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> len;
	for( int i = 1; i <= len; i++ )
	{
		cin >> tree[i];
	}

	int root = 1;
	dfs(root);

	if( is_min_heap() )
	{
		cout << "Min Heap\n";
	}
	else if( is_max_heap() )
	{
		cout << "Max Heap\n";
	}
	else
	{
		cout << "Not Heap\n";
	}
	return 0;
}
