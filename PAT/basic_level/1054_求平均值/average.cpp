#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int us_N, i=0, j=0, cnt=0, is_equal=1;
	char str_num[100]={0}, str_in[100]={0};
	double sigma=0.0, num=0.0;

	scanf("%d", &us_N);
	for( i=0; i<us_N; i++ ){
		scanf("%s", str_in);
		sscanf(str_in, "%lf", &num);
		sprintf(str_num, "%.2lf", num);
		is_equal = 1;
		for( j=0; j<strlen(str_in); j++ ){
			if( str_in[j]!=str_num[j] )
				is_equal = 0;
		}
		if( is_equal==0 || num<-1000 || num>1000 ){
			printf("ERROR: %s is not a legal number\n", str_in);
		}else{
			sigma += num;
			cnt++;
		}
	}

	if( cnt>1 )
		printf("The average of %d numbers is %.2lf", cnt, sigma/cnt);
	else if( cnt==1 )
		printf("The average of 1 number is %.2lf", sigma);
	else
		printf("The average of 0 numbers is Undefined");

	return 0;
}
