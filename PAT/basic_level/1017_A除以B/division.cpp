#include <iostream>
using namespace std;

int main(){
	string us_a, ans_q;
	string::iterator iter;
	int a=0, b=0, q=0, r=0;
	int i=0, j=0;
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>us_a>>b;

	for( iter=us_a.begin(); iter!=us_a.end(); iter++ ){
		a = *iter - '0' + r*10;
		q = a / b;
		r = a % b;
		ans_q.push_back( q + '0');
		j++;
	}

	if( ans_q[0]!='0' || ans_q.size()==1 )
		cout<<ans_q<<' '<<r;
	else
		cout<<&ans_q[1]<<' '<<r;

	return 0;
}
