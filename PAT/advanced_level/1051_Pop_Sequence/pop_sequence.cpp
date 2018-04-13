#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int seq[1004];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n, k, x, i;

	cin>>m>>n>>k;

	for( x=0; x<k; x++ ){
		for( i=1; i<=n; i++ ){
			cin>>seq[i];
		}
		
		int seqHead=1, isOK=1;
		stack<int> st;

		for( i=1; i<=n; i++ ){
			st.push(i);
			if( st.size()>m ){
				isOK = 0;
				break;
			}else{
				while( !st.empty() && st.top()==seq[seqHead] ){
					st.pop();
					seqHead++;
				}
			}
		}

		if( st.empty() && isOK==1 ){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}

	return 0;
}