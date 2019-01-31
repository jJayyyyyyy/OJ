#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int win, tie, lose;
	int option_wincnt[128];
} Player;

char get_max_option( int option_wincnt[] )
{
	char max_option = 'B';
	int wincnt_B = option_wincnt['B'];
	int wincnt_C = option_wincnt['C'];
	int wincnt_J = option_wincnt['J'];
	int max_wincnt = wincnt_B;
	if( wincnt_C > max_wincnt )
	{
		max_option = 'C';
		max_wincnt = wincnt_C;
	}
	if( wincnt_J > max_wincnt )
	{
		max_option = 'J';
		max_wincnt = wincnt_J;
	}
	return max_option;
}

int main(){
	int n, i;
	char option1, option2, line[8];
	Player p1, p2;
	p1.win = p1.tie = p1.lose = p2.win = p2.tie = p2.lose = 0;
	p1.option_wincnt['B'] = p1.option_wincnt['C'] = p1.option_wincnt['J'] = 0;
	p2.option_wincnt['B'] = p2.option_wincnt['C'] = p2.option_wincnt['J'] = 0;

	scanf("%d", &n);
	fgets(line, 8, stdin);
	for( i = 0; i < n; i++ )
	{
		fgets(line, 8, stdin);
		option1 = line[0];
		option2 = line[2];
		if( option1 == option2 )
		{
			p1.tie++;
			p2.tie++;
		}
		else
		{
			// B > C
			// C > J
			// J > B
			if( option1 == 'B' )
			{
				if( option2 == 'C' )
				{
					p1.win++;
					p1.option_wincnt[option1]++;
					p2.lose++;
				}
				else
				{
					p1.lose++;
					p2.win++;
					p2.option_wincnt[option2]++;
				}
			}

			else if( option1 == 'C' )
			{
				if( option2 == 'J' )
				{
					p1.win++;
					p1.option_wincnt[option1]++;
					p2.lose++;
				}
				else
				{
					p1.lose++;
					p2.win++;
					p2.option_wincnt[option2]++;
				}
			}

			else if( option1 == 'J' )
			{
				if( option2 == 'B' )
				{
					p1.win++;
					p1.option_wincnt[option1]++;
					p2.lose++;
				}
				else
				{
					p1.lose++;
					p2.win++;
					p2.option_wincnt[option2]++;
				}
			}
		}
	}

	printf("%d %d %d\n", p1.win, p1.tie, p1.lose);
	printf("%d %d %d\n", p2.win, p2.tie, p2.lose);
	option1 = get_max_option(p1.option_wincnt);
	option2 = get_max_option(p2.option_wincnt);
	printf("%c %c\n", option1, option2);

	return 0;
}


/*

10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J

*/
