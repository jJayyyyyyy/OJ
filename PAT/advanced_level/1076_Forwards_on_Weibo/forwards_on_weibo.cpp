#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAXSIZE 1004
using namespace std;

struct Node{
	int id;
	int level;
	Node(int _id, int _level){
		id = _id;
		level = _level;
	}
};

vector<Node> G[MAXSIZE];
bool inq[MAXSIZE] = {false};

int BFS(int start, int maxLevel){
	int maxForward = 0;
	Node now(start, 0);
	queue<Node> q;
	q.push(now);
	inq[now.id] = true;

	while( q.size() ){
		now = q.front();
		q.pop();
		int id = now.id;
		for( int i = 0; i < G[id].size(); ++i ){
			Node next = G[id][i];
			next.level = now.level + 1;
			if( inq[next.id] == false && next.level <= maxLevel ){
				q.push(next);
				inq[next.id] = true;
				maxForward++;
			}
		}
	}
	return maxForward;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, maxLevel, numFollow, id, numQuery, i, j;
	cin>>n>>maxLevel;

	for( i = 1; i <= n; ++i ){
		Node user(i, 0);
		cin>>numFollow;
		for( j = 0; j < numFollow; ++j ){
			cin>>id;
			G[id].push_back(user);
		}
	}

	cin>>numQuery;
	for( i = 0; i < numQuery; ++i ){
		int start;
		cin>>start;
		fill(inq, inq+MAXSIZE, false);
		int maxForward = BFS(start, maxLevel);
		cout<<maxForward<<'\n';
	}
	return 0;
}