#include <cstdio>
#include <cmath>
#define MAX 10005
using namespace std;

struct Student{
	int is_member;
	int is_checked;
	int is_first;
	int is_prime;
	Student(): is_member(0), is_checked(0), is_first(0), is_prime(0){}
} stu[MAX];

int main(){
	int i=0, j=0, us_N=0, us_K=0, id=0, up_bound=sqrt(MAX);
	int is_prime[MAX]={0, 0, 1};
	for( i=3; i<MAX; i+=2 ){
		is_prime[i] = 1;
		is_prime[i+1] = 0;
	}
	for( i=3; i<=up_bound; i+=2 ){
		if( is_prime[i] )
			for( j=i+i; j<MAX; j+=i)
				is_prime[j] = 0;
	}

	scanf("%d", &us_N);

	scanf("%d", &id);
	stu[id].is_member = 1;
	stu[id].is_checked = 0;
	stu[id].is_first = 1;
	stu[id].is_prime = 0;
	for( i=2; i<=us_N; i++ ){
		scanf("%d", &id);
		stu[id].is_member = 1;
		stu[id].is_checked = 0;
		stu[id].is_first = 0;
		if( is_prime[i] )
			stu[id].is_prime = 1;
		else
			stu[id].is_prime = 0;
	}

	scanf("%d", &us_K);
	for( i=1; i<=us_K; i++ ){
		scanf("%d", &id);
		if( stu[id].is_member==1 ){
			if( stu[id].is_checked==1 ){
				printf("%04d: Checked\n", id);
			}else{
				stu[id].is_checked = 1;
				if( stu[id].is_first==1 ){
					printf("%04d: Mystery Award\n", id);
				}else{
					if( stu[id].is_prime==1 ){
						printf("%04d: Minion\n", id);
					}else{
						printf("%04d: Chocolate\n", id);
					}
				}
			}
		}else{
			printf("%04d: Are you kidding?\n", id);
		}
	}

	return 0;
}
// 1h, 17/20
/*
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222



8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?

*/


