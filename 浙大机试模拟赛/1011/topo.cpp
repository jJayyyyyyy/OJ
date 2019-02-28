#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <functional>
#define MAXSIZE 1004
using namespace std;

vector<int> graph[MAXSIZE], ans_list;	// graph是邻接表
int in_degree[MAXSIZE] = {0};        	// 入度表
int n, m, cnt=0;

bool is_topo(){
	set<int> s;
	// priority_queue<int, vector<int>, greater<int> > pq;

	for( int v = 0; v < n; v++ )
	{
		if( in_degree[v] == 0 )
		{
			s.insert(v);			// 先访问序号较小的
			// pq.push(i);
		}
	}

	while( s.size() != 0 ){
	// while( pq.size() ){
		int now = *s.begin();
		// int now = pq.top();

		ans_list.push_back(now);

		s.erase(now);
		// pq.pop();

		for( int next : graph[now] )
		{
			in_degree[next]--;
			if( in_degree[next] == 0 )
			{
				s.insert(next);
				// pq.push(next);
			}
		}
		graph[now].clear();
		cnt++;
	}
	return cnt == n;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int v1, v2;

	for( int i = 0; i < m; i++ )
	{
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		in_degree[v2]++;
	}

	if( is_topo() == true )
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
		cout << (n - cnt) << '\n';
	}

	return 0;
}