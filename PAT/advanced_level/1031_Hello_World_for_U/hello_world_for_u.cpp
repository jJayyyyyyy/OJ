#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char str[128];
	scanf("%s", str);
	int len = strlen(str);
	int n1, n2, n3;
	n2 = ( len + 4 ) / 3;   // 3*n2 >= N + 2, use (N+4) to get min int n2
	if( (len - n2)%2 ){
		n2 ++;
	}

	n1 = n3 = (len - n2) / 2;
	int i=0;
	for( i=0; i<n1; i++ ){
		printf("%c%*c\n", str[i], n2-1, str[len-1-i]);
	}

	for( i=n1; i<n1+n2; i++ ){
		printf("%c", str[i]);
	}

	return 0;
}

/*
case:

123456
*/