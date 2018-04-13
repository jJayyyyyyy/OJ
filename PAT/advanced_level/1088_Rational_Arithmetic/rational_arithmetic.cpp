#include <cstdio>
#include <cstdlib>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
	if( 0 == b ){
		return a;
	}else{
		return gcd(b, a%b);
	}
}

struct Num{
	ll up, down;
};

Num simplize(Num n){
	Num res = n;
	ll divi;

	if( res.down < 0 ){
		res.down = -res.down;
		res.up = -res.up;
	}

	if( 0 == res.up ){
		res.down = 1;
	}else{
		divi = gcd( abs(res.up), res.down );
		res.up /= divi;
		res.down /= divi;
	}

	return res;
}

int stdPrint(Num n){
	Num res = simplize(n);

	if( res.up < 0 ){
		printf("(");
	}
	if( 1 == res.down ){
		printf("%lld", res.up);
	}else if( abs(res.up) < res.down ){
		printf("%lld/%lld", res.up, res.down);
	}else{
		printf( "%lld %lld/%lld", res.up / res.down, abs(res.up) % res.down, res.down );
	}
	if( res.up < 0 ){
		printf(")");
	}
	return 1;
}

Num add(Num n1, Num n2){
	Num res;
	res.up = n1.up * n2.down + n2.up * n1.down;
	res.down = n1.down * n2.down;
	return simplize(res);
}

Num subtract(Num n1, Num n2){
	Num res;
	res.up = n1.up * n2.down - n2.up * n1.down;
	res.down = n1.down * n2.down;
	return simplize(res);
}

Num multi(Num n1, Num n2){
	Num res;
	res.up = n1.up * n2.up;
	res.down = n1.down * n2.down;
	return simplize(res);
}

Num divide(Num n1, Num n2){
	Num res;
	res.up = n1.up * n2.down;
	res.down = n1.down * n2.up;
	return simplize(res);
}

int main(){
	Num n1, n2;
	scanf("%lld/%lld %lld/%lld", &n1.up, &n1.down, &n2.up, &n2.down);

	stdPrint(n1);
	printf(" + ");
	stdPrint(n2);
	printf(" = ");
	stdPrint( add(n1, n2) );
	printf("\n");

	stdPrint(n1);
	printf(" - ");
	stdPrint(n2);
	printf(" = ");
	stdPrint( subtract(n1, n2) );
	printf("\n");

	stdPrint(n1);
	printf(" * ");
	stdPrint(n2);
	printf(" = ");
	stdPrint( multi(n1, n2) );
	printf("\n");

	stdPrint(n1);
	printf(" / ");
	stdPrint(n2);
	printf(" = ");
	if( n2.up==0 ){
		printf("Inf");
	}else{
		stdPrint( divide(n1, n2) );
	}
	return 0;
}


/*
2147483647/2147483646 -2147483647/2147483645

1 1/2147483646 + (-1 2/2147483645) = (-2147483647/4611686007689969670)
1 1/2147483646 - (-1 2/2147483645) = 2 6442450937/4611686007689969670
1 1/2147483646 * (-1 2/2147483645) = (-1 6442450939/4611686007689969670)
1 1/2147483646 / (-1 2/2147483645) = (-2147483645/2147483646)


4611686007689969670*2 + 6442450937 = 9223372021822390277
2 6442450937/4611686007689969670

*/
