#include <stdio.h>

int print_first_line(int col, char ch){
	int i=0;
	for(i=0; i<col; i++){
		printf("%c", ch);
	}
	printf("\n");

	return 0;
}

int print_middle_lines(int col, int row, char ch){
	int i=0, j=0;
	for(i=0; i<row-2; i++){
		printf("%c", ch);
		for(j=0; j<col-2; j++)
			printf(" ");
		printf("%c\n", ch);
	}

	return 0;
}

int print_last_line(int col, char ch){
	print_first_line(col, ch);
	return 0;
}

int main(){
	int us_N=0;
	char us_ch=0;
	int col=0, row=0;
	int i=0;

	scanf("%d %c", &us_N, &us_ch);
	col = us_N;
	if(col%2)
		row = col/2 + 1;
	else
		row = col/2;

	print_first_line(col, us_ch);
	print_middle_lines(col, row, us_ch);
	print_last_line(col, us_ch);

	return 0;
}
