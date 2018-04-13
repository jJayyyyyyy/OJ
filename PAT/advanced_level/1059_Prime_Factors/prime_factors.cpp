#include <iostream>
#include <cmath>
#define MAXSIZE 150001
using namespace std;

struct Factor{
	int val;
	int cnt=0;
};

Factor facList[32];

bool indexList[MAXSIZE] = {false, false, true};
int primeList[MAXSIZE] = {2}, cntPrime=0;

int getPrimeList(){
	for( int i=3; i<MAXSIZE; i+=2 ){
		indexList[i] = true;
		indexList[i+1] = false;
	}

	int upperBound = (int)sqrt(MAXSIZE);
	for( int i=3; i<=upperBound; i+=2 ){
		if( true == indexList[i] ){
			for( int j=i+i; j<MAXSIZE; j+=i ){
				indexList[j] = false;
			}
		}
	}

	primeList[cntPrime++] = 2; 
	for( int i=3; i<MAXSIZE; i+=2 ){
		if( true == indexList[i] ){
			primeList[cntPrime++] = i;
		}
	}

	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	getPrimeList();
	int n, diffFac=0;	// n可以分解成diffFac种不同的质因子
	cin>>n;

	if( 1 == n ){
		cout<<"1=1\n";
	}else{
		cout<<n<<'=';
		int upperBound = (int)sqrt(n);
		for( int i=0; i<cntPrime && primeList[i]<=upperBound ; ++i ){
			int p = primeList[i];
			if( n % p == 0 ){	//  这里不能直接上while(), 否则diffFac会出错
				facList[diffFac].val = p;
				facList[diffFac].cnt = 0;
				while( n % p == 0){
					n = n / p;
					facList[diffFac].cnt++;
				}
				++diffFac;	// n可以分解成diffFac种不同的质因子
			}
			if( n == 1 ){
				break;
			}
		}

		if( n != 1 ){
			facList[diffFac].val = n;
			facList[diffFac].cnt = 1;
			++diffFac;
		}

		for( int i=0; i<diffFac; ++i ){
			if( i > 0 ){
				cout<<'*';
			}
			cout<<facList[i].val;
			if( facList[i].cnt > 1 ){
				cout<<'^'<<facList[i].cnt;
			}
		}
	}

	return 0;
}
