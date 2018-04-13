#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, k, maxBaseSum = 0;
vector<int> fac, ansSeq, tmpSeq;

/*
 * fac[base] 的值为 base^Exp, 最大不超过n
 * 比如 n=33, Exp=2, 那么fac里面的内容是 0, 1, 4, 9, 25
 * 这样一次性计算完后, 下次就可以直接调用了，不用每次base^Exp都重新计算
 */
void initFac(int Exp){
	int base = 0;
	for( int val = 0; val <= n; val = pow(++base, Exp) ){
		fac.push_back(val);
	}
}

void DFS(int base, int cntK, int facSum, int baseSum){
	if( facSum == n && cntK == k ){
		if( baseSum > maxBaseSum ){
			maxBaseSum = baseSum;
			ansSeq = tmpSeq;
		}
		return;
	}else if( facSum > n || cntK > k ){
		return;
	}

	if( base >= 1 ){
		tmpSeq.push_back(base);
		// 先选中这个base，试探 baseSum 最大能到达的程度
		DFS(base, cntK + 1, facSum + fac[base], baseSum + base);
		tmpSeq.pop_back();
		// 要到底了，分叉口，不选这个base
		DFS(base - 1, cntK, facSum, baseSum);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Exp;
	cin>>n>>k>>Exp;
	initFac(Exp);

	// 根据题目要求, [和]相同的情况下, 序号小的[因子]要尽可能大
	// 所以 base = fac.size() - 1, 底数从大到小进行试探
	int base = fac.size() - 1;
	DFS( base, 0, 0, 0 );

	if( maxBaseSum == 0 ){
		cout<<"Impossible\n";
	}else{
		cout<<n<<" = "<<ansSeq[0]<<'^'<<Exp;
		for( int i = 1; i < k; ++i ){
			cout<<" + "<<ansSeq[i]<<'^'<<Exp;
		}
		cout<<'\n';
	}

	return 0;
}
