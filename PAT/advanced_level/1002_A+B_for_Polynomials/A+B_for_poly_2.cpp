#include <iostream>
#include <iomanip>
#define MAXSIZE 1004
using namespace std;

double plist1[MAXSIZE], plist2[MAXSIZE], ans[MAXSIZE];

int main(){
	double coef;
	int len1=0, len2=0, expo=0, max_expo = 0;

	cin >> len1;
	for( int i = 0; i < len1; i++ )
	{
		cin >> expo;
		if( max_expo < expo)
		{
			max_expo = expo;
		}
		cin >> coef;
		plist1[expo] = coef;
	}

	cin >> len2;
	for( int i = 0; i < len2; i++ )
	{
		cin >> expo;
		if( max_expo < expo )
		{
			max_expo = expo;
		}
		cin >> coef;
		plist2[expo] = coef;
	}

	int len = 0;
	for( expo = 0; expo <= max_expo; expo++ ){
		coef = plist1[expo] + plist2[expo];
		ans[expo] = coef;
		if( coef != 0 )
		{
			len++;
		}
	}

	cout << len;
	for( expo = max_expo; expo >= 0; expo-- ){
		coef = ans[expo];
		if( coef != 0 )
		{
			cout << ' ' << expo << ' ';
			cout << fixed << setprecision(1) << coef;
		}
	}

	return 0;
}
