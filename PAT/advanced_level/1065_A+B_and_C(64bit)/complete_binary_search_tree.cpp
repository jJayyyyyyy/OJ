#include <iostream>
using namespace std;

// 2^63 = 9223372036854775808
// (-2^63) + (-2^63) === 0, in case of long long

int test(){
	long long a, b, c;
	cin>>a>>b;
	c = a + b;
	cout<<c;

	return 0;
}

int main(){
	int n, i;
	long long a, b, c, sum;
	cin>>n;
	for( i=1; i<=n; i++ ){
		cin>>a>>b>>c;
		sum = a + b;
		if( a>0 && b>0 && sum<0 ){
			// sum<0 means overflow
			// a + b > 2^63 >= c
			cout<<"Case #"<<i<<": true\n";
		}else if( a<0 && b<0 && sum>=0 ){
			// sum>=0 means overflow
			// a + b < -2^63 <= c
			cout<<"Case #"<<i<<": false\n";
		}else if( sum > c ){
			cout<<"Case #"<<i<<": true\n";
		}else{
			cout<<"Case #"<<i<<": false\n";
		}
	}

	return 0;
}