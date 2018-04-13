#include <stdio.h>
#define MAXNUM 1500

int init_num_list(int num_list[]){
	int num=1, a=3, i=0;
	for(i=0; num<MAXNUM; i++){
		num_list[i] = num;
		num += a*2;
		a += 2;
	}
	return 1;
}

int get_middle(int num_list[], int num){
	int i=0;
	while( num>=num_list[i] )
		i++;

	return i-1;
}

int init_hour_glass(char hour_glass[], char ch, int len){
	int i=0;
	for( i=0; i<len; i++ )
		hour_glass[i] = ch;
	hour_glass[i]='\0';

	return 1;
}

int print_upper(char hour_glass[], int middle){
	int i=0;

	for( i=middle; i>0; i--){
		printf("%s\n", hour_glass);
		hour_glass[middle-i] = ' ';
		hour_glass[middle+i] = '\0';
	}
	return 1;
}

int print_middle(char hour_glass[]){
	printf("%s\n", hour_glass);
	return 1;
}

int print_lower(char hour_glass[], int middle, char ch){
	int i=0;

	for( i=1; i<=middle; i++){
		hour_glass[middle-i] = ch;
		hour_glass[middle+i] = ch;
		printf("%s\n", hour_glass);
	}
	return 1;
}

int main(){
	int num_list[40]={0}, middle=0, len=0, us_num=0;
	char hour_glass[100]={0}, us_ch=0;

	scanf("%d %c", &us_num, &us_ch);
	init_num_list(num_list);

	middle = get_middle(num_list, us_num);
	len = middle*2 + 1;

	init_hour_glass(hour_glass, us_ch, len);
	print_upper(hour_glass, middle);
	print_middle(hour_glass);
	print_lower(hour_glass, middle, us_ch);

	printf("%d\n", us_num - num_list[middle]);
	return 0;
}

/*
1 7 17 31 49 71 97 127 161 199 241 287 337 391 449 511 577 647 721 799 881 967
*/
