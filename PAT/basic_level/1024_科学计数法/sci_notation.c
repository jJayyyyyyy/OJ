#include <stdio.h>
#include <string.h>
#define MAX 10000

int main(){
	char us_input[MAX];
	char *p_E, *p_start;
	int expo=0, len=0, i=0;

	scanf("%s", us_input);

	p_start = us_input;
	p_E = strchr(us_input, 'E');
	p_E[0] = '\0';

	if( '-'==us_input[0] )
		printf("-");

	if( p_E[1]=='+' ){
		len = strlen( &us_input[3] );
		expo = atoi( &p_E[2] );
		printf("%c", us_input[1]);

		if( len>expo ){
			for( i=0; i<expo; i++ )
				printf("%c", us_input[i+3]);
			printf(".%s", &us_input[i+3]);
		}else{
			printf("%s", &us_input[3]);
			for(i=len; i<expo; i++)
				printf("0");
		}
	}else{
		expo = atoi(&p_E[2])-1;
		printf("0.");
		for(i=0; i<expo; i++)
			printf("0");
		printf("%c%s", us_input[1], &us_input[3]);
	}

	return 0;
}
