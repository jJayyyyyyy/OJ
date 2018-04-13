#include <stdio.h>
#include <string.h>

int main(){
	char str[100], *p_find;
	int i=0;

	fgets(str, 81, stdin);

	p_find = strrchr(str, '\n');
	if(p_find){
		p_find[0] = '_';
		p_find[1] = '\0';
	}else{
		p_find = strrchr(str, '\0');
		if(p_find){
			p_find[0] = '_';
			p_find[1] = '\0';
		}
	}

	while(1){
		i = 1;
		p_find = strrchr(str, ' ');
		if(p_find){
			p_find[0] = '_';
			while(p_find[i]!='_')
				printf("%c", p_find[i++]);
			printf(" ");
		}else
			break;
	}
	i = 0;
	while(str[i]!='_')
		printf("%c", str[i++]);

	return 0;
}
