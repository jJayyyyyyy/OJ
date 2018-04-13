#include <stdio.h>
#define MAX 10010

int main(){
	int us_N, member, score, i=0, team_id, max_num=0, champion_id=0;
	int team[MAX]={0};

	scanf("%d", &us_N);
	for( i=0; i<us_N; i++ ){
		scanf("%d-%d%d", &team_id, &member, &score);
		team[team_id] += score;
		if( max_num<team_id )
			max_num = team_id;
	}

	for( i=1; i<=max_num; i++){
		if( team[champion_id]<team[i] )
			champion_id = i;
	}

	printf("%d %d\n", champion_id, team[champion_id]);
	return 0;
}

// 14min
