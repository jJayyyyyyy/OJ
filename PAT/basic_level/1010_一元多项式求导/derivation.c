#include <stdio.h>

int main(){
	int coefficient=0, exponent=0;
	int is_start=1;

	while(1){
		scanf("%d%d", &coefficient, &exponent);
		if( exponent!=0 && coefficient!=0){
			// if(  ){
				if( is_start ){
					printf("%d %d", coefficient*exponent, exponent-1);
					is_start = 0;
				}else{
					printf(" %d %d", coefficient*exponent, exponent-1);
				}
			// }
		}else if( exponent==0 && coefficient==0 ){
			// if( coefficient==0 ){
				if( is_start ){
					printf("0 0");
					is_start = 0;
				}else{
					printf(" 0 0");
				}
			// }
		}

		if(getchar()=='\n')
			break;
	}

	if( is_start ){
		printf("0 0");
		printf("hello\n");
		is_start = 0;
	}

	return 0;
}

// scanf("%d%d", &coefficient, &exponent);
// 	if( coefficient==0 && exponent==0)
// 		printf("0 0");
// 	return 0;
// }


	// cnt = i;

	// while(i<=2001){
	// 	// has_input = ;
	// 	if( scanf("%d %d", &coefficient, &exponent)==-1 ){
	// 		break;
	// 	}else{
	// 		if( exponent!=0 ){
				// if(is_start){
				// 	printf("%d %d", coefficient*exponent, exponent-1);
				// 	is_start = 0;
				// }else{
				// 	printf(" %d %d", coefficient*exponent, exponent-1);
				// }
	// 		}else{
	// 			continue;
	// 		}
	// 	}
	// 	i++;
	// }




/*
3 4 -5 2 6 1 -2 0


*/
