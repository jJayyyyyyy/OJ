#include <stdio.h>
#include <math.h>

int is_prime(int num){
	int di=1, up_bound=1;

	if( num>2 && num%2 ){
		up_bound = (int)sqrt(num);
		for( di=3; di<=up_bound; di+=2)
			if( 0==num%di )
				return 0;
		return 1;
	}else if( num==2 ){
		return 1;
	}else{
		return 0;
	}
}

int cnv10toD(int base_10, int base, int base_d[], int *len){
	int i=0;
	for( i=0; base_10!=0; i++){
		base_d[i] = base_10 % base;
		base_10 /= base;
	}

	*len = i;
	return 1;
}

int cnvDto10(int *base_10, int base, const int base_d[], int len){
	int i=0;
	int result=0, n=0;

	for( i=len-1; i>=0; i-- ){
		result += (base_d[i]) * pow(base, n++);
	}

	*base_10 = result;
	return 1;
}

int main(){
	int base_10=0, len=0;
	int base_d[20]={0};
	int us_N=0, us_D=0;

	while(1){
		scanf("%d", &base_10);
		if(base_10<0)
			break;
		else{
			scanf("%d", &us_D);
			if(is_prime(base_10)){
				cnv10toD(base_10, us_D, base_d, &len);
				cnvDto10(&base_10, us_D, base_d, len);
				if(is_prime(base_10))
					printf("Yes\n");
				else
					printf("No\n");
			}else
				printf("No\n");
		}
	}

	return 0;
}



/*
73 10
23 2
23 10
-2



*/
