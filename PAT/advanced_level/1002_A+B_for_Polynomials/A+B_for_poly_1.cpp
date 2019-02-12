/*
由于输入是按照指数降序的, 所以我们在读取输入后, 可以直接将两个列表合并, 得到按指数降序的列表
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Polynum {
	int expo;       //指数
	double coef;    //系数
	Polynum(int e, double c)
	{
		expo = e;
		coef = c;
	}
};

vector<Polynum> plist1, plist2, ans;

void merge_two_list(int len1, int len2);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int expo;
	double coef;
	int len1, len2;

	cin >> len1;
	for( int i = 0; i < len1; i++ )
	{
		cin >> expo >> coef;
		plist1.push_back( Polynum(expo, coef) );
	}

	cin >> len2;
	for( int i = 0; i < len2; i++ )
	{
		cin >> expo >> coef;
		plist2.push_back( Polynum(expo, coef) );
	}

	merge_two_list(len1, len2);

	int len = ans.size();
	cout << len;
	for( int i = 0; i < len; i++ )
	{
		Polynum p = ans[i];
		cout << ' ' << p.expo << ' ';
		cout << fixed << setprecision(1) << p.coef;
	}

	cout << '\n';
	return 0;
}

void merge_two_list(int len1, int len2)
{
	int i = 0, j = 0;
	while( i < len1 && j < len2 )
	{
		Polynum p1 = plist1[i];
		Polynum p2 = plist2[j];
		if( p1.expo > p2.expo )
		{
			ans.push_back(p1);
			i++;
		}
		else if( p1.expo < p2.expo )
		{
			ans.push_back(p2);
			j++;
		}
		else
		{
			p1.coef += p2.coef;
			if( p1.coef != 0 )
			{
				ans.push_back(p1);
			}
			i++;
			j++;
		}
	}

	while( i < len1 )
	{
		Polynum p1 = plist1[i++];
		ans.push_back(p1);
	}
	while( j < len2 )
	{
		Polynum p2 = plist2[j++];
		ans.push_back(p2);
	}
}
