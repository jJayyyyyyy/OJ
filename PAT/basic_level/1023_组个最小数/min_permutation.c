#include <stdio.h>

int main(){
	int i;
    int numList[16];

	for(i=0; i<10; i++){
		scanf("%d", &numList[i]);
	}

	for(i=1; i<10; i++){
		if( 0!=numList[i] ){
			printf("%d", i);
            numList[i]--;
			break;
		}
	}

	for(i=0; i<10; i++){
		while( 0!=numList[i] ){
			printf("%d", i);
			numList[i]--;
		}
	}

	return 0;
}
