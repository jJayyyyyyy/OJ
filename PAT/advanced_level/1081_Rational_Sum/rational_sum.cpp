#include <iostream>
#include <cstdio>
#define MAXSIZE 104
typedef long long ll;
using namespace std;

struct Num{
	ll up, down;
};

Num numList[MAXSIZE];

ll gcd(ll a, ll b){
	if( 0 == b){
		return a;
	}else{
		return gcd(b, a%b);
	}
}

ll lcm(ll a, ll b){
	return a * b / gcd(a, b);
}

int inc(Num & sigma, Num & num){
	ll up, down;
	down = lcm(sigma.down, num.down);
	up = sigma.up * down / sigma.down + num.up * down / num.down;
	sigma.up = up;
	sigma.down = down;

	return 0;
}

int simplize(Num & result){
	ll factor = gcd(result.up, result.down);
	result.up /= factor;
	result.down /= factor;
	return 0;
}

int stdPrint(Num & result){
	if( result.down < 0 ){
		result.up = -result.up;
		result.down = -result.down;
	}

	ll integer = result.up / result.down;
	result.up -= integer * result.down;

	if( integer != 0 ){
		printf("%lld", integer);
	}

	if( result.up != 0 ){
		printf(" %lld/%lld\n", result.up, result.down);
	}

	if( integer == 0 && result.up == 0 ){
		printf("0\n");
	}

	return 0;
}

int main(){
	int n, i;
	scanf("%d", &n);

	for( i=0; i<n; i++ ){
		scanf("%lld/%lld", &numList[i].up, &numList[i].down);
	}

	Num sigma = numList[0];
	for( i=1; i<n; i++ ){
		simplize(sigma);
		simplize(numList[i]);
		inc(sigma, numList[i]);
	}
	stdPrint(sigma);

	return 0;
}