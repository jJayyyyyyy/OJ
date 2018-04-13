#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#define MAXSIZE 100004
using namespace std;

struct Node{
	int level;
	vector<int> children;
	Node(){
		level = 0;
	}
};

Node node[MAXSIZE];
int minLevel=MAXSIZE, minCnt=1;

void updateLevel(int root){
	for( auto childID : node[root].children  ){
		node[childID].level = node[root].level + 1;
		updateLevel(childID);
	}
}

void getMinLevel(int root){
	if( 0 == node[root].children.size() ){
		int level = node[root].level;
		if( level < minLevel ){
			minLevel = level;
			minCnt = 1;
		}else if( level == minLevel ){
			++minCnt;
		}
	}else{
		for( auto childID : node[root].children ){
			getMinLevel(childID);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, id;
	double price, rate;
	cin>>n>>price>>rate;
	for( int i = 0; i < n; ++i ){
		cin>>k;
		for( int j = 0; j < k; ++j ){
			cin>>id;
			node[i].children.push_back(id);
		}
	}
	
	updateLevel(0);
	getMinLevel(0);
	double lowRate = pow(1.0 + rate/100.0, minLevel);
	double lowPrice = price * lowRate;
	cout.setf(ios::fixed);
	cout<<setprecision(4)<<lowPrice<<' '<<minCnt<<'\n';
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <queue>
#define MAXSIZE 100004
// #define MAXSIZE 14
using namespace std;

struct Node {
	int id, level;
	vector<int> childList;
	Node(){
		level = 1;
	}
};

int minLevel = MAXSIZE, cntMinLevel = 0;

Node nodeList[MAXSIZE];

// update level
void levelTrav(){
	queue<Node> q;
	q.push(nodeList[0]);
	while( q.size() ){
		Node parent = q.front();
		// vis(parent);
		q.pop();
		int level = parent.level;
		if( parent.childList.size() == 0 ){
			if( level < minLevel ){
				minLevel = level;
				cntMinLevel = 1;
			}else if( level == minLevel ){
				cntMinLevel++;
			}
		}else{
			for( auto id : parent.childList ){
				nodeList[id].level = level + 1;
				q.push(nodeList[id]);
			}
		}

	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int total;
	double rawPrice, incRate;
	cin>>total>>rawPrice>>incRate;

	int k, id;
	for( int i = 0; i < total; i++ ){
		cin>>k;
		nodeList[i].id = i;
		for( int j = 0; j < k; j++ ){
			cin>>id;
			nodeList[i].childList.push_back(id);
		}
	}
	levelTrav();

	double minPrice = rawPrice * pow(1.0+incRate/100, minLevel-1);

	cout<<fixed<<setprecision(4)<<minPrice;
	cout<<' '<<cntMinLevel<<'\n';

	return 0;
}

*/