#include <iostream>
#include <algorithm>
#include <iomanip>
#define MAXSIZE 100004
#define INF 1000000
using namespace std;

struct Node{
	int mAddr, mVal, mNext;
	int mOrder = INF;
	int set(int addr, int val, int next){
		mAddr = addr;
		mVal = val;
		mNext = next;
		return 0;
	}
};

Node nodelist[MAXSIZE];

int cmp(Node a, Node b){
	return a.mOrder < b.mOrder;
}

int nowNode(int addr){
	cout<<setfill('0')<<setw(5)<<nodelist[addr].mAddr<<' ';
	cout<<nodelist[addr].mVal<<' ';
	return 0;
}

int nextNode(int addr){
	cout<<setfill('0')<<setw(5)<<nodelist[addr].mAddr<<'\n';
	return 0;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int start, n, k, i, addr, val, next;
	
	for( i=0; i<MAXSIZE; ++i ){
		nodelist[i].mOrder = INF;
	}

	cin>>start>>n>>k;

	for( i=0; i<n; ++i ){
		cin>>addr>>val>>next;
		nodelist[addr].set(addr, val, next);
	}

	int p = start, cnt = 0;
	while( p != -1 ){
		nodelist[p].mOrder = cnt++;
		p = nodelist[p].mNext;
	}
	n = cnt;

	sort( nodelist, nodelist+MAXSIZE, cmp );

	int loop = n / k;
	if( loop > 0 ){
		for( i = 0; i < loop; ++i ){
			int src = (i + 1) * k - 1;
			int dest = i * k;
			for( p = src; p > dest; --p ){
				nowNode(p);
				nextNode(p-1);
			}

			// now is p
			nowNode(p);

			// then we are going to find [next]
			if( i < loop - 1 ){
				nextNode(src + k);
			}else if( i == loop - 1 ){
				// last round
				if( 0 == n % k ){
					// end, next is -1
					cout<<"-1\n";
				}else{
					nextNode(src + 1);
					
					src = src + 1;
					dest = n;
					for( int q = src; q < dest; ++q ){
						nowNode(q);
						if( q < dest - 1 ){
							nextNode(q + 1);
						}else{
							cout<<"-1\n";
						}
					}
				}
			}
		}
	}else{
		// loop == 0
		int src = n - n % k;
		int dest = n;
		for( int q = src; q < dest; ++q ){
			nowNode(q);
			if( q < dest - 1 ){
				nextNode(q + q);
			}else{
				cout<<"-1\n";
			}
		}
	}
	return 0;
}
