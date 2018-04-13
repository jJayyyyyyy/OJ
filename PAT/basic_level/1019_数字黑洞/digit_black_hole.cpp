#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int decCmp(char a, char b){
	return a>b;
}

int decOutput(char str_num[]){
	sort(str_num, str_num+4, decCmp);
	printf("%s - ", str_num);
	return atoi(str_num);
}

int incOutput(char str_num[]){
	sort(str_num, str_num+4);
	printf("%s = ", str_num);
	return atoi(str_num);
}

int main(){
	int num, a, b;
	char str_num[5];

	scanf("%d", &num);
	sprintf(str_num, "%04d", num);

	if( str_num[0]==str_num[1] && str_num[0]==str_num[2] && str_num[0]==str_num[3] ){
		printf("%s - %s = 0000\n", str_num, str_num);
		return 0;
	}

	do{
		a = decOutput(str_num);
		b = incOutput(str_num);
		num = a - b;
		printf("%04d\n", num);
		sprintf(str_num, "%04d", num);
	}while(6174!=num);

	return 0;
}