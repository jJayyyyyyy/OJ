#include <stdio.h>

int main(int argc, char * argv[]){
	int us_N=0, us_input=0;
	int a[5]={0}, cnt[5]={0};
	int i=0,  multi=1;

	scanf("%d", &us_N);
	while( i++<us_N ){
		scanf("%d", &us_input);
		if( 0==us_input%10 ){
			a[0] += us_input;
			cnt[0]++;
		}
		if( 1==us_input%5 ){
			a[1] += us_input * multi;
			multi = -multi;
			cnt[1]++;
		}
		if( 2==us_input%5 ){
			a[2]++;
			cnt[2]++;
		}
		if( 3==us_input%5 ){
			a[3] += us_input;
			cnt[3]++;
		}
		if( 4==us_input%5 ){
			if( a[4]<us_input )
				a[4] = us_input;
			cnt[4]++;
		}
	}

	if(0 == cnt[0]){
		printf("N ");
	}else{
		printf("%d ", a[0]);
	}
	if(0 == cnt[1]){
		printf("N ");
	}else{
		printf("%d ", a[1]);
	}
	if(0 == cnt[2]){
		printf("N ");
	}else{
		printf("%d ", a[2]);
	}
	if(0 == cnt[3]){
		printf("N ");
	}else{
		printf("%.1f ", a[3]*1.0/cnt[3]);
	}
	if(0 == cnt[4]){
		printf("N");
	}else{
		printf("%d", a[4]);
	}

	return 0;
}
