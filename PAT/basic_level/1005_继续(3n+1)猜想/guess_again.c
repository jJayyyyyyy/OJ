#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 120

typedef struct
{
	int val;
	int iskey;
}Number;

Number numList[MAXSIZE];

int cmp(const void * a, const void * b)
{
	const Number *a1 = (const Number *)a;
	const Number *b1 = (const Number *)b;
	int ans = a1->val - b1->val;
	if( ans < 0 )
	{
		return 1;
	}
	else if( ans == 0 )
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void doCallatz(int len)
{
	for( int i = 0; i < len; i++ )
	{
		if( numList[i].iskey == 1 )
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
						numList[j].iskey = 0;
					}
				}
			}
		}
	}
}

void printCallatz(int len)
{
	int isFirst = 1;
	for( int i = 0; i < len; i++ )
	{
		if( numList[i].iskey == 1 )
		{
			if( isFirst == 1 )
			{
				printf("%d", numList[i].val);
				isFirst = 0;
			}
			else
			{
				printf(" %d", numList[i].val);
			}
		}
	}
}

int main()
{
	int len, val;
	scanf("%d", &len);
	for( int i = 0; i < len; i++ )
	{
		scanf("%d", &val);
		numList[i].val = val;
		numList[i].iskey = 1;
	}

	qsort(numList, len, sizeof(Number), cmp);
	doCallatz(len);
	printCallatz(len);
	return 0;
}