#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *place_low[]={"0", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const char *place_high[]={"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int cnv13to10(const int base_13[]){
	int base_10 = base_13[0]*13 + base_13[1];
	printf("%d\n", base_10);

	return 0;
}

int cnv10to13(const int base_10){
	int high=0, low=0;

	low = base_10 % 13;
	high = (base_10 - low) / 13;

	if( 0==low )
		printf("%s\n", place_high[high]);
	else if( 0==high )
		printf("%s\n", place_low[low]);
	else
		printf("%s %s\n", place_high[high], place_low[low]);

	return 0;
}

int earth2mars(char s[]){
	cnv10to13(atoi(s));
	return 0;
}

int mars2earth(char s[]){
	int base_13[2]={0, 0}, i=0;

	switch(strlen(s)){
		case 4:
			base_13[0] = 0;
			base_13[1] = 0;
			break;
		case 3:
			for( i=1; i<13; i++ )
				if( 0==strcmp(s, place_high[i]) ){
					base_13[0] = i;
					break;
				}
			for( i=1; i<13; i++ )
				if( 0==strcmp(s, place_low[i]) ){
					base_13[1] = i;
					break;
				}
			break;
		case 7:
			s[3] = '\0';
			for( i=1; i<13; i++ )
				if( 0==strcmp(s, place_high[i]) ){
					base_13[0] = i;
					break;
				}
			for( i=1; i<13; i++ )
				if( 0==strcmp(&s[4], place_low[i]) ){
					base_13[1] = i;
					break;
				}
			break;
	}

	cnv13to10(base_13);
	return 0;
}

int get_input(char s[]){
	char *p;

	fgets(s, 10, stdin);
	p = strchr(s, '\n');
	*p = '\0';
	return 0;
}

int main(){
	int us_N=0, i=0;
	char s[10]={0};

	// scanf("%d", &us_N);
	// getchar();
	// for( i=0; i<us_N; i++ ){
		while(1){get_input(s);
		if(isdigit(s[0]))
			earth2mars(s);
		else
			mars2earth(s);
	}

	return 0;
}


/*
4
29
5
elo nov
tam


*/
