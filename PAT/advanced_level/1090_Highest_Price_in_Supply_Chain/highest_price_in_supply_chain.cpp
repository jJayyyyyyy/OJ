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
int maxLevel=-1, maxCnt=0;

void updateLevel(int root){
	for( auto childID : node[root].children  ){
		node[childID].level = node[root].level + 1;
		updateLevel(childID);
	}
}

void getMaxLevel(int root){
	if( 0 == node[root].children.size() ){
		int level = node[root].level;
		if( level > maxLevel ){
			maxLevel = level;
			maxCnt = 1;
		}else if( level == maxLevel ){
			++maxCnt;
		}
	}else{
		for( auto childID : node[root].children ){
			getMaxLevel(childID);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, id, root;
	double price, rate;
	cin>>n>>price>>rate;
	for( int i = 0; i < n; ++i ){
		cin>>id;
		if( id == -1 ){
			root = i;
		}else{
			node[id].children.push_back(i);
		}
	}

	updateLevel(root);
	getMaxLevel(root);
	double maxRate = pow(1.0 + rate/100.0, maxLevel);
	double maxPrice = price * maxRate;
	cout.setf(ios::fixed);
	cout<<setprecision(2)<<maxPrice<<' '<<maxCnt<<'\n';
	return 0;
}