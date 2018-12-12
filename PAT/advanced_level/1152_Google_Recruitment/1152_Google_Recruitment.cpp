/*
输入 L 和 K, 还有一个数字 N, L==N.size()
求出N中第一个K位的素数

本题与以往的判断素数的题略有不同
由于K的取值很大, 可以达到 10^10 的级别
而输入的组数较少, 且个人猜测就算是 L 大 K 大的 case, 也不是特别极端
因此不适合用 筛表法, (准确地说, 用筛表法去适配K时无法通过编译

而用最基本的方法判断素数时, 对应本题的case, 耗时不多
因此两种模板都需要掌握以便灵活运用

1. 基本方法

bool isPrime(int num){
	if( num == 0 || num == 1 ){
		return false;
	}

	for( int i = 2; i * i <= num; i++ ){
		if( num % i == 0 ){
			return false;
		}
	}

	return true;
}

2. 筛表法, 找出MAXSIZE以内的素数, 注意MAXSIZE应为奇数

#define MAXSIZE 100003
bool primeList[MAXSIZE] = {false, false, true};

void getPrimeList(){
	for( int i = 3; i < MAXSIZE; i += 2 ){
		primeList[i] = true;
		primeList[i + 1] = false;
	}

	int upperBound = (int) sqrt(MAXSIZE);
	for( int i = 3; i < upperBound; i += 2){
		if( primeList[i] == true ){
			for( int j = i + i; j < MAXSIZE; j += i ){
				primeList[j] = false;
			}
		}
	}
}
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

bool isPrime(int num){
	if( num == 0 || num == 1 ){
		return false;
	}

	for( int i = 2; i * i <= num; i++ ){
		if( num % i == 0 ){
			return false;
		}
	}

	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int L, K;
	string strN;
	cin>>L>>K>>strN;

	int len = L - K;

	for(int i = 0; i <= len; i++ ){
		string subs = strN.substr(i, K);
		int num = stoi(subs);
		if( isPrime(num) == true ){
			cout<<subs<<'\n';
			return 0;
		}
	}

	cout<<"404\n";
	return 0;
}
