#include <iostream>
using namespace std;

class Player
{
public:
	int win, tie, lose;
	int option_wincnt[128];
	Player()
	{
		win = tie = lose = 0;
		option_wincnt['B'] = 0;
		option_wincnt['C'] = 0;
		option_wincnt['J'] = 0;
	}

	char get_max_option()
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
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	Player p1, p2;
	char option1, option2;
	for( int i = 0; i < n; i++ )
	{
		cin >> option1 >> option2;

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

	cout<<p1.win<<' '<<p1.tie<<' '<<p1.lose<<'\n';
	cout<<p2.win<<' '<<p2.tie<<' '<<p2.lose<<'\n';
	cout<<p1.get_max_option()<<' '<<p2.get_max_option()<<'\n';

	return 0;
}