#include <stdio.h>
#include <stdlib.h>
#define MAX 1004

typedef struct{
	double stock;
	double totalPrice;
	double unitPrice;
}Cake;

int getCakes(Cake cakes[], int n){
	int i=0;
	for( i=0; i<n; i++ ){
		scanf("%lf", &cakes[i].stock);
	}

	for( i=0; i<n; i++ ){
		scanf("%lf", &cakes[i].totalPrice);
		cakes[i].unitPrice = cakes[i].totalPrice / cakes[i].stock;
	}

	return 0;
}

int decCmp(const void *p1, const void *p2){
	const Cake *a1 = (const Cake *)p1;
	const Cake *a2 = (const Cake *)p2;

	if( a1->unitPrice > a2->unitPrice )
		return -1;
	else if( a1->unitPrice==a2->unitPrice )
		return 0;
	else
		return 1;
}

int main(){
	int us_N=0, demand=0;
	double maxPrice=0.0;
	Cake cakes[MAX];
	int i=0;

	scanf("%d%d", &us_N, &demand);
	getCakes(cakes, us_N);
	qsort(cakes, us_N, sizeof(Cake), decCmp);

	for( i=0; i<us_N; i++ ){
		if( demand>=cakes[i].stock ){
			maxPrice += cakes[i].totalPrice;
			demand -= cakes[i].stock;
		}else{
			maxPrice += demand * cakes[i].unitPrice;
			break;
		}
	}

	printf("%.2lf\n", maxPrice);
	return 0;
}