#include <stdio.h>

int main(){
	unsigned char us_a[1001], ans_q[1001];
	int a=0, b=0, q=0, r=0;
	int i=0, j=0;

	scanf("%s %d", us_a, &b);
	while( us_a[i]!='\0' ){
		a = us_a[i++] - '0' + r*10;
		q = a / b;
		r = a % b;
		ans_q[j++] = q + '0';
	}
	ans_q[j] = '\0';

	if( j==1 || ans_q[0]!='0' ){
		printf("%s %d", ans_q, r);
	}else{
		printf("%s %d", &ans_q[1], r);
	}

	return 0;
}
