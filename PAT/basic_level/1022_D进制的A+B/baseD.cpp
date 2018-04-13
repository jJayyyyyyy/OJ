#include <iostream>
#include <cstdio>
#define MAX 40
using namespace std;

int main(){
	int a=0, b=0, baseD=2;
	int sigma=0, remain=0, i=0;
	int output[MAX]={0};

	scanf("%d%d%d", &a, &b, &baseD);
	sigma = a + b;
	if( 0==sigma ){
		printf("0");
		return 0;
	}

	if( 10==baseD ){
		printf("%d\n", sigma);
		return 0;
	}

	while( sigma!=0 ){
		remain = sigma % baseD;
		output[i++] = remain;
		sigma /= baseD;
	}

	while( i!=0 ){
		i--;
		printf("%d", output[i]);
	}

	return 0;
}