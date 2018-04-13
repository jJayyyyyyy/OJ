#include <stdio.h>
#define MAX 100005

/*
 * sub_len = K
 * go_end = sum / K
 * has_remain = sum % K
*/
int reverse_print(const int ol[], const int data[], const int sub_len, const int go_end, const int has_remain){
	int ix=1, sub_begin=1, sub_end=0;
	int go=1;
	for( go=1; go<go_end; go++ ){
		sub_end += sub_len;
		sub_begin = sub_end - sub_len + 1;
		for( ix=sub_end; ix>sub_begin; ix-- )
			printf("%05d %d %05d\n", ol[ix], data[ ol[ix] ], ol[ix-1]);
		printf("%05d %d %05d\n", ol[ix], data[ ol[ix] ], ol[sub_end+sub_len]);
	}

	sub_end += sub_len;
	sub_begin = sub_end - sub_len + 1;
	for( ix=sub_end; ix>sub_begin; ix-- )
		printf("%05d %d %05d\n", ol[ix], data[ ol[ix] ], ol[ix-1]);

	if( has_remain )
		printf("%05d %d %05d\n", ol[ix], data[ ol[ix] ], ol[sub_end+1]);
	else
		printf("%05d %d -1", ol[ix], data[ ol[ix] ]);

	return 0;
}

int main(){
	int data[MAX]={0}, next[MAX]={0}, ol[MAX]={0};
	int us_N=0, us_K=0, sum=0;
	int start=0, addr=0, i=0, remain=0, go_end=0;

	scanf("%d%d%d", &start, &us_N, &us_K);
	for( i=0; i<us_N; i++){
		scanf("%d", &addr);
		scanf("%d%d", &data[addr], &next[addr]);
	}

	addr = start;
	for( i=1; -1!=next[addr]; i++ ){
		ol[i] = addr;
		addr = next[addr];
		sum++;
	}
	ol[i] = addr;
	sum++;

	if( sum>=us_K ){
		remain = sum % us_K;
		go_end = sum / us_K;
		reverse_print(ol, data, us_K, go_end, remain);
		if( 0!=remain ){
			i = sum - remain + 1;
			for( i; i<sum; i++ )
				printf( "%05d %d %05d\n", ol[i], data[ ol[i] ], ol[i+1]);
			printf( "%05d %d -1", ol[i], data[ ol[i] ]);
		}
	}else{
		// us_K > sum, then keep ol[]
		for( i=1; i<sum; i++ )
			printf("%05d %d %05d\n", ol[i], data[ol[i]], ol[i+1]);
		printf( "%05d %d -1", ol[i], data[ol[i]]);
	}


	return 0;
}


/*
00100 7 7
12345 7 54321
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

*/



