#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int row, col, tLow, tHigh, gp, newGp, ixRow, ixCol, isFirst=1;
	scanf("%d %d %d %d %d", &row, &col, &tLow, &tHigh, &newGp);
	for( ixRow=0; ixRow<row; ixRow++ ){
		for( ixCol=0; ixCol<col; ixCol++ ){
			scanf("%d", &gp);
			if( gp>=tLow && gp<=tHigh ){
				gp = newGp;
			}
			if( isFirst ){
				printf("%03d", gp);
				isFirst = 0;
			}else{
				printf(" %03d", gp);
			}
		}
		isFirst = 1;
		printf("\n");
	}

	return 0;
}