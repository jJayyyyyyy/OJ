#include <iostream>
#include <cstdlib>	//abs()
#include <iomanip>
#define MAXSIZE 100004
using namespace std;

struct Node{
	int mAddr, mVal, mNext;
	int set(int addr, int val, int next){
		mAddr = addr;
		mVal = val;
		mNext = next;
		return 0;
	}
};

Node tmpList[MAXSIZE], ansList1[MAXSIZE], ansList2[MAXSIZE];
bool marked[MAXSIZE] = {false};

int nowNode(Node ansList[], int addr){
	cout<<setfill('0')<<setw(5)<<ansList[addr].mAddr<<' ';
	cout<<ansList[addr].mVal<<' ';
	return 0;
}

int nextNode(Node ansList[], int addr){
	cout<<setfill('0')<<setw(5)<<ansList[addr].mAddr<<'\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, i, start, val, addr, next;
	cin>>start>>n;
	for( i = 0; i < n; ++i ){
		cin>>addr>>val>>next;
		tmpList[addr].set(addr, val, next);
	}
	
	int cnt1 = 0, cnt2 = 0, absVal, p = start;
	while( p != -1 ){
		val = tmpList[p].mVal;
		absVal = abs(val);

		if( false == marked[absVal] ){
			marked[absVal] = true;
			ansList1[cnt1].mAddr = p;
			ansList1[cnt1].mVal = val;
			++cnt1;
		}else{
			ansList2[cnt2].mAddr = p;
			ansList2[cnt2].mVal = val;
			++cnt2;
		}
		p = tmpList[p].mNext;;
	}

	for( i = 0; i < cnt1; ++i ){
		nowNode(ansList1, i);
		if( i < cnt1 - 1 ){
			nextNode(ansList1, i + 1);
		}else{
			cout<<"-1\n";
		}
	}

	for( i = 0; i < cnt2; ++i ){
		nowNode(ansList2, i);
		if( i < cnt2 - 1 ){
			nextNode(ansList2, i + 1);
		}else{
			cout<<"-1\n";
		}
	}

	return 0;
}
