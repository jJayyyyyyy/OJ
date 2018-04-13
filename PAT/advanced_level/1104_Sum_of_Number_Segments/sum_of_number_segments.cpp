#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	double sigma = 0.0, num = 0.0;
	int n;
	cin>>n;

	for( int i = 1; i <= n; ++i ){
		cin>>num;
		sigma += num * ( i + (n-i) * i );
	}
	cout.setf(ios::fixed);
	cout<<setprecision(2)<<sigma<<'\n';
	return 0;
}


/*
以下方法比较直观，能拿15分，case 2, case 3会运行超时
左右浮标
#include <iostream>
#include <iomanip>
#include <algorithm>
#define MAXSIZE 100004
using namespace std;

double rawList[MAXSIZE];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	double sum=0;

	int total, left=0, right=0;
	cin>>total;
	for( int i = 0; i < total; i++ ){
		cin>>rawList[i];
	}

	while( left < total ){
		while( right < total ){
			for( int i = left; i <= right; i++ ){
				sum += rawList[i];
			}
			right++;
			if( right == total ){
				left++;
				right = left;
			}
		}
	}

	cout<<fixed<<setprecision(2)<<sum<<'\n';

	return 0;
}

*/