/*
https://baike.baidu.com/item/%E4%BA%8C%E6%AC%A1%E5%86%8D%E6%95%A3%E5%88%97%E6%B3%95/
Quadratic probing, 平方再散列
H(key) = [ H(key) + i^2 ] % P, i∈[0, P)

Hash表的平均查找长度ASL计算方法
https://blog.csdn.net/u013806583/article/details/52643541

*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

int MAXSIZE;
int msize, n, m;

vector<bool> primeList;

void getPrimeList(){
	primeList[2] = true;

	for( int i = 3; i < MAXSIZE; i += 2 ){
		primeList[i] = true;
		primeList[i + 1] = false;
	}

	int upper = (int)sqrt(MAXSIZE);
	for( int i = 3; i < upper; i += 2 ){
		if( primeList[i] == true ){
			for( int j = i + i; j < MAXSIZE; j += i ){
				primeList[j] = false;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>msize>>n>>m;

	MAXSIZE = n + 10000;
	primeList.resize(MAXSIZE);
	getPrimeList();

	int P;
	for( int i = msize; i < MAXSIZE; i++ ){
		if( primeList[i] == true  && i >= n ){
			P = i;
			break;
		}
	}
	

	vector<int> hashtable(P, 0);
	for( int i = 0; i < n; i++ ){
		int val;
		cin>>val;

		int j;
		for( j = 0; j < P; j++ ){
			int pos = (val + j*j) % P;
			if( hashtable[pos] == 0 ){
				hashtable[pos] = val;
				break;
			}
		}
		if( j == P ){
			cout<<val<<" cannot be inserted.\n";
		}
	}

	double sum = 0.0;
	for( int i = 0; i < m; i++ ){
		int val;
		cin>>val;

		int j = 0;
		for( ; j < P; j++ ){
			int pos = (val + j*j) % P;
			if( hashtable[pos] == val || hashtable[pos] == 0 ){
				break;
			}
		}
		sum += j + 1;
	}

	sum /= m;
	cout<<fixed<<setprecision(1)<<sum<<'\n';
	return 0;
}

/*
4 5 4
10 6 4 15 11
11 4 15 2


https://pintia.cn/problem-sets/994805342720868352/problems/994805343236767744
*/