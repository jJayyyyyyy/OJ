#include <iostream>
#include <iomanip>
using namespace std;

struct Poly{
	int expo;
	double coef;
};

Poly polyList[1004];
double ansList[2004] = {0.0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, i, j, cnt=0;
	int expo;
	double coef;
	
	cin>>n;
	for( i=0; i<n; i++ ){
		cin>>polyList[i].expo>>polyList[i].coef;
	}

	cin>>m;
	for( i=0; i<m; i++ ){
		cin>>expo>>coef;
		for( j=0; j<n; j++ ){
			ansList[expo + polyList[j].expo] += coef * polyList[j].coef;
		}
	}

	for( i=0; i<=2000; i++ ){
		if( ansList[i] != 0.0 ){
			cnt++;
		}
	}

	cout<<cnt;
	for( i=2000; i>=0; i-- ){
		if( ansList[i] != 0.0 ){
			cout<<' '<<i<<' ';
			cout.setf(ios::fixed);
			cout<<setprecision(1)<<ansList[i];
		}
	}

	return 0;
}