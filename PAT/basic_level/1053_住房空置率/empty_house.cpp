#include <cstdio>
using namespace std;

int main(){
	int n, thDay, i, j;
	double thValue;
	scanf("%d%lf%d", &n, &thValue, &thDay);

	int obDay=0, cntEmpty=0, isEmpty=0, maybeEmpty=0;
	double eValue;

	for( i=0; i<n; i++ ){
		cntEmpty = 0;
		scanf("%d", &obDay);
		for( j=0; j<obDay; j++ ){
			scanf("%lf", &eValue);
			if( eValue<thValue ){
				cntEmpty++;
			}
		}
		if( cntEmpty>obDay/2 ){
			if( obDay>thDay ){
				isEmpty++;
			}else{
				maybeEmpty++;
			}
		}
	}

	printf("%.1f%% %.1f%%\n", maybeEmpty*100.0/n, isEmpty*100.0/n);

	return 0;
}

