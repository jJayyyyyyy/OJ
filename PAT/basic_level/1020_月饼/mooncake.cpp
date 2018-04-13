#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 1004
using namespace std;

struct Cake{
	double stock;
	double totalPrice;
	double unitPrice;
};

int getCakes(Cake *cakes, int n){
	int i;

	for( i=0; i<n; i++ ){
		scanf("%lf", &cakes[i].stock);
	}

	for( i=0; i<n; i++ ){
		scanf("%lf", &cakes[i].totalPrice);
		cakes[i].unitPrice = cakes[i].totalPrice / cakes[i].stock;
	}

	return 0;
}

int decCmp(Cake a, Cake b){
	return a.unitPrice > b.unitPrice;
}

int main(){
	int us_N, demand=0;
	double maxPrice=0.0;
	Cake cakes[MAX];

	scanf("%d%d", &us_N, &demand);
	getCakes(cakes, us_N);
	sort(cakes, cakes+us_N, decCmp);

	for( int i=0; i<us_N; i++ ){
		if( demand>=cakes[i].stock ){
			maxPrice += cakes[i].totalPrice;
			demand -= cakes[i].stock;
		}else{
			maxPrice += demand * cakes[i].unitPrice;
			break;
		}
	}

	printf("%.2f\n", maxPrice);
	return 0;
}