#include <stdio.h>
#define MAX 100004
int school[MAX]={0};

int main(){
	int us_N, i, id, max_id=0, champion_id=0, score;

	scanf("%d", &us_N);
	for( i=0; i<us_N; i++ ){
		scanf("%d%d", &id, &score);
		school[id] += score;
		if( max_id<id )
			max_id = id;
	}

	for( i=1; i<=max_id; i++ ){
		if( school[champion_id]<school[i] )
			champion_id = i;
	}

	printf("%d %d\n", champion_id, school[champion_id]);

	return 0;
}
// 12min
// like 1047
