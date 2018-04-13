#include <stdio.h>

int main(int argc, char * argv[]){
	int i=0, n=0;
	scanf("%d", &n);
	long int a=0, b=0, c=0;

	for(i=0; i<n; i++){
		scanf("%ld%ld%ld", &a, &b, &c);
		if(a>2147483648||a<-2147483648||b>2147483648||b<-2147483648||c>2147483648||c<-2147483648){
			printf("Case #%d: false\n", i+1);
		}else if((a+b)>c){
			printf("Case #%d: true\n", i+1);
		}else{
			printf("Case #%d: false\n", i+1);
		}
	}

	return 0;
}
