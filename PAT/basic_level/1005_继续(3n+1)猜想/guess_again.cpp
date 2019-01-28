#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Number
{
	int val;
	bool iskey;
	Number(int v)
	{
		val = v;
		iskey = true;
	}
};

int cmp(Number & a, Number & b)
{
	return a.val > b.val;
}

void doCallatz(vector<Number> & numList, int len)
{
	for( int i = 0; i < len; i++ )
	{
		if( numList[i].iskey == true )
		{
			int val = numList[i].val;
			while( val != 1 )
			{
				if( val % 2 != 0 )
				{
					val = (val * 3 + 1) / 2;
				}
				else
				{
					val /= 2;
				}
				for( int j = 0; j < len; j++ )
				{
					if( numList[j].val == val && j != i )
					{
						numList[j].iskey = false;
					}
				}
			}
		}
	}
}

void printCallatz(vector<Number> & numList, int len)
{
	bool isFirst = true;
	for( int i = 0; i < len; i++ )
	{
		if( numList[i].iskey == true )
		{
			if( isFirst == true )
			{
				cout<<numList[i].val;
				isFirst = false;
			}
			else
			{
				cout<<' '<<numList[i].val;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int len, val;
	vector<Number> numList;
	cin>>len;
	for( int i = 0; i < len; i++ )
	{
		cin>>val;
		numList.push_back(Number(val));
	}

	sort(numList.begin(), numList.end(), cmp);
	doCallatz(numList, len);
	printCallatz(numList, len);
	return 0;
}