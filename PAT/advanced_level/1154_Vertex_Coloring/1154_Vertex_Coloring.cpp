/*
https://pintia.cn/problem-sets/994805342720868352/problems/1071785301894295552
画图观察，总结规律

1. 首先遍历图, 检查是否存在 graph[v1][v2], 使得 color[v1] == color[v2]
   如果存在, 则返回 false, 即这个图不是 k-coloring
2. 如果返回的是 true, 再遍历所有结点, 将其 color 输入一个 set<int> s
   最后得到的 s.size() 就是 k-coloring 中的 k
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector< vector<int> > graph;
vector<int> colorList;

// 检查相邻顶点颜色是否相同
// BFS
bool checkValid(int n)
{
	int valid = true;
	for( int now = 0; now < n; now++ )
	{
		vector<int> neighbor = graph[now];
		for( int next : neighbor )
		{
			if( colorList[now] == colorList[next] )
			{
				valid = false;
				break;
			}
		}
	}
	return valid;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	graph.resize(n);
	colorList.resize(n);

	int v1, v2;
	for( int i = 0; i < m; i++ )
	{
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	int k;
	cin >> k;
	for(int qeury = 0; qeury < k; qeury++ )
	{
		for( int v = 0; v < n; v++ )
		{
			cin >> colorList[v];
		}

		bool valid = checkValid(n);
		if( valid == true )
		{
			// cntColor
			unordered_set<int> s;
			for( int color : colorList )
			{
				s.insert(color);
			}
			int cnt = s.size();
			cout << cnt << "-coloring\n";
		}
		else
		{
			cout << "No\n";
		}

	}

	return 0;
}
