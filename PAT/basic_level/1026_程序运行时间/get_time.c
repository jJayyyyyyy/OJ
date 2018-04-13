#include <stdio.h>
#define CLK_TCK 100

int main(){
	int c1, c2, tick=0, s=0;
	int hour, minute, second;

	scanf("%d%d", &c1, &c2);
	tick = c2 - c1;

	s = (tick + 50)/CLK_TCK;

	hour = s/3600;
	s -= hour*3600;
	minute = s/60;
	s -= minute*60;
	second = s;

	printf("%02d:%02d:%02d\n", hour, minute, second);

	return 0;
}
