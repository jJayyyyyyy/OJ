#include <iostream>
#include <algorithm>
#define MAXSIZE 100004
using namespace std;
typedef long long ll;

ll couponP[MAXSIZE] = {0};
ll couponN[MAXSIZE] = {0};
ll productP[MAXSIZE] = {0};
ll productN[MAXSIZE] = {0};

int cmp(ll a, ll b){
	return a > b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int nc, np, i;
	int cntCP=0, cntCN=0, cntPP=0, cntPN=0;
	ll val;
	cin>>nc;
	for( i = 0; i < nc; ++i ){
		cin>>val;
		if( val >= 0 ){
			couponP[cntCP++] = val;
		}else{
			couponN[cntCN++] = -val;
		}
	}

	cin>>np;
	for( i = 0; i < np; ++i ){
		cin>>val;
		if( val >= 0 ){
			productP[cntPP++] = val;
		}else{
			productN[cntPN++] = -val;
		}
	}

	sort(couponP, couponP + cntCP, cmp);
	sort(couponN, couponN + cntCN, cmp);
	sort(productP, productP + cntPP, cmp);
	sort(productN, productN + cntPN, cmp);

	ll total = 0;
	int positive = min(cntCP, cntPP);
	int negative = min(cntCN, cntPN);
	for( i = 0; i < positive; ++i ){
		total += couponP[i] * productP[i];
	}
	for( i = 0; i < negative; ++i ){
		total += couponN[i] * productN[i];
	}

	cout<<total<<'\n';

	return 0;
}
