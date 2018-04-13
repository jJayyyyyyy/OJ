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
