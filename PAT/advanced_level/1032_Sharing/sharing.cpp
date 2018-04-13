#include <iostream>
#include <iomanip>
#define MAXSIZE 100004
using namespace std;

struct Node{
	int mVal, mNext;
	bool marked = false;
	int set(int val, int next){
		mVal = val;
		mNext = next;
		return 0;
	}
};

Node nodelist[MAXSIZE];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a1, a2, n, i, now, next;
	char val;
	cin>>a1>>a2>>n;

	for( i=0; i<n; ++i ){
		cin>>now>>val>>next;
		nodelist[now].set(val, next);
	}

	int p = a1;
	while( p != -1 ){
		nodelist[p].marked = true;
		p = nodelist[p].mNext;
	}

	p = a2;
	while( p != -1 ){
		if( nodelist[p].marked == true ){
			break;
		}else{
			p = nodelist[p].mNext;
		}
	}

	if( p != -1 ){
		cout<<setfill('0')<<setw(5)<<p<<'\n';
	}else{
		cout<<"-1\n";
	}

	return 0;
}
