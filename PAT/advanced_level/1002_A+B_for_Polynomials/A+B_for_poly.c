#include <stdio.h>

int main(){
	double num_A[1004]={0}, num_B[1004]={0}, num_sum[1004]={0};
	int us_KA=0, us_KB=0, i=0, us_N=0, max=0, cnt=0;

	scanf("%d", &us_KA);
	for( i=0; i<us_KA; i++ ){
		scanf("%d", &us_N);
		if( max<us_N)
			max = us_N;
		scanf("%lf", &num_A[us_N]);
	}

	scanf("%d", &us_KB);
	for( i=0; i<us_KB; i++ ){
		scanf("%d", &us_N);
		if( max<us_N)
			max = us_N;
		scanf("%lf", &num_B[us_N]);
	}

	for( i=0; i<=max; i++ ){
		num_sum[i] = num_A[i] + num_B[i];
		if( num_sum[i]!=0 )
			cnt++;
	}

	printf("%d", cnt);
	for( i=max; i>=0; i-- ){
		if( num_sum[i]!=0 )
			printf(" %d %.1lf", i, num_sum[i]);
	}

	return 0;
}
