#include <stdio.h>

int main(int argc, char *argv[]){
	int arr[101]={0}, us_N=0, us_shift=0;
	int i=0, r_shift=0, is_start=1;

	scanf("%d%d", &us_N, &us_shift);
	while( i<us_N ){
		scanf("%d", &arr[i++]);
	}
	us_shift = us_shift % us_N;
	r_shift = us_N - us_shift;

	for( i=r_shift; i<us_N; i++ ){
		if(is_start){
			printf("%d", arr[i]);
			is_start = 0;
		}else
			printf(" %d", arr[i]);
	}

	for(i=0; i<r_shift; i++)
		if(is_start){
			printf("%d", arr[i]);
			is_start = 0;
		}else
			printf(" %d", arr[i]);

	return 0;
}
