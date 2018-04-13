#include <cstdio>
#define MAXPAIRS 100004
#define MAXGUESTS 100004
using namespace std;

struct Person{
	int hasMate = 0;
	int mateId = -1;
	int set(int has, int id){
		hasMate = has;
		mateId = id;
	}
};
Person person[MAXPAIRS];
int guest[MAXGUESTS]={0};
int single[MAXGUESTS]={0};

int main(){
	int n, m, i, id, id1, id2, maxId=0, cnt=0, is_first=1;
	scanf("%d", &n);
	for( i=0; i<n; i++ ){
		scanf("%d%d", &id1, &id2);
		person[id1].set(1, id2);
		person[id2].set(1, id1);
	}
	scanf("%d", &m);
	for( i=0; i<m; i++){
		scanf("%d", &id);
		guest[id] = 1;
		if( maxId<id )
			maxId = id;
	}
	i=0;
	for( id=0; id<=maxId; id++ ){
		if( 1==guest[id] ){
			if( 1==person[id].hasMate ){
				if( 0==guest[person[id].mateId] ){
					cnt++;
					single[i++] = id;
				}
			}else{
				cnt++;
				single[i++] = id;
			}
		}
	}
	printf("%d\n", cnt);
	for( i=0; i<cnt; i++ ){
		if(is_first){
			printf("%05d", single[i]);
			is_first = 0;
		}else{
			printf(" %05d", single[i]);
		}
	}

	return 0;
}
