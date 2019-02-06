#include <iostream>
#include <algorithm>
#define MAXSIZE 100004
using namespace std;

long long num[MAXSIZE]={0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, i, maxCnt=1, iMin, iMax;;
	long long p, mp;
	cin>>n>>p;

	for( i=0; i<n; i++ ){
		cin>>num[i];
	}
	sort(num, num+n);

	for( iMin=0; iMin<n; iMin++ ){
		mp = num[iMin] * p;
		iMax = upper_bound(num+iMin+1, num+n, mp) - num;
		maxCnt = max( maxCnt, iMax - iMin );
	}

	cout<<maxCnt<<'\n';
	return 0;
}


/*
Solution 2
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int len;
	long long p;
	cin >> len >> p;

	vector<int> numList(len);

	for( int i = 0; i < len; i++ )
	{
		cin>>numList[i];
	}

	sort(numList.begin(), numList.end());
	long long mp;
	int maxGap=1, gap, left=0, right=1;

	for( right = 1; right < len; right++ )
	{
		mp = numList[left] * p;
		if( numList[right] > mp )
		{
			left++;
		}
		else
		{
			gap = right - left + 1;
			maxGap = maxGap > gap ? maxGap : gap;
		}
	}

	cout << maxGap << '\n';
	return 0;
}

*/
