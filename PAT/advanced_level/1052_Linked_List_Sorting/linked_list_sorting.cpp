#include <iostream>
#include <algorithm>
#include <iomanip>
#define MAXSIZE 100004
using namespace std;

struct Node{
	int mAddr=-2, mVal, mNext;
	bool mMarked=false;
	int set(int addr, int val, int next){
		mAddr = addr;
		mVal = val;
		mNext = next;
		return 0;
	}
};

Node tmpNode[MAXSIZE], nodeList[MAXSIZE];

int cmp(Node a, Node b){
	return a.mVal < b.mVal;
}

int nowNode(int addr){
	cout<<setfill('0')<<setw(5)<<nodeList[addr].mAddr<<' ';
	cout<<nodeList[addr].mVal<<' ';
	return 0;
}

int nextNode(int addr){
	cout<<setfill('0')<<setw(5)<<nodeList[addr].mAddr<<'\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, start, addr, val, next, i;

	cin>>n>>start;

	for( i = 0; i < n; ++i ){
		cin>>addr>>val>>next;
		tmpNode[addr].set(addr, val, next);
	}

	int cnt = 0;
	int p = start;
	while( p != -1 ){
		if( tmpNode[p].mAddr == -1 ){
			break;
		}
		tmpNode[p].mMarked = true;
		nodeList[cnt++] = tmpNode[p];
		p = tmpNode[p].mNext;
	}

	if( cnt == 0 ){
		cout<<"0 -1\n";
	}else{
		sort(nodeList, nodeList + cnt, cmp);
		cout<<cnt<<' ';
		cout<<setfill('0')<<setw(5)<<nodeList[0].mAddr<<'\n';

		for( i = 0; i < cnt - 1; ++i ){
			nowNode(i);
			nextNode(i + 1);
		}
		nowNode(i);
		cout<<"-1\n";
	}

	return 0;
}