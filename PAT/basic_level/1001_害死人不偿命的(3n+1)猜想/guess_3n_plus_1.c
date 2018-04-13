#include <stdio.h>

int main(int argc, char * argv[]){
	int num=1, cnt=0;

	scanf("%d", &num);
	while( num!=1 ){
		if( 0==num%2 ){
			num /= 2;
		}else{
			num = num*3 + 1;
			num /= 2;
		}
		cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
