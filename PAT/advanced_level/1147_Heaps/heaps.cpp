/*
输入一个数组, 代表一棵完全二叉树
根据定义, 判断这棵树是否构成 最大堆/最小堆
最后, 后序遍历输出这棵树
*/

#include <iostream>
#include <vector>
#define MAXSIZE 1004
using namespace std;

int tree_size;
int tree[MAXSIZE];
vector<int> ans_list;

void post_trav(int root)
{
	if( root <= tree_size )
	{
		int left = root * 2;
		int right = left + 1;
		post_trav(left);
		post_trav(right);
		ans_list.push_back(tree[root]);
	}
}

void print_node_list()
{
	cout << ans_list[0];
	int size = ans_list.size();
	for( int i = 1; i < size; i++ )
	{
		cout << ' ' << ans_list[i];
	}
	cout << '\n';
	ans_list.clear();
}

bool is_min_heap()
{
	for( int i = 2; i <= tree_size; i++ )
	{
		int child = i;
		int parent = child / 2;
		if( tree[parent] > tree[child] )
		{
			return false;
		}
	}
	return true;
}

bool is_max_heap()
{
	for( int i = 2; i <= tree_size; i++ )
	{
		int child = i;
		int parent = child / 2;
		if( tree[parent] < tree[child] )
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

	int m, len;
	cin >> m >> len;
	tree_size = len;
	for( int q = 0; q < m; q++ )
	{
		for( int i = 1; i <= len; i++ )
		{
			cin >> tree[i];
		}
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
		// root == 1;
		post_trav(1);
		print_node_list();
	}

	return 0;
}