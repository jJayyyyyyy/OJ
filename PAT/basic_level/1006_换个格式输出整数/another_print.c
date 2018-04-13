#include <stdio.h>

int main(int argc, char *argv[]){
	int us_num=0;
	int p_hundreds=0, p_tens=0, p_units=0;
	int i=0;

	scanf("%d", &us_num);
	p_hundreds = us_num/100;
	p_tens = us_num%100/10;
	p_units = us_num%10;

	if(p_hundreds){
		for(i=0; i<p_hundreds; i++)
			printf("B");
		for(i=0; i<p_tens; i++)
			printf("S");
		for(i=0; i<p_units; i++)
			printf("%d", i+1);
	}else if(p_tens){
		for(i=0; i<p_tens; i++)
			printf("S");
		for(i=0; i<p_units; i++)
			printf("%d", i+1);
	}else{
		for(i=0; i<p_units; i++)
			printf("%d", i+1);
	}

	return 0;
}
