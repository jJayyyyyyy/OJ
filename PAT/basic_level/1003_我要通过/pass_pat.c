#include <stdio.h>
#define MAX 101

int correct_cnt(const char *us_str, int *posi_p, int *posi_t);
int correct_order(const int posi_p, const int posi_t);
int correct_logic(const char *us_str);

int main(){
	int posi_p=0, posi_t=0;
	int i=0;
	int us_N=0;
	char us_str[MAX];

	scanf("%d", &us_N);
	if(us_N>=10){
		printf("NO\n");
		return 0;
	}

	for(i=0; i<us_N; i++){
		scanf("%s", us_str);
		if( correct_cnt(us_str, &posi_p, &posi_t) ){
			if( correct_order(posi_p, posi_t) ){
				if( correct_logic(us_str) ){
					printf("YES\n");
				}else{
					printf("NO\n");
				}
			}else{
				printf("NO\n");
			}
		}else{
			printf("NO\n");
		}
	}

	return 0;
}

int correct_cnt(const char *us_str, int *posi_p, int *posi_t){
	int cnt_p=0, cnt_a=0, cnt_t=0;
	int i=0;

	while( us_str[i]!='\0' ){
		if( us_str[i]=='P' ){
			cnt_p++;
			*posi_p = i;
		}else if( us_str[i]=='A' ){
			cnt_a++;
		}else if( us_str[i]=='T' ){
			cnt_t++;
			*posi_t = i;
		}else{
			return 0;
		}
		i++;
	}

	if( 1!=cnt_p ){
		return 0;
	}else if( 0==cnt_a ){
		return 0;
	}else if( 1!=cnt_t ){
		return 0;
	}else{
		return 1;
	}
}

int correct_order(const int posi_p, const int posi_t){
	return (posi_p+1) < posi_t;
}

int correct_logic(const char *us_str){
	int cnt_a1=0, cnt_a2=0, cnt_a3=0;
	int i=0;

	while( us_str[i++]!='P' ){
		cnt_a1++;
	}

	while( us_str[i++]!='T' ){
		cnt_a2++;
	}

	while( us_str[i++]!='\0' ){
		cnt_a3++;
	}

	if( cnt_a1*cnt_a2==cnt_a3 )
		return 1;
	else
		return 0;
}


/*
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA


*/
