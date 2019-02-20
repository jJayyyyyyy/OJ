/*
名词解释
1. clique 是一个集合, 在这个集合里的所有结点两两直接相连
2. maximal clique 是这样一个 clique, 无法再向里面添加任何结点的且使其仍满足 clique 的性质

思路如下
首先检查每一个 query 是否满足 clique 的性质 —— query 中的结点是否两两直接相连
1.1 先把每一个 query 的所有结点保存到 node_list 中
1.2 接着, 我们首先把 node_list 中的所有结点保存到 visited_list 中并设置为 false
    然后遍历 node_list
        对于其中的每一个结点 now, 再遍历与 now 相邻的结点 next, 将其标注为 true
        检查 visited_list 中的所有结点是否为 true, 若存在 false, 则说明存在不相连的结点, 打印 Not a Clique 并退出

    若能正常遍历完成 node_list , 则说明所有结点都满足两两相连的性质, 这是一个 clique

接下来判断是否为 maximal clique
2.1 对于每一个属于 graph 但不属于 node_list 的结点 v, 将其加入 node_list, 判断新的 node_list 是否满足 clique 的性质
    若存在满足性质的 v, 则说明 clique 还可以再扩充
    否则, 这个 query 就是一个 maximal clique
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAXSIZE 208
using namespace std;

vector<int> graph[MAXSIZE];
vector<bool> vis(MAXSIZE, false);

bool check_connectivity(int now, vector<int> & node_list)
{
	/* visit graph, set neighbors as true */
	fill(vis.begin(), vis.end(), false);
	vis[now] = true;
	for( int next : graph[now] )
	{
		vis[next] = true;
	}
	
	/* check if there is any node in the query doesn't connect with now */
	for( int now :  node_list ){
		if( vis[now] == false )
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

	int n, m;
	cin >> n >> m;

	int v1, v2;
	for( int i = 0; i < m; i++ )
	{
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	int ttl_query;
	cin >> ttl_query;
	for( int q = 0; q < ttl_query; q++ ){
		int size;
		cin >> size;
		vector<int> node_list(size);
		vector<bool> query_set(n + 1, false);
		for( int i = 0; i < size; i++ )
		{
			int now;
			cin >> now;
			node_list[i] = now;
			query_set[now] = true;
		}

		bool is_clique = true;
		for( int now : node_list )
		{
			if( check_connectivity(now, node_list) == false )
			{
				is_clique = false;
				break;
			}
		}

		if( is_clique == false )
		{
			cout<<"Not a Clique\n";
		}
		else
		{
			bool not_maximal = false;
			for( int now = 1; now <= n; now++ )
			{
				if( query_set[now] == false )
				{
					node_list.push_back(now);
					if( check_connectivity(now, node_list) == true )
					{
						not_maximal = true;
						break;
					}
					else
					{
						node_list.pop_back();
					}
				}
			}
			if( not_maximal == true )
			{
				cout << "Not Maximal\n";
			}
			else
			{
				cout<<"Yes\n";
			}
		}
	}
	return 0;
}
