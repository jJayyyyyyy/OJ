#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <functional>
#define MAXSIZE 1004
using namespace std;

vector<int> G[MAXSIZE], ansList;
int inDegree[MAXSIZE] = {0};
int n, m, cnt=0;

bool isTopo(){
	// priority_queue<int, vector<int>, greater<int> > pq;
	set<int> s;

	for( int i = 0; i < n; i++ ){
		if( inDegree[i] == 0 ){
			s.insert(i);
			// pq.push(i);
		}
	}

	while( s.size() ){
	// while( pq.size() ){
		int now = *s.begin();
		// int now = pq.top();

		ansList.push_back(now);

		s.erase(now);
		// pq.pop();
		for( auto next : G[now] ){
			inDegree[next]--;
			if( inDegree[next] == 0 ){
				s.insert(next);
				// pq.push(next);
			}
		}
		G[now].clear();
		cnt++;
	}
	return cnt == n;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;
	int v1, v2;

	for( int i = 0; i < m; i++ ){
		cin>>v1>>v2;
		G[v1].push_back(v2);
		inDegree[v2]++;
	}

	if( isTopo() ){
		cout<<"YES\n";
		for( int i = 0; i < n; i++ ){
			if( i != 0 ){
				cout<<' ';
			}
			cout<<ansList[i];
		}
		cout<<'\n';
	}else{
		cout<<"NO\n";
		cout<<(n - cnt)<<'\n';
	}

	return 0;
}