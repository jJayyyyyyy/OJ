#include <iostream>
#include <stack>
#include <algorithm>
#define MAXSIZE 100004
#define sqrtN 316
using namespace std;

stack<int> st;
int block[sqrtN] = {0};		// blcok[id] 表示第 id 号区块
int table[MAXSIZE]={0};		// table[i] 表示目前栈内数字 i 的个数

int push(int x){
	st.push(x);
	block[x / sqrtN]++;
	table[x]++;
	return 0;
}

int pop(){
	int x = st.top();
	cout<<x<<'\n';
	st.pop();
	block[x / sqrtN]--;
	table[x]--;
	return 0;
}

int peekMedian(int k){
	int sum = 0;
	int id = 0;
	while( sum + block[id] < k ){
		sum += block[id];
		id++;
	}

	int num = id * sqrtN;
	while( sum + table[num] < k ){
		sum += table[num];
		num++;
	}
	cout<<num<<'\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string oper;
	int n, i, x, k;
	cin>>n;

	for( i = 0; i < n; ++i ){
		cin>>oper;
		if( oper == "Push" ){
			cin>>x;
			push(x);
		}else if( oper == "Pop" ){
			if( st.empty() ){
				cout<<"Invalid\n";
			}else{
				pop();
			}
		}else{
			if( st.empty() ){
				cout<<"Invalid\n";
			}else{
				k = (st.size() + 1) / 2;
				peekMedian(k);
			}
		}
	}

	return 0;
}