#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX 100001

int main(int argc, char *argv[]){
	int i=0, j=0, up_bound=0;
	int us_N=0;
	int cnt=0;

	scanf("%d", &us_N);

	if(us_N<5){
		printf("0");
		return 0;
	}

	bool is_prime[MAX] = {false, false, true};
	for(i=3; i<MAX; i+=2){
		is_prime[i] = true;
		is_prime[i+1] = false;
	}
	up_bound = sqrt(MAX);
	for(i=3; i<=up_bound; i+=2){
		if(is_prime[i])
			for(j=i+i; j<MAX; j+=i)
				is_prime[j] = false;
	}

	for(i=5; i<=us_N; i+=2){
		if(is_prime[i] && is_prime[i-2]){
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}
