#include <iostream>
#include <algorithm>
#define MAXN 10004
#define MAXVALUE 104
using namespace std;

int w[MAXN] = {0};
int dp[MAXVALUE] = {0};
bool choice[MAXN][MAXN], flag[MAXN];

int cmp(int a, int b){
	return a > b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, i, v;
	cin>>n>>m;
	for( i = 1; i <= n; ++i ){
		cin>>w[i];
	}
	sort(w + 1, w + n + 1, cmp);

	for( i = 1; i <= n; ++i ){
		for( v = m; v >= w[i]; --v ){
			int tmpV = w[i];
			if( dp[v] <= dp[v - tmpV] + tmpV ){
				dp[v] = dp[v - tmpV] + tmpV;
				choice[i][v] = true;
			}else{
				choice[i][v] = false;
			}
		}
	}

	if( dp[m] != m ){
		cout<<"No Solution\n";
	}else{
		int k = n, num = 0, v = m;
		while( k >= 0 ){
			if( choice[k][v] == true ){
				flag[k] = true;
				v -= w[k];
				num++;
			}else{
				flag[k] = false;
			}

			k--;
		}

		for( i = n; i >= 1; --i ){
			if( flag[i] == true ){
				cout<<w[i];
				num--;
				if( num > 0 ){
					cout<<' ';
				}
			}
		}
		cout<<'\n';
	}

	return 0;
}
