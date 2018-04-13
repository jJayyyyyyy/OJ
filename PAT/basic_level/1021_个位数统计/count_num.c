#include <stdio.h>
#define MAX 1001

int main(){
	char us_num[MAX];
	int cnt[10]={0}, n=0;
	int i=0;

	for(i=0; i<10; i++){
		cnt[i]=0;
	}
	i=0;

	scanf("%s", us_num);
	while( us_num[i]!='\0' ){
		n = us_num[i++] - '0';
		cnt[n]++;
	}

	for(i=0; i<10; i++){
		if( cnt[i] )
			printf("%d:%d\n", i, cnt[i]);
	}

	return 0;
}
