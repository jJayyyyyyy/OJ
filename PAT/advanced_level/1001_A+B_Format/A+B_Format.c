#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int a=0, b=0, sum=0, len=0, i=0, first_comma=0;
	char str_num[10]={0}, *num;

	scanf("%d%d", &a, &b);

	sum = a + b;
	if( sum<0 )
		printf("-");
	sum = abs(sum);

	if( sum<1000 )
		printf("%d\n", sum);
	else{
		sprintf(str_num, "%d", sum);
		len = strlen(str_num);

		first_comma = len%3;
		if( first_comma==0 )
			first_comma = 3;
		for( i=0; i<first_comma; i++ )
			printf("%c", str_num[i]);

		num = &str_num[i];
		while( *num!='\0' ){
			printf(",%c%c%c", num[0], num[1], num[2]);
			num = &num[3];
		}
	}

	return 0;
}
