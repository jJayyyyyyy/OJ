#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX 150001

int main(){
	int i=0, j=0;
	int up_bound=0;
	int us_pm=0, us_pn=0, cnt=0, line_cnt=0;
	unsigned long int num=2;

	scanf("%d %d", &us_pm, &us_pn);

	bool prime_list[MAX]={false, false, true};
	for(i=3; i<MAX; i+=2){
		prime_list[i] = true;
		prime_list[i+1] = false;
	}

	up_bound = (int)sqrt(MAX);
	for(i=3; i<=up_bound; i+=2){
		if(prime_list[i])
			for(j=i+i; j<MAX; j+=i)
				prime_list[j]=false;
	}

	while(1){
		if(prime_list[num]){
			cnt++;
		}
		if(us_pm == cnt){
			printf("%lu", num);
			line_cnt++;
			num++;
			break;
		}
		num++;
	}

	if (us_pm >= us_pn){
		return 0;
	}

	while(1){
		if(prime_list[num]){
			if (9 == line_cnt){
				printf(" %lu\n", num);
				line_cnt = 0;
			}else{
				(line_cnt)?printf(" %lu", num):printf("%lu", num);
				line_cnt++;
			}
			cnt++;
			if(us_pn == cnt){
				break;
			}
		}
		num++;
	}
	return 0;
}
