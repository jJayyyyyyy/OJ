#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

ll gcd(ll a, ll b){
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

typedef struct{
	ll up;
	ll down;
}Num;

Num simplize(Num n){
	Num res = n;
	ll divi;
	if( res.down<0 ){
		res.down = -res.down;
		res.up = -res.up;
	}

	if( res.up==0 ){
		res.down = 1;
	}else{
		divi = gcd( labs(res.up), res.down );
		res.up /= divi;
		res.down /= divi;
	}

	return res;
}

Num plus(Num n1, Num n2){
	Num res;
	res.up = n1.up * n2.down + n2.up * n1.down;
	res.down = n1.down * n2.down;
	return simplize(res);
}

Num minus(Num n1, Num n2){
	Num res;
	res.up = n1.up*n2.down - n2.up*n1.down;
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

int stdPrint(Num n){
	Num res = simplize(n);

	if( res.up<0 )
		printf("(");

	if( res.down==1 )
		printf("%lld", res.up);
	else if( labs(res.up)<res.down )
		printf("%lld/%lld", res.up, res.down);
	else
		printf("%lld %lld/%lld", res.up / res.down, labs(res.up) % res.down, res.down);

	if( res.up<0 )
		printf(")");

	return 1;
}

int main(){
	Num n1, n2;
	scanf("%lld/%lld %lld/%lld", &n1.up, &n1.down, &n2.up, &n2.down);

	stdPrint(n1);
	printf(" + ");
	stdPrint(n2);
	printf(" = ");
	stdPrint( plus(n1, n2) );
	printf("\n");

	stdPrint(n1);
	printf(" - ");
	stdPrint(n2);
	printf(" = ");
	stdPrint( minus(n1, n2) );
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
	if( n2.up==0 )
		printf("Inf");
	else
		stdPrint( divide(n1, n2) );

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
