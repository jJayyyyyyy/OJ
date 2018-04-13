#include <stdio.h>
#define MAX 101

int main(int argc, char *argv[]){
	const char *num_pinyin[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	char us_num[MAX];
	int sigma=0, i=0;
	scanf("%s", us_num);

	while( us_num[i]!='\0' )
		sigma += (us_num[i++]-'0');

	i=0;
	sprintf(us_num, "%d", sigma);

	while(us_num[i+1]!='\0')
		printf("%s ", num_pinyin[us_num[i++]-'0']);
	printf("%s", num_pinyin[us_num[i]-'0']);

	return 0;
}
