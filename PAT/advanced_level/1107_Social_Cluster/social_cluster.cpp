#include <iostream>
#include <algorithm>
#define MAXSIZE 1004
#define EMPTY 0
using namespace std;

struct Cluster{
	int rootID = 0;
	int people = 0;
};
Cluster cluster[MAXSIZE];

bool marked[MAXSIZE] = {false};
int father[MAXSIZE] = {0};
int hobbyList[MAXSIZE] = {0};

void initFather(){
	for( int i = 0; i < MAXSIZE; ++i ){
		father[i] = i;
	}
}

int findFather(int x){
	while( x != father[x] ){
		x = father[x];
	}
	return x;
}

void Union(int a, int b){
	int fa1 = findFather(a);
	int fa2 = findFather(b);
	if( fa1 < fa2 ){
		father[fa2] = fa1;
	}else{
		father[fa1] = fa2;
	}
}

int cmp(Cluster a, Cluster b){
	return a.people > b.people;
}

int main(){
	char ch;
	int n, k, h, i, id, j;
	cin>>n;
	initFather();

	for( id = 1; id <= n; ++id ){
		marked[id] = true;
		cin>>k>>ch;
		for( j = 1; j <= k; ++j ){
			cin>>h;
			// 下面5行是关键，其他都是模板
			if( hobbyList[h] == EMPTY ){
				hobbyList[h] = id;
			}
			int hobbyOwnerID = findFather(hobbyList[h]);
			Union( id, hobbyOwnerID );
		}
	}

	for( i = 0; i < MAXSIZE; ++i ){
		if( marked[i] == true ){
			int rootID = findFather(i);
			cluster[rootID].people++;
		}
	}

	int cntCluster = 0, maxID = 0;
	for( i = 0; i < MAXSIZE; ++i ){
		if( cluster[i].people > 0 ){
			cntCluster++;
			maxID = i;
		}
	}

	sort( cluster, cluster + maxID + 1, cmp);
	cout<<cntCluster<<'\n';
	for( i = 0; i < cntCluster; ++i ){
		cout<<cluster[i].people;
		if( i < cntCluster - 1 ){
			cout<<' ';
		}
	}
	cout<<'\n';
	return 0;
}
