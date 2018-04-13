#include <stdio.h>
#include <math.h>

int is_prime(int num){
	int up_bound=1, divisor=1;
	if( 2<num && num%2){
		up_bound = (int)sqrt(num);
		for(divisor=3; divisor<=up_bound; divisor+=2){
			if( 0 == num % divisor )
				return 0;
		}
		return 1;
	}else if(2 == num)
		return 1;
	else
		return 0;
}

int main(){
	int us_pm=0, us_pn=0, num=2, cnt=0, line_cnt=0;
	scanf("%d %d", &us_pm, &us_pn);

	while(1){
		if (is_prime(num)){
			cnt++;
		}
		if (us_pm == cnt){
			printf("%d", num);
			line_cnt++;
			num++;
			break;
		}
		num++;
	}

	if (us_pm == us_pn){
		return 0;
	}

	while(1){
		if(is_prime(num)){
			if (9 == line_cnt){
				printf(" %d\n", num);
				line_cnt = 0;
			}else{
				(line_cnt)?printf(" %d", num):printf("%d", num);
				line_cnt++;
			}
			cnt++;
			if(us_pn == cnt)
				break;
		}
		num++;
	}
	return 0;
}
